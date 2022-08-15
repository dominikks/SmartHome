#define ARDUINOJSON_DECODE_UNICODE 1
#include <ArduinoJson.h>

#include <ArduinoOTA.h>
#include <AsyncMqttClient.h>
#include <RingBuf.h>
extern "C" {
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
}
#include "time.h"
#include <WiFi.h>

#include <GxEPD2_3C.h>
#include <GxEPD2_BW.h>

#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>

#include "config/config.h"
#include "icons/icons.h"

AsyncMqttClient mqtt;
TimerHandle_t mqttReconnectTimer;
TimerHandle_t wifiReconnectTimer;

typedef std::function<void()> Task;
RingBuf<Task, 10> taskQueue;

GxEPD2_3C<GxEPD2_420c, GxEPD2_420c::HEIGHT>
    display(GxEPD2_420c(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY));

///////////////////////////////////////////////////////////////////////////////////
// Arduino methods
///////////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200);
  Serial.println("ePaper Status Display");
  delay(1000);

  display.init(115200, true, 2, false);

  mqttReconnectTimer =
      xTimerCreate("mqttTimer", pdMS_TO_TICKS(2000), pdFALSE, (void *)0,
                   reinterpret_cast<TimerCallbackFunction_t>(connectToMqtt));
  wifiReconnectTimer =
      xTimerCreate("wifiTimer", pdMS_TO_TICKS(2000), pdFALSE, (void *)0,
                   reinterpret_cast<TimerCallbackFunction_t>(connectToWifi));

  mqtt.onConnect(onMqttConnect);
  mqtt.onDisconnect(onMqttDisconnect);
  mqtt.onMessage(onMqttMessage);
  mqtt.setServer(mqtt_server, mqtt_port);

  WiFi.onEvent(onWiFiEvent);
  connectToWifi();

  // Init NTP
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  setupOta();
}

void loop() {
  Task task;
  if (taskQueue.lockedPop(task)) {
    task();
  }

  ArduinoOTA.handle();
}

///////////////////////////////////////////////////////////////////////////////////
// Event methods
///////////////////////////////////////////////////////////////////////////////////

void setupOta() {
  ArduinoOTA.setHostname(ota_device_name);
  ArduinoOTA.setPassword(ota_password);
  ArduinoOTA
      .onStart([]() {
        String type;
        if (ArduinoOTA.getCommand() == U_FLASH)
          type = "sketch";
        else // U_SPIFFS
          type = "filesystem";

        // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS
        // using SPIFFS.end()
        Serial.println("Start updating " + type);
      })
      .onEnd([]() { Serial.println("\nEnd"); })
      .onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
      })
      .onError([](ota_error_t error) {
        Serial.printf("Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR)
          Serial.println("Auth Failed");
        else if (error == OTA_BEGIN_ERROR)
          Serial.println("Begin Failed");
        else if (error == OTA_CONNECT_ERROR)
          Serial.println("Connect Failed");
        else if (error == OTA_RECEIVE_ERROR)
          Serial.println("Receive Failed");
        else if (error == OTA_END_ERROR)
          Serial.println("End Failed");
      });
  ArduinoOTA.begin();
}

void connectToWifi() {
  Serial.print("Connecting to WiFi ");
  Serial.print(wifi_ssid);
  Serial.println("...");

  WiFi.begin(wifi_ssid, wifi_pwd);
}

void connectToMqtt() {
  Serial.println("Connecting to MQTT...");

  mqtt.connect();
}

void onWiFiEvent(WiFiEvent_t event) {
  switch (event) {
  case SYSTEM_EVENT_STA_GOT_IP:
    Serial.print("WiFi connected, ");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    connectToMqtt();
    break;
  case SYSTEM_EVENT_STA_DISCONNECTED:
    Serial.println("WiFi lost connection");
    xTimerStop(
        mqttReconnectTimer,
        0); // ensure we don't reconnect to MQTT while reconnecting to Wi-Fi
    xTimerStart(wifiReconnectTimer, 0);
    break;
  }
}

void onMqttConnect(bool sessionPresent) {
  Serial.println("Connected to MQTT.");
  Serial.print("Session present: ");
  Serial.println(sessionPresent);

  mqtt.subscribe(mqtt_topic, 0);
}

void onMqttDisconnect(AsyncMqttClientDisconnectReason reason) {
  Serial.println("Disconnected from MQTT.");

  if (WiFi.isConnected()) {
    xTimerStart(mqttReconnectTimer, 0);
  }
}

void onMqttMessage(char *topic, char *payload,
                   AsyncMqttClientMessageProperties properties, size_t len,
                   size_t index, size_t total) {
  Serial.println(F("MQTT message received"));

  DynamicJsonDocument doc(2048);
  if (deserializeJson(doc, payload, len)) {
    Serial.println(F("Failed to parse JSON"));
  } else {
    taskQueue.push([doc]() { updateDisplay(doc); });
  }
}

///////////////////////////////////////////////////////////////////////////////////
// Display methods
///////////////////////////////////////////////////////////////////////////////////

void updateDisplay(const DynamicJsonDocument &doc) {
  float outdoorTemp = doc["OutdoorTemperature"];
  float outdoorHumidity = doc["OutdoorHumidity"];
  float windSpeed = doc["WindSpeed"];
  float airPressure = doc["AirPressure"];
  int uvIndex = doc["UVIndex"];
  String uvIndexDescription = doc["UVIndexDescription"];
  float ozone = doc["Ozone"];
  bool isRaining = doc["IsRaining"];
  float powerMeter = doc["PowerMeter"];
  float indoorTemp = doc["IndoorTemperature"];
  float indoorHumidity = doc["IndoorHumidity"];
  long sunsetTime = doc["SunsetTime"];
  long sunriseTime = doc["SunriseTime"];
  bool windowsOpen = doc["WindowsOpen"];
  float rainfallToday = doc["RainfallToday"];
  float rainfallYesterday = doc["RainfallYesterday"];
  float co2 = doc["CO2"];
  String sunshineHoursToday = doc["SunshineHoursToday"];
  String sunshineHoursYesterday = doc["SunshineHoursYesterday"];

  struct tm currenttime;
  bool hasTime = getLocalTime(&currenttime);

  display.setTextColor(GxEPD_BLACK);
  display.setFullWindow();
  display.firstPage();

  do {
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
    display.setFont(&FreeMonoBold9pt7b);

    if (hasTime) {
      display.setCursor(0, 11);
      display.println(&currenttime, "%H:%M");
      display.setCursor(150, 11);
      display.println(my_city);
      display.setCursor(290, 11);
      display.println(&currenttime, "%d.%m.%Y");
    }

    drawDashedHLine(0, 20, 420, GxEPD_BLACK);

    display_icon(346, 25, isRaining ? "rain" : "partly_cloudy_day");
    display.setCursor(220, 47);
    display.print("UV: ");
    display.println(uvIndex);
    display.setCursor(220, 62);
    display.println(uvIndexDescription);
    display.setCursor(220, 87);
    display.print("Ozon: ");
    display.println((int)ozone, DEC);
    display.setCursor(220, 112);
    display.println("Niederschlag");
    display.setCursor(220, 127);
    display.print("Heute:   ");
    display.print(rainfallToday, 0);
    display.print("l");
    display.setCursor(220, 142);
    display.print("Gestern: ");
    display.print(rainfallYesterday, 0);
    display.print("l");
    display.setCursor(220, 167);
    display.print("Sonnenschein");
    display.setCursor(220, 182);
    display.print("Heute:   ");
    display.println(sunshineHoursToday);
    display.setCursor(220, 197);
    display.print("Gestern: ");
    display.println(sunshineHoursYesterday);

    display.setFont(&FreeMonoBold12pt7b);    
    dashedRect(0, 25, 210, 125, GxEPD_BLACK);
    display_icon(2, 25, "temperature");
    display.setCursor(50, 47);
    display.print(outdoorTemp, 2);
    display.print(" Grad");
    display.setCursor(50, 67);
    display.print((int)outdoorHumidity, DEC);
    display.println("%");
    display_icon(15, 75, "wind_speed");
    display.setCursor(50, 98);
    display.print((int)windSpeed, DEC);
    display.println(" km/h");

    display_icon(15, 113, "barometer");
    display.setCursor(50, 135);
    display.print((int)airPressure, DEC);
    display.println(" hPa");

    dashedRect(0, 160, 210, 90, GxEPD_BLACK);
    display_icon(2, 160, "temperature");
    display.setCursor(50, 182);
    display.print(indoorTemp, 2);
    display.print(" Grad");
    display.setCursor(50, 202);
    display.print((int)indoorHumidity, DEC);
    display.println("%");
    
    display.setCursor(5, 237);
    display.print("CO");
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(32, 242);
    display.print("2");
    display.setFont(&FreeMonoBold12pt7b);
    display.setCursor(50, 237);
    display.print((int)co2, DEC);
    display.println(" ppm");
    
    display.setFont(&FreeMonoBold9pt7b);    
    display_icon(7, 260, "sunrise_sunset");
    display.setCursor(60, 280);
    struct tm timeinfo; 
    localtime_r(&sunriseTime, &timeinfo);
    display.println(&timeinfo, "%H:%M");
    display.setCursor(60, 294); 
    localtime_r(&sunsetTime, &timeinfo);
    display.println(&timeinfo, "%H:%M");

    display_icon(135, 267, "electricity");
    display.setCursor(170, 287);
    display.print(powerMeter, 2);
    display.println(" kWh");
        
    display.setTextColor(windowsOpen ? GxEPD_RED : GxEPD_BLACK);
    display.setCursor(315, 294);
    display.println("Fenster");
    display.setTextColor(GxEPD_BLACK);    
  } while (display.nextPage());
}

///////////////////////////////////////////////////////////////////////////////////
// Helper methods
///////////////////////////////////////////////////////////////////////////////////

void drawDashedHLine(int16_t x, int16_t y, int16_t w, uint16_t color) {
  display.startWrite();
  writeDashedLine(x, y, x + w - 1, y, color);
  display.endWrite();
}

#ifndef _swap_int16_t
#define _swap_int16_t(a, b)                                                    \
  {                                                                            \
    int16_t t = a;                                                             \
    a = b;                                                                     \
    b = t;                                                                     \
  }
#endif

void writeDashedLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
                     uint16_t color) {
  int16_t steep = abs(y1 - y0) > abs(x1 - x0);
  bool hole = false; // make it dash by using a hole every second pixel
  if (steep) {
    _swap_int16_t(x0, y0);
    _swap_int16_t(x1, y1);
  }

  if (x0 > x1) {
    _swap_int16_t(x0, x1);
    _swap_int16_t(y0, y1);
  }

  int16_t dx, dy;
  dx = x1 - x0;
  dy = abs(y1 - y0);

  int16_t err = dx / 2;
  int16_t ystep;

  if (y0 < y1) {
    ystep = 1;
  } else {
    ystep = -1;
  }

  for (; x0 <= x1; x0++) {
    if (steep) {
      if (!hole)
        display.writePixel(y0, x0, color);
      hole = !hole;
    } else {
      if (!hole)
        display.writePixel(x0, y0, color);
      hole = !hole;
    }
    err -= dy;
    if (err < 0) {
      y0 += ystep;
      err += dx;
    }
  }
}

void dashedRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
  display.startWrite();
  writeDashedLine(x, y, x + w - 1, y, color);
  writeDashedLine(x, y, x, y + h - 1, color);
  writeDashedLine(x + w - 1, y, x + w - 1, y + h - 1, color);
  writeDashedLine(x, y + h - 1, x + w - 1, y + h - 1, color);
  display.endWrite();
}

void display_icon(int x, int y, String icon_name) {
  if (icon_name == "partly_cloudy_day")
    display.drawBitmap(x, y, partly_cloudy_day, 54, 50, GxEPD_BLACK);
  else if (icon_name == "clear_day")
    display.drawBitmap(x, y, clear_day, 54, 50, GxEPD_BLACK);
  else if (icon_name == "rain")
    display.drawBitmap(x, y, rain, 54, 50, GxEPD_BLACK);
  else if (icon_name == "sunrise_sunset")
    display.drawBitmap(x, y, sunrise_sunset, 48, 36, GxEPD_BLACK);
  else if (icon_name == "prob_rain")
    display.drawBitmap(x, y, prob_rain, 54, 50, GxEPD_BLACK);
  else if (icon_name == "temperature")
    display.drawBitmap(x, y, temperature, 54, 50, GxEPD_BLACK);
  else if (icon_name == "pressure")
    display.drawBitmap(x, y, pressure, 69, 64, GxEPD_BLACK);
  else if (icon_name == "moon_0")
    display.drawBitmap(x, y, moon_0_8, 24, 24, GxEPD_BLACK);
  else if (icon_name == "moon_1")
    display.drawBitmap(x, y, moon_2, 24, 24, GxEPD_BLACK);
  else if (icon_name == "moon_2")
    display.drawBitmap(x, y, moon_3, 24, 24, GxEPD_BLACK);
  else if (icon_name == "moon_3")
    display.drawBitmap(x, y, moon_4, 24, 24, GxEPD_BLACK);
  else if (icon_name == "moon_4")
    display.drawBitmap(x, y, moon_5, 24, 24, GxEPD_BLACK);
  else if (icon_name == "moon_5")
    display.drawBitmap(x, y, moon_6, 24, 24, GxEPD_BLACK);
  else if (icon_name == "moon_6")
    display.drawBitmap(x, y, moon_7, 24, 24, GxEPD_BLACK);
  else if (icon_name == "moon_7")
    display.drawBitmap(x, y, moon_8, 24, 24, GxEPD_BLACK);
  else if (icon_name == "moon_8")
    display.drawBitmap(x, y, moon_0_8, 24, 24, GxEPD_BLACK);
  else if (icon_name == "barometer")
    display.drawBitmap(x, y, barometer, 30, 30, GxEPD_BLACK);
  else if (icon_name == "wind_speed")
    display.drawBitmap(x, y, wind_speed, 30, 30, GxEPD_BLACK);
  else if (icon_name == "light_on")
    display.drawBitmap(x, y, light_on, 50, 50, GxEPD_BLACK);
  else if (icon_name == "light_off")
    display.drawBitmap(x, y, light_off, 50, 50, GxEPD_BLACK);
  else if (icon_name == "gate_open")
    display.drawBitmap(x, y, gate_open, 50, 50, GxEPD_BLACK);
  else if (icon_name == "gate_closed")
    display.drawBitmap(x, y, gate_closed, 47, 50, GxEPD_BLACK);
  else if (icon_name == "electricity")
    display.drawBitmap(x, y, electricity, 30, 30, GxEPD_BLACK);
}

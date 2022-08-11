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

// ePaper Pins
#define EPD_CS 23
#define EPD_DC 18
#define EPD_RST 5
#define EPD_BUSY 17

GxEPD2_3C<GxEPD2_420c, GxEPD2_420c::HEIGHT>
    display(GxEPD2_420c(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY));

///////////////////////////////////////////////////////////////////////////////////
// Arduino methods
///////////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200);
  Serial.println("ePaper Status Display");
  delay(1000);

  display.init(115200);

  mqttReconnectTimer =
      xTimerCreate("mqttTimer", pdMS_TO_TICKS(2000), pdFALSE, (void *)0,
                   reinterpret_cast<TimerCallbackFunction_t>(connectToMqtt));
  wifiReconnectTimer =
      xTimerCreate("wifiTimer", pdMS_TO_TICKS(2000), pdFALSE, (void *)0,
                   reinterpret_cast<TimerCallbackFunction_t>(connectToWifi));

  WiFi.onEvent(onWiFiEvent);

  mqtt.onConnect(onMqttConnect);
  mqtt.onDisconnect(onMqttDisconnect);
  mqtt.onMessage(onMqttMessage);
  mqtt.setServer(mqtt_server, mqtt_port);

  ArduinoOTA.setHostname("epaper-status-display");
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

  connectToWifi();

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
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

void connectToWifi() {
  Serial.print("Connecting to WiFi ");
  Serial.print(wifi_ssid);
  Serial.println("...");

  taskQueue.push([]() {
    display.setFont(&FreeMonoBold12pt7b);
    display.setTextColor(GxEPD_BLACK);
    display.setFullWindow();
    display.firstPage();

    do {
      display.fillScreen(GxEPD_WHITE);
      display.setCursor(0, 100);
      display.println("Verbinde mit WiFi...");
    } while (display.nextPage());
  });

  WiFi.begin(wifi_ssid, wifi_pwd);
}

void connectToMqtt() {
  Serial.println("Connecting to MQTT...");

  taskQueue.push([]() {
    display.setFont(&FreeMonoBold12pt7b);
    display.setTextColor(GxEPD_BLACK);
    display.setFullWindow();
    display.firstPage();

    do {
      display.fillScreen(GxEPD_WHITE);
      display.setCursor(0, 100);
      display.println("Verbinde mit MQTT...");
    } while (display.nextPage());
  });

  mqtt.connect();
}

void onWiFiEvent(WiFiEvent_t event) {
  Serial.printf("[WiFi-event] event: %d\n", event);
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
  }

  updateDisplay(doc);
}

///////////////////////////////////////////////////////////////////////////////////
// Display methods
///////////////////////////////////////////////////////////////////////////////////

void updateDisplay(DynamicJsonDocument doc) {
  float outdoorTemp = doc["OutdoorTemp"];
  float outdoorHumidity = doc["OutdoorHumidity"];
  float windSpeed = doc["WindSpeed"];
  float airPressure = doc["AirPressure"];
  int uvIndex = doc["UVIndex"];
  const char *uvIndexDescription = doc["UVIndexDescription"];
  float ozone = doc["Ozone"];
  bool isRaining = doc["IsRaining"];

  struct tm timeinfo;
  bool hasTime = getLocalTime(&timeinfo);

  display.setTextColor(GxEPD_BLACK);
  display.setFullWindow();
  display.firstPage();

  do {
    display.fillScreen(GxEPD_WHITE);
    display.setFont(&FreeMonoBold9pt7b);

    if (hasTime) {
      display.setCursor(0, 11);
      display.println(&timeinfo, "%H:%M:%S");
      display.setCursor(150, 11);
      display.println(my_city);
      display.setCursor(290, 11);
      display.println(&timeinfo, "%d.%m.%Y");
    }

    drawDashedHLine(0, 20, 420, GxEPD_BLACK);

    display.setCursor(270, 100);
    display.println("UV: " + uvIndex);
    display.setCursor(270, 115);
    display.println(uvIndexDescription);
    display.setCursor(270, 140);
    display.print("Ozon: ");
    display.println((int)ozone, DEC);

    display.setFont(&FreeMonoBold12pt7b);
    dashedRect(0, 25, 260, 125, GxEPD_BLACK);
    display_icon(2, 25, "temperature");
    display.setCursor(50, 47);
    display.print(outdoorTemp);
    display.print(" Grad");
    display.setCursor(50, 67);
    display.print(outdoorHumidity * 100, 0);
    display.println("%");
    display_icon(2, 65, "wind_speed");
    display.setCursor(50, 98);
    display.print((int)windSpeed, DEC);
    display.println("km/h");

    display_icon(15, 113, "barometer");
    display.setCursor(50, 135);
    display.print((int)airPressure, DEC);
    display.println("hPa");
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
  int scale = 10; // Adjust size as necessary
  if (icon_name == "partly-cloudy-day")
    display.drawBitmap(x, y, partly_cloudy_day, 54, 50, GxEPD_BLACK);
  else if (icon_name == "clear-day")
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
}
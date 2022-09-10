#include <ArduinoOTA.h>
#include <AsyncMqttClient.h>
#include <WiFi.h>
#include <bsec.h>

#include "config/config.h"

AsyncMqttClient mqtt;
TimerHandle_t mqttReconnectTimer;
TimerHandle_t wifiReconnectTimer;

Bsec iaqSensor;

String will_topic = String(mqtt_topic) + "/connected";

///////////////////////////////////////////////////////////////////////////////////
// Arduino methods
///////////////////////////////////////////////////////////////////////////////////

void setup(void) {
  Serial.begin(115200);

  Wire.begin(SDA_PIN, SCL_PIN);
  iaqSensor.begin(BME680_I2C_ADDR_SECONDARY, Wire);
  checkIaqSensorStatus();

  bsec_virtual_sensor_t sensorList[10] = {
      BSEC_OUTPUT_RAW_TEMPERATURE,
      BSEC_OUTPUT_RAW_PRESSURE,
      BSEC_OUTPUT_RAW_HUMIDITY,
      BSEC_OUTPUT_RAW_GAS,
      BSEC_OUTPUT_IAQ,
      BSEC_OUTPUT_STATIC_IAQ,
      BSEC_OUTPUT_CO2_EQUIVALENT,
      BSEC_OUTPUT_BREATH_VOC_EQUIVALENT,
      BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_TEMPERATURE,
      BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_HUMIDITY,
  };

  // Sample rate: 300s
  iaqSensor.updateSubscription(sensorList, 10, BSEC_SAMPLE_RATE_ULP);
  checkIaqSensorStatus();

  // Initialize networking
  mqttReconnectTimer =
      xTimerCreate("mqttTimer", pdMS_TO_TICKS(2000), pdFALSE, (void *)0,
                   reinterpret_cast<TimerCallbackFunction_t>(connectToMqtt));
  wifiReconnectTimer =
      xTimerCreate("wifiTimer", pdMS_TO_TICKS(2000), pdFALSE, (void *)0,
                   reinterpret_cast<TimerCallbackFunction_t>(connectToWifi));

  WiFi.onEvent(onWiFiEvent);

  mqtt.onConnect(onMqttConnect);
  mqtt.onDisconnect(onMqttDisconnect);
  mqtt.setServer(mqtt_server, mqtt_port);
  mqtt.setWill(will_topic.c_str(), 0, false, "false");

  connectToWifi();

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

// Function that is looped forever
void loop(void) {
  if (iaqSensor.run()) {
    // If new data is available, send everything
    sendMqtt("rawTemperature", String(iaqSensor.rawTemperature));
    sendMqtt("rawHumidity", String(iaqSensor.rawHumidity));
    sendMqtt("pressure", String(iaqSensor.pressure));
    sendMqtt("gasResistance", String(iaqSensor.gasResistance));
    sendMqtt("iaq", String(iaqSensor.iaq));
    sendMqtt("iaqAccuracy", String(iaqSensor.iaqAccuracy));
    sendMqtt("temperature", String(iaqSensor.temperature));
    sendMqtt("humidity", String(iaqSensor.humidity));
    sendMqtt("staticIaq", String(iaqSensor.staticIaq));
    sendMqtt("staticIaqAccuracy", String(iaqSensor.staticIaqAccuracy));
    sendMqtt("co2Equivalent", String(iaqSensor.co2Equivalent));
    sendMqtt("co2Accuracy", String(iaqSensor.co2Accuracy));
    sendMqtt("breathVocEquivalent", String(iaqSensor.breathVocEquivalent));
    sendMqtt("breathVocAccuracy", String(iaqSensor.breathVocAccuracy));
    sendMqtt("gasPercentage", String(iaqSensor.gasPercentage));
    sendMqtt("gasPercentageAccuracy", String(iaqSensor.gasPercentageAcccuracy));
    sendMqtt("compGasValue", String(iaqSensor.compGasValue));
    sendMqtt("compGasAccuracy", String(iaqSensor.compGasAccuracy));
    sendMqtt("gasResistance", String(iaqSensor.gasResistance));
    Serial.println("Sent new data via MQTT");
  } else {
    checkIaqSensorStatus();
  }
}

///////////////////////////////////////////////////////////////////////////////////
// Event methods
///////////////////////////////////////////////////////////////////////////////////

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

  sendMqtt("connected", "true");
}

void onMqttDisconnect(AsyncMqttClientDisconnectReason reason) {
  Serial.print("Disconnected from MQTT: ");
  Serial.println((int)reason);

  if (WiFi.isConnected()) {
    xTimerStart(mqttReconnectTimer, 0);
  }
}

void sendMqtt(const char *topic_suffix, String payload) {
  String topic = String(mqtt_topic) + "/" + String(topic_suffix);
  if (mqtt.connected()) {
    Serial.print("MQTT Publish [");
    Serial.print(topic);
    Serial.print("]: ");
    Serial.println(payload);

    mqtt.publish(topic.c_str(), 0, false, payload.c_str());
  }
}

///////////////////////////////////////////////////////////////////////////////////
// Sensor helper methods
///////////////////////////////////////////////////////////////////////////////////

void checkIaqSensorStatus() {
  if (iaqSensor.status != BSEC_OK) {
    if (iaqSensor.status < BSEC_OK) {
      String output = "BSEC error code: " + String(iaqSensor.status);
      Serial.println(output);
      sendMqtt("error", output);

      // Halt in case of failure
      for (;;)
        errLeds();
    } else {
      String output = "BSEC warning code: " + String(iaqSensor.status);
      Serial.println(output);
      sendMqtt("warning", output);
    }
  }

  if (iaqSensor.bme680Status != BME680_OK) {
    if (iaqSensor.bme680Status < BME680_OK) {
      String output = "BME680 error code: " + String(iaqSensor.bme680Status);
      Serial.println(output);
      sendMqtt("error", output);

      // Halt in case of failure
      for (;;)
        errLeds();
    } else {
      String output = "BME680 warning code: " + String(iaqSensor.bme680Status);
      Serial.println(output);
      sendMqtt("warning", output);
    }
  }
}

void errLeds() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN, LOW);
  delay(100);
}

#pragma once

///////////////////////////////////////////////////////////////////////////////////////
// UPDATE THOSE VALUES FOR YOUR ENVIRONMENT
///////////////////////////////////////////////////////////////////////////////////////
const char *wifi_ssid = "";
const char *wifi_pwd = "";

const char *mqtt_server = "";
const uint16_t mqtt_port = 1883;
const char *mqtt_topic = "";

// Password to update the software via WiFi
const char *ota_password = "";
const char *ota_device_name = "esp32-device";

#define LED_PIN 9
#define SDA_PIN 25
#define SCL_PIN 12
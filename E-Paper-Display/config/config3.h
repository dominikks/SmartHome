///////////////////////////////////////////////////////////////////////////////////////
// UPDATE THOSE VALUES FOR YOUR ENVIRONMENT
///////////////////////////////////////////////////////////////////////////////////////
const char *wifi_ssid = "iot@kdtk.de";
const char *wifi_pwd = "KDOzHvOymVJkh6CFCgirUskAsIqgsDetqKUmoj0CWuS7eHggPTTXEGFd";

const char *mqtt_server = "ap01.intern.kdtk.de";
const uint16_t mqtt_port = 1883;
const char *mqtt_topic = "epaper/3";

// Password to update the software via WiFi
const char *ota_password = "hdgb7i56htdjk4";
const char *ota_device_name = "esp32-device-epaper2";

// Time is retrieved via NTP
const char *ntpServer = "192.168.19.254";
const long gmtOffset_sec = 3600;
const int daylightOffset_sec = 3600;

// The city is displayed at the top of the epaper
const char *my_city = "Neviges";

// ePaper Pins
#define EPD_CS 0
#define EPD_DC 2
#define EPD_RST 15
#define EPD_BUSY 13
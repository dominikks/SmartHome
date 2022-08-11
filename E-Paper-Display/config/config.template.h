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

// Time is retrieved via NTP
const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 3600;
const int daylightOffset_sec = 3600;

// The city is displayed at the top of the epaper
const char *my_city = "";

// ePaper Pins
#define EPD_CS 23
#define EPD_DC 18
#define EPD_RST 5
#define EPD_BUSY 17
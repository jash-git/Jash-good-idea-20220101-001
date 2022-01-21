#include <WiFi.h>
 
const char* wifi_network_ssid = "yourNetworkName";
const char* wifi_network_password =  "yourNetworkPassword";
 
const char *soft_ap_ssid = "MyESP32AP";
const char *soft_ap_password = "testpassword";
 
void OnWiFiEvent(WiFiEvent_t event)
{
  switch (event) {
 
    case SYSTEM_EVENT_STA_CONNECTED:
      Serial.println("ESP32 Connected to WiFi Network");
      break;
    case SYSTEM_EVENT_AP_START:
      Serial.println("ESP32 soft AP started");
      break;
    case SYSTEM_EVENT_AP_STACONNECTED:
      Serial.println("Station connected to ESP32 soft AP");
      break;
    case SYSTEM_EVENT_AP_STADISCONNECTED:
      Serial.println("Station disconnected from ESP32 soft AP");
      break;
    default: break;
  }
}
 
 
void setup() {
 
  Serial.begin(115200);
  WiFi.onEvent(OnWiFiEvent);
 
  WiFi.mode(WIFI_MODE_APSTA);
 
  WiFi.softAP(soft_ap_ssid, soft_ap_password);
  WiFi.begin(wifi_network_ssid, wifi_network_password);
}
 
void loop() {}
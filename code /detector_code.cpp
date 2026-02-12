#include <ESP8266WiFi.h>

extern "C" {
  #include "user_interface.h"
}

#define LED_PIN 2  // D4 (Built-in LED, Active LOW)

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

volatile bool attackDetected = false;

/* Promiscuous Mode Callback */
void ICACHE_FLASH_ATTR sniffer_callback(uint8_t *buf, uint16_t len) {

  if (len == 12) return;  // Ignore control frames

  wifi_promiscuous_pkt_t *pkt = (wifi_promiscuous_pkt_t*)buf;
  uint8_t *payload = pkt->payload;

  uint8_t frameControl = payload[0];

  // Check for Deauthentication frame (0xC0)
  if (frameControl == 0xC0) {
    attackDetected = true;
    Serial.println("[⚠️] Deauth packet detected!");
  }
}

void setup() {

  Serial.begin(115200);
  delay(1000);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);  // LED OFF (Active LOW)

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println("\nConnecting to WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n[WiFi] Connected!");
  Serial.print("[WiFi] IP Address: ");
  Serial.println(WiFi.localIP());

  // Enable Promiscuous Mode
  wifi_set_opmode(STATION_MODE);
  wifi_promiscuous_enable(0);
  wifi_set_promiscuous_rx_cb(sniffer_callback);
  wifi_promiscuous_enable(1);

  Serial.println("[Monitor] Promiscuous mode ON.");
}

void loop() {

  if (attackDetected) {

    // LED ON (Active LOW)
    digitalWrite(LED_PIN, LOW);
    delay(2000);

    // LED OFF
    digitalWrite(LED_PIN, HIGH);
    delay(5000);

    attackDetected = false;  // Reset after alert
  }
}

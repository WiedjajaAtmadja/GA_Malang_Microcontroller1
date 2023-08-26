#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6BzPTgS8O"
#define BLYNK_TEMPLATE_NAME "ESP32Semarang"
#define BLYNK_AUTH_TOKEN "-flYKuerTVg2hN_froOyTc19XUxsHa6A"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Arduino.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SteffN9";
char pass[] = "steff123";

#define LED_RED 15
#define LED_GREEN 4
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, 
  "blynk.cloud", 8080);
}

void loop() {
  Blynk.run();
}

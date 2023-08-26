#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6BzPTgS8O"
#define BLYNK_TEMPLATE_NAME "ESP32Semarang"
#define BLYNK_AUTH_TOKEN "-flYKuerTVg2hN_froOyTc19XUxsHa6A"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Arduino.h>
#include <DHTesp.h>


// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SteffN9";
char pass[] = "steff123";
DHTesp dht;

#define LED_RED 15
#define LED_GREEN 4
#define DHT_PIN 5
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  dht.setup(DHT_PIN, DHTesp::DHT11);
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, 
  "blynk.cloud", 8080);
}

int nPrevTime = 0;
void loop() {
  int current = millis();
  if ((current-nPrevTime)>5000)
  {
    nPrevTime = current;
    float fHumidity = dht.getHumidity();
    float fTemperature = dht.getTemperature();
    Blynk.virtualWrite(V0, fHumidity);
    Blynk.virtualWrite(V1, fTemperature);
      Serial.printf("Humidity: %.2f, Temperature: %.2f\n",
      fHumidity, fTemperature);
  }
  Blynk.run();
}

BLYNK_WRITE(V3)
{
 int value = param.asInt();
 digitalWrite(LED_RED, value);
// Blynk.virtualWrite(V3, value);
}

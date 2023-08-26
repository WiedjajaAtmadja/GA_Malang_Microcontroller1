#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(4, OUTPUT);

}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(4, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(15, LOW);
  digitalWrite(4, HIGH);
  delay(1000);
}

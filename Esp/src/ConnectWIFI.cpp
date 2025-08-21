// #define COMPILE
#ifdef COMPILE

#include <Arduino.h>
#include <WiFi.h>

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_AP);
    delay(10);
    WiFi.softAP("O mais gato");
}

void loop() {

}

#endif


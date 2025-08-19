#include <Arduino.h>
#include <ArduinoJson.h>

const int LED_ONB = 13;

JsonDocument doc;


//{"led_state":true}

// #define COMPILE
#ifdef COMPILE
void led_blinkin(int pin, uint8_t power){
  digitalWrite(pin, power);
  delay(200);
  // digitalWrite(pin, power);
  // delay(200);
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_ONB, OUTPUT);

  doc["led_state"]=true;
  String output;
  doc.shrinkToFit();
  serializeJson(doc, output);
  Serial.begin(9600);
  Serial.println(output);


}

void loop() {
uint8_t power = HIGH;

  led_blinkin(LED_ONB, power);

  if (Serial.available() > 0)
  {
    String msg = Serial.readStringUntil('\n');
    deserializeJson(doc, msg);

    bool led_state = doc["led_state"];

    if (led_state == true){
      power = HIGH;
    }
    else if (led_state == false)
    {
      power = LOW;
    }
    
    led_blinkin(LED_ONB, power);
  }
}
#endif
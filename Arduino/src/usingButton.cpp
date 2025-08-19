#include <Arduino.h>
#include <ArduinoJson.h>

const int LED_ONB = 13;
const int PIN_BUTTON = 3;
const int PIN_LED = 5;
const int serial_speed = 9600;

volatile bool led_state = false;
int count = 0;

// #define COMPILE
#ifdef COMPILE

void led_blinkin(int pin){
  digitalWrite(pin, HIGH);
  delay(200);
  digitalWrite(pin, LOW);
  delay(200);
}

void interrupt_function(){
    led_state = !led_state;
    count++;
}

void setup() {

    Serial.begin(serial_speed);
    pinMode(PIN_BUTTON, INPUT_PULLUP);
    pinMode(PIN_LED, OUTPUT);
    pinMode(LED_ONB, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(PIN_BUTTON),interrupt_function, FALLING);

}

void loop() {

    if(led_state == false){
        led_blinkin(PIN_LED);
    }else{
        digitalWrite(PIN_LED, LOW);
        led_blinkin(LED_ONB);
    }

    if(count > 2){
        count = 0;
    }

    Serial.println(count);
}


#endif
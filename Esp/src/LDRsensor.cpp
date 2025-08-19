#include <Arduino.h>
#include <pwmwrite.h>

const int monitor_speed = 115200;
const int LDR_PIN = 4;
const int LED_PIN = 26;

Pwm pwm = Pwm();


// #define COMPILE
#ifdef COMPILE

float tension(int leitura){
    return map(leitura, 0, 4095, 0, 33) / 10.0;
}

void setup(){
    pinMode(LDR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(monitor_speed);
}

void loop(){
    int leitura = analogRead(LDR_PIN);

    int brightness = map(leitura, 0, 4095, 0, 255);
    
    Serial.print( "A tensão é: ");
    Serial.print(tension(leitura));
    Serial.println("V");

    pwm.write(LED_PIN, brightness);
    
    delay(100);
}
#endif
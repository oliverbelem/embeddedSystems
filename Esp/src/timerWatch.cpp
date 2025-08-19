#include <Arduino.h>

// #define COMPILE
#ifdef COMPILE
void setup(){

    pinMode(2, OUTPUT);
    Serial.begin(115200);
    Serial.println("Piscando Led...");
    esp_sleep_wakeup_cause_t reason = esp_sleep_get_wakeup_cause();
    int i = 0;
    int timing;

    if (reason == ESP_SLEEP_WAKEUP_TIMER){
        Serial.println("Acordou pelo timer...");
        timing = 10;
    }else{
        Serial.println("Acordou por outro motivo...");
        timing = 5;
    }

    do{
        digitalWrite(2, HIGH);
        delay(200);
        digitalWrite(2, LOW);
        delay(200);
        i++;
    }while (i < timing);

    esp_deep_sleep(10* 1000000);
}

void loop(){

}
#endif
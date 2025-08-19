#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0X27, 16, 2);
const int LED_BUILTIN = 2;
int count = 0;

#define I2C_SDA 21
#define I2C_SCL 22

// #define COMPILE
#ifdef COMPILE

void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    lcd.init(I2C_SDA, I2C_SCL);
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0, 0);
    Serial.println("ESP inicializando");
}

void loop(){

    if(Serial.available() > 0){
        String msg = Serial.readStringUntil('\n');
        msg.trim();
        msg = msg.substring(0, 16);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(msg);
    }

    // if ( count > 12 ){
    //     count = 0;
    //     lcd.clear();
    // }

    // lcd.print(count);
    // count++;
    // delay(1000);
}

#endif
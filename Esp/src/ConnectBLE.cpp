
// #define COMPILE
#ifdef COMPILE

#include <Arduino.h>
#include <BleSerial.h>

BleSerial ble;
String msg = "off";
const int LED_BLT = 2;


void bleConnectCallback(bool connected){
    if(connected){
        Serial.println("Connected!");
    }
    else{
        Serial.println("Disconnected!");
    }
}

void led_blink(int pin) {
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW);
    delay(500);
}

void setup() {
    //Start Serial
    Serial.begin(115200);
    pinMode(LED_BLT, OUTPUT);
	//Start the BLE Serial
	//Enter the Bluetooth name here
	ble.begin("O mais lindo(disse mamãe)");

    //Set Callback
    ble.setConnectCallback(bleConnectCallback);

}

void loop() {

	if(ble.available() > 0){
        msg = ble.readStringUntil('\n');
        Serial.println(msg);
    }

    if (msg == "on") {
        digitalWrite(LED_BLT, HIGH);
    }else if(msg == "off"){
        digitalWrite(LED_BLT, LOW);
    }else if(msg="blink"){
        led_blink(LED_BLT);
    }
    

	delay(10);
}
#endif


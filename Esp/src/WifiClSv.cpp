// #define COMPILE
#ifdef COMPILE

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>

const unsigned long timeout = 30 * 1000;

WiFiClient cl;
WiFiServer sv(3000);

bool connectWiFi( unsigned long timeout){
    WiFi.mode(WIFI_OFF);
    delay(10);

    WiFi.mode(WIFI_STA);
    WiFi.begin("FPF-2Ghz", "10203040");
    Serial.println("Trying to connect on WiFi...");

    unsigned long current_time = millis();

    while (WiFi.status() != WL_CONNECTED)  {
        Serial.print(".");
        delay(100);

        if (millis() - current_time >= timeout){
            return false;
        }
    
    }

    Serial.println("\nConnected on WiFi...");
    Serial.println(WiFi.localIP());

    return true;
}

void tcp(){
    if(cl.connected()){
        if(cl.available() > 0){
            String received_msg = "";
            
            while (cl.available() > 0){
                received_msg += cl.read();
            }
            Serial.println(received_msg);
            
        }else {
            cl = sv.available();
            delay(1);
        }
    }
}

void setup() {
    Serial.begin(115200);
    connectWiFi(timeout);
    sv.begin();
}

void loop() {

    if(WiFi.status() != WL_CONNECTED){
        connectWiFi(timeout);
    }

    tcp();
}

#endif


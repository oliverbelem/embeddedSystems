// #define COMPILE
#ifdef COMPILE

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <HTTPClient.h>

String url = "https://api.adviceslip.com/advice";

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

void setup() {
    Serial.begin(115200);
    connectWiFi(30 * 1000);
}

void loop() {
    HTTPClient http;

    http.begin(url);
    int code = http.GET();
    
    Serial.println(code);
    if(code == 200){
        Serial.println(http.getString());
    }
    
    delay(10 * 1000);
}

#endif


#ifndef WIFI_FUNCTIONS_H
#define WIFI_FUNCTIONS_H
#include "global.h"
#include "WiFi.h"
#include "WiFiClient.h"
#include "config.h"
#include "displayFunctions.h"


WiFiClient wifi_client;

namespace wifi{

    void connect() {
        sprintf(DISPLAY_BUFFER, "Conectando-se a\na rede\nWi-FI\nAGUARDE!\nSSID:\n%sSENHA:\n%s",WIFI_SSID,WIFI_PASSWORD);
        display::print(DISPLAY_BUFFER);
        unsigned long tempoInicial = millis();
        while (WiFi.status() != WL_CONNECTED && (millis() - tempoInicial < WIFI_TIMEOUT)) {
            delay(100);
        }
        if (WiFi.status() != WL_CONNECTED) {
            display::print("Falha ao\ntentar se\nconectar\nao WiFi");
            delay(5000);
        } else {
            
            sprintf(DISPLAY_BUFFER,"Conectado com o IP:\n%s", WiFi.localIP().toString().c_str());
            display::print(DISPLAY_BUFFER);
            delay(5000);
        
        }
    }

    void init(){
        WiFi.mode(WIFI_STA); 
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
        connect();
    }
}
#endif

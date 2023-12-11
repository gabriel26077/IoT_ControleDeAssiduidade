#ifndef MQTT_FUNCTIONS_H
#define MQTT_FUNCTIONS_H

#include "PubSubClient.h"
#include "wifiFunctions.h"
#include "global.h"
#include "config.h"

PubSubClient mqtt_client(wifi_client);

namespace mqtt {
  void init(){
    mqtt_client.setServer(MQTT_BROKER, MQTT_PORT);
  }

  void connect() {
    unsigned long tempoInicial = millis();
    while (!mqtt_client.connected() && (millis() - tempoInicial < MQTT_TIMEOUT)) {
      if (WiFi.status() != WL_CONNECTED) {
        wifi::connect();
      }
      Serial.println("<system> Conectando ao MQTT Broker...");
  
      if (mqtt_client.connect("ESP32Client", MQTT_USERNAME_ADAFRUIT_IO, MQTT_KEY_ADAFRUIT_IO)) {
        Serial.println("<system> Conectado ao broker MQTT!");
      } else {

        Serial.println("<system>  Conexão com o broker MQTT falhou!\n");
        delay(500);
      }
    }
    
  }

  void reconnect(){
    if (!mqtt_client.connected()) { 
      connect();
    }
  }

  bool publish(String& feed, String data){
    if (mqtt_client.connected()) {
        
        sprintf(BUFFER,"%s%s",FEEDS_PATH, feed);
        
        mqtt_client.publish(BUFFER, String(data).c_str());
        
 
        Serial.printf( "<system>  Publicou o dado:\n\tNome: %s\n", String(data));
 
        mqtt_client.loop();
        return true;
    }
    
    Serial.println("<system>  Nao foi possivel publicar o dado, pois o broker mqtt esta desconectado");
    return false;
  }
}
#endif

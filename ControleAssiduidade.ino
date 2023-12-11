#include "global.h"
#include "config.h"
#include <FS.h>
#include "SPIFFS.h"
#include <Keypad.h>
#include "WiFi.h"
#include "WiFiClient.h"
#include "wifiFunctions.h"
#include "PubSubClient.h"
#include "mqttFunctions.h"
#include "runHomeMenu.h"
#include "runUpdateByCard.h"
#include "runUpdateByCode.h"
#include "runGenerateReport.h"
#include "runSendReport.h"
#include "KeyPadFunctions.h"
#include "displayFunctions.h"
#include "databaseFunctions.h"

String nome = "adsas";


void setup(){
  
  SPIFFS.begin(true);
  
  Serial.begin(9600);
  
  display::init();
 
  display::print("Sistema\nde Assiduidade\nde bolsistas\nIoT Unidade 2\nJoao Pedro\nGabriel Neto");
  delay(5000);
  
  wifi::init();
  mqtt::init();
}
  
void loop(){
  char op = runHomeMenu();
  sprintf(BUFFER, "Opcao escolhida no menu: %c", op);
  Serial.println(BUFFER);
  switch(op){
    case '1':
      runUpdateByCode();
    break;
    case '2':
      runUpdateByCard();
    break;
    case '3':
      runGenerateReport();
      runSendReport();
    break;
    default:
      showInvalidOptionAlert();
      delay(2000);
    
  }

  
}




void showInvalidOptionAlert(){
    display::print("ERRO\ndigite uma\nopcao valida!");
}

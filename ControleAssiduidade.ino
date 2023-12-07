#include <FS.h>
#include "SPIFFS.h"
#include "FSFunctions.h"
#include <Keypad.h>

#include "runHomeMenu.h"
#include "runUpdateByCard.h"
#include "runUpdateByCode.h"
#include "runGenerateReport.h"
#include "runSendReport.h"
#include "KeyPadFunctions.h"

String buffer_file_bolsistas;
char buffer_de_teclado[10];
byte size_b_t = 0;

void setup(){
  Serial.begin(9600);
  delay(5000);
  Serial.println("iniciando processos...");
  //buffer_file_bolsistas = readFile("/dados/bolsistas.txt");
}
  
void loop(){

  char op = runHomeMenu();

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
  
  delay(1000);

}



void showInvalidOptionAlert(){
    Serial.println("Erro, digite uma opcao valida!");
}

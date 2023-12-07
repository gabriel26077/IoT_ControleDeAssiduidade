#ifndef RUN_HOME_MENU_H
#define RUN_HOME_MENU_H

#include "KeyPadFunctions.h"



char runHomeMenu(){
  Serial.println("Seleciona a opção");
  Serial.println("1 - update/codigo");
  Serial.println("2 - update/cartao");
  Serial.println("3 - gerar relatorio");

  char ans = listen_keypad();
  
  Serial.print("Selecionado: ");
  
  Serial.println(ans);
  
  for(int i=0; i<3;i++){
    Serial.print(".");
    delay(500);
  }
  Serial.print("\n");
  Serial.println("////////////////");
  return ans;
}


#endif

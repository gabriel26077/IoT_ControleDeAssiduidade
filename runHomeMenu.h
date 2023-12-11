#ifndef RUN_HOME_MENU_H
#define RUN_HOME_MENU_H

#include "KeyPadFunctions.h"
#include "displayFunctions.h"
#include "mqttFunctions.h"

char runHomeMenu(){

  String content = "Selecione uma opcao\n\n1 - update/codigoa\n\n2 - update/cartao\n\n3 - gerar relatorio\n";

  display::print(content);
  
  char ans = listen_keypad();
 
  return ans;
}


#endif

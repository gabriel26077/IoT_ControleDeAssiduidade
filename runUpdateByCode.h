#ifndef RUN_UPDATE_BY_CODE_H
#define RUN_UPDATE_BY_CODE_H

#include "KeyPadFunctions.h"

void printchar(char p){
  Serial.print(p);
}

void runUpdateByCode() {
  Serial.println("Aguardando o usuário digitar o codigo");

  String codigo = read_string(/*Max Length*/10,/*end indicator*/'#', printchar);

  //lê o código do bolsiste

  Serial.println("\nSenha lida com sucesso!");
  Serial.print("<<<<  ");
  Serial.print(codigo);
  Serial.println("   >>>>");
}


#endif

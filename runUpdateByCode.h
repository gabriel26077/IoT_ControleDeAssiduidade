#ifndef RUN_UPDATE_BY_CODE_H
#define RUN_UPDATE_BY_CODE_H

#include "KeyPadFunctions.h"
#include "displayFunctions.h"
#include "databaseFunctions.h"


void runUpdateByCode() {
  //Lê o código do bolsista via teclado numérico
 
  display::print("DIGITE O CODIGO\n");

  String codigo = "";
    
  for(int i=0; i<10; i++){
      
      char key = listen_keypad();
      
      if(key == '#')break;
      if(key=='*')return;
      codigo += key;

      
      sprintf(BUFFER, "CODIGO:\n%s", codigo);
      display::print(BUFFER);

  }
  


  //envia código para o broker
  display::print("CARREGANDO...");
  delay(1000);

  sprintf(BUFFER,"procurando por:\n%s\nem: %s", codigo, USERS_FILEPATH);
  delay(1000);
 
  String name;
  bool state=false;
  bool finded = database::findUserByCode(codigo,name,state);
  
  if (finded) {
      mqtt::reconnect();
      bool success = mqtt::publish(name, state? "0" : "1");
      if(success){
        sprintf(BUFFER, "Bolsista\n%s\natualizado com\nsucesso\nstatus:\n%s",name,state? "INDISPONIVEL" : "DISPONIVEL");
        database::swapValueState(codigo);
        display::print(BUFFER);
      }else{
        sprintf(BUFFER, "Falha ao\nenviar broker");
        display::print(BUFFER); 
      }
      delay(5000);
    
    sprintf(BUFFER,"Bolsista:\n%s\npresente: %d\n", name, (int)state);
    display::print(BUFFER);
  } else {
    display::print("usuario nao\nencontrado");
  }
  delay(10000);
}


#endif

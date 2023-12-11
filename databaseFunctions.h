#ifndef DATABASE_FUNCTIONS_H
#define DATABASE_FUNCTIONS_H

#include "global.h"
#include <FS.h>
#include "SPIFFS.h"
//#include "FSFunctions.h"
#include "config.h"

namespace database{
  bool findUserByCode(String code, String& finded_username, bool& state){
      
    File file = SPIFFS.open(USERS_FILEPATH, "r");
    
    if (!file) {
    Serial.println("Falha ao abrir o file");
    return false;
    }
        
    while (file.available()) {
      String line = file.readStringUntil('\n');
      int spacePosition = line.indexOf(' ');
      int endPosition = line.indexOf(':');
      Serial.printf("<system> space: %d end: %d\n",spacePosition, endPosition);
      
      if (spacePosition != -1 && endPosition!=-1) {
        String _code = line.substring(0, spacePosition);
        String name = line.substring(spacePosition + 1, endPosition);
        
        if (_code == code) {
          
          Serial.printf("<system> char position+1: %c\n", line[endPosition+1]);
          state = line[endPosition+1]=='1';
          Serial.printf("<system> state: %d\n", (int)state);

          finded_username = name;
          Serial.printf("<system> name: %s\n", name);

          file.close();
          return true; // Código encontrado
        }
      }
    
    }
    file.close();
    return false;
  
  }
  
  bool swapValueState(const String& code) {
      
    File file = SPIFFS.open(USERS_FILEPATH, "r+");
    
    if (!file) {
      Serial.println("Falha ao abrir o file");
      return false;
    }
        
    while (file.available()) {
      long startPosition = file.position();
      
      String line = file.readStringUntil('\n');
      int spacePosition = line.indexOf(' ');
      int endPosition = line.indexOf(':');
      if (spacePosition != -1) {
        String _code = line.substring(0, spacePosition);
     
        if (_code == code) {
          
          if(endPosition!=-1){
            bool state = line[endPosition+1]=='1';
            file.seek(startPosition + endPosition + 1);
            file.print(state? "0" : "1");
          }
          
          file.close();
          return true; 
        }
      }
    
    }
    file.close();
    return false;
  }
}

#endif

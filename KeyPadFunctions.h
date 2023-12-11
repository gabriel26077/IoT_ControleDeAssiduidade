#ifndef KEY_PAD_FUNCTIONS_H
#define KEY_PAD_FUNCTIONS_H

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {32,33,25,26}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5,14,15}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

char listen_keypad(){
  char key = NO_KEY;
  while(key == NO_KEY){
    key = keypad.getKey();
  }
  return key;
}


#endif

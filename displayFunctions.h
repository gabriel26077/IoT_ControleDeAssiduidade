#ifndef DISPLAY_FUNCTIONS_H
#define DISPLAY_FUNCTIONS_H

#include "global.h"
#include <LCDWIKI_GUI.h> //Core graphics library
#include <SSD1283A.h> //Hardware-specific library


#if (defined(TEENSYDUINO) && (TEENSYDUINO == 147))

SSD1283A_GUI mylcd(/*CS=*/ 10, /*DC=*/ 15, /*RST=*/ 14, /*LED=*/ -1); //hardware spi,cs,cd,reset,led

#elif defined (ESP8266)
SSD1283A_GUI mylcd(/*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*LED=D2*/ 4); //hardware spi,cs,cd,reset,led
#elif defined(ESP32)
SSD1283A_GUI mylcd(/*CS=5*/ 4, /*DC=*/ 17, /*RST=*/ 16, /*LED=*/ 4); //hardware spi,cs,cd,reset,led
#elif defined(_BOARD_GENERIC_STM32F103C_H_)
SSD1283A_GUI mylcd(/*CS=4*/ SS, /*DC=*/ 3, /*RST=*/ 2, /*LED=*/ 1); //hardware spi,cs,cd,reset,led
#elif defined(__AVR)
SSD1283A_GUI mylcd(/*CS=10*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*LED=*/ 7); //hardware spi,cs,cd,reset,led
#else

SSD1283A_GUI mylcd(/*CS=10*/ 4, /*DC=*/ 17, /*RST=*/ 16, /*LED=*/ 13); //hardware spi,cs,cd,reset,led
#endif

#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF



namespace display {
  void init() 
  {
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    mylcd.init();
    mylcd.setRotation(3);
    mylcd.Set_Text_Mode(0);
    mylcd.Fill_Screen(0x0000);
    mylcd.Set_Text_colour(GREEN);
    mylcd.Set_Text_Back_colour(BLACK);
    mylcd.Set_Text_Size(1);
  }
  
  void print(String str, byte size=1){
    mylcd.Fill_Screen(0);
    mylcd.Set_Text_Size(size);
    mylcd.Print_String(str, 0, 0);
    
    Serial.print("\n\n####   DISPLAY   #####\n");
    Serial.print(    "                     #\n");
    Serial.print(str);
    Serial.print("\n                     #\n");
    Serial.print("#### END DISPLAY #####\n\n");
  }

}

#endif

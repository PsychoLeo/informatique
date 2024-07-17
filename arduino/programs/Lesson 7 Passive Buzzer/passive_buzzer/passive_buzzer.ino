#include <EasyTransfer2.h>
#include <Fat16.h>
#include <FatStructs.h>
#include <Fat16mainpage.h>
#include <Fat16util.h>
#include <Fat16Config.h>
#include <Compass.h>
#include <Squawk.h>
#include <ArduinoRobot.h>
#include <SdInfo.h>
#include <SquawkSD.h>
#include <Arduino_LCD.h>
#include <Multiplexer.h>
#include <EEPROM_I2C.h>
#include <SdCard.h>

//www.elegoo.com
//2016.12.08

#include "pitches.h"
 
// notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int duration = 500;  // 500 miliseconds
 
void setup() {
 
}
 
void loop() {  
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // pin8 output the voice, every scale is 0.5 sencond
    tone(8, melody[thisNote], duration);
     
    // Output the voice after several minutes
    delay(1000);
  }
   
  // restart after two seconds 
  delay(2000);
}

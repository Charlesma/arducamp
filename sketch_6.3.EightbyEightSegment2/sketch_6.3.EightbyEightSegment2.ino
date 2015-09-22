//We always have to include the library
#include "LedControl.h"
 
/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn
 pin 11 is connected to the CLK
 pin 10 is connected to LOAD
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(2,4,3,1);
 
/* we always wait a bit between updates of the display */
unsigned long delaytime=100;
 
void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
 
  lc.setRow(0,0,B00011000);
  lc.setRow(0,1,B00100100);
  lc.setRow(0,2,B01000010);
  lc.setRow(0,3,B10000001);
  lc.setRow(0,4,B10000001);
  lc.setRow(0,5,B01011010);
  lc.setRow(0,6,B00100100);
 
}
 
 
 
void loop() {
}

#include "EmonLib.h"                   // Include Emon Library
#include <LiquidCrystal.h>
 
EnergyMonitor emon1;                   // Create an instance
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup() {
  Serial.begin(9600);
 
  emon1.current(1, 111.1);       // Current: input pin, calibration.
 
  lcd.begin(16, 2);
  lcd.print("hello, world!");
}
 
void loop() {
 
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
 
  Serial.print(Irms*230.0);       // Apparent power
  Serial.print(" ");
  Serial.println(Irms);           // Irms
 
  lcd.setCursor(0, 0);
  lcd.print("ApPw:");
  lcd.print(Irms*230.0);
 
  lcd.setCursor(0, 1);
  lcd.print("Irms:");
  lcd.print(Irms);
 
  lcd.setCursor(13, 1);
  lcd.print(millis() / 1000);
}

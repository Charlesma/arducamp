#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
 
// to use software time clock
#include <swRTC.h>
#include <LiquidCrystal.h>
 
swRTC rtc;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
const int DELAY_INTERVAL = 1000 * 10;
const int LED_NUMBER = 30;
#define LIGHT_THRESHOLD 1000
#define STRIP_PIN 6
int prev_light = 0;
 

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_NUMBER, STRIP_PIN, NEO_GRB + NEO_KHZ800);
 
 
void setup() {
  
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
 
  Serial.begin(9600);
 
  rtc.stopRTC();
  rtc.setTime(9,0,0);
  rtc.setDate(7,14,2015);
  rtc.startRTC();
 
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
 
  lcd.begin(16, 2);
 
  delay(2000);
}
 
 
void loop() {
 
  byte h = rtc.getHours();
  byte m = rtc.getMinutes();
  byte s = rtc.getSeconds();
  byte led_pos = m / 10;
 
  // Read CDS Sensor : 0 to 1023
  int light_value = analogRead(A0);
 
  int avg_light = (prev_light + light_value) / 2;
  int mode = 0;
 

  if (9 <= h && h < 17) {
 
    if (avg_light < LIGHT_THRESHOLD) {
   
      // every even(8, 10, 12, 14, 16) hour
      if ((h % 2) == 0) {
       
        smartFarm(strip.Color(255, 0, 0), 5, led_pos);
       
      }
      // every odd(9, 11, 13, 15, 17) hour
      else {
        smartFarm(strip.Color(0, 0, 255), 5, led_pos);
      }
     
      mode = 1;
    } else {
      turnOff();
     
      mode = 2;
    }
  }
  // turn off all leds
  else {
    turnOff();
   
    mode = 3;
  }
 
 
  lcd.setCursor(0, 0);
  lcd.print("Date:");
  lcd.print(h);
  lcd.print("/");
  lcd.print(m);
  lcd.print("/");
  lcd.print(s);
 
  lcd.setCursor(0, 1);
  lcd.print("L:");
  lcd.print(light_value);
 
  lcd.print(" M:");
  if (mode == 1) {
    lcd.print("Day-on");
  } else if (mode == 2) {
    lcd.print("Day-off");
  } else if (mode == 3) {
    lcd.print("Night-off");
  } else {
    lcd.print("None");
  }
 
  Serial.print("CDS: ");
  Serial.print(light_value, DEC);
  Serial.print(", AVG: ");
  Serial.print(avg_light, DEC);
  Serial.print(", led pos: ");
  Serial.print(led_pos, DEC);
  Serial.print(", ");
  Serial.print(h);
  Serial.print(":");
  Serial.print(m);
  Serial.print(":");
  Serial.print(s);
  Serial.println("");
 
  prev_light = light_value;
 
 
  delay(DELAY_INTERVAL);
}
 
void smartFarm(uint32_t c, uint8_t interval, uint8_t shift) {
 
  // set all to white
    for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(255, 255, 255));
    }
   
    strip.show();
}
 
// turn off all leds
void turnOff() {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0,0,0));
  }
 
  strip.show();
}

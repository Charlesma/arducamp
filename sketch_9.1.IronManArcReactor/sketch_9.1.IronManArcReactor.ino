#include <Adafruit_NeoPixel.h>
 
#define PIN            6 // Arduino Pin number of NeoPixel
#define NUMPIXELS      12 // How many NeoPixels are attached to the Arduino?
 
// init
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
 
int delayval = 80; // delay for half a second
 
void setup() {
 
  pixels.setBrightness(100); // Set the brightness 0 ~ 255 (max brightness)
 
  pixels.begin(); // This initializes the NeoPixel library.
}
 
void loop() {
 
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
 
  for(int i=0;i<NUMPIXELS;i++){
   
   
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,255)); // blue color.
 
    pixels.show(); // This sends the updated pixel color to the hardware.
 
    delay(delayval); // Delay for a period of time (in milliseconds).
 
  }
 
  pixels.clear(); //clear  
}

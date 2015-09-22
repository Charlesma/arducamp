#include <AFMotor.h>
 
#include <Servo.h>
 
int i;
 
Servo servo1;
 
void setup() {  
 
    Serial.begin(9600);          
   
    Serial.println("Test servo!");    
   
    servo1.attach(10);    // 주의)servo1 10번 , servo2는 9번
 
}
 
void loop() {
 
    for (i=0; i<255; i++) {   //From 0 To 255
 
        servo1.write(i);    
       
        delay(3);
    }    
 
    for (i=255; i!=0; i--) {
        servo1.write(i-255);
        delay(3);  
    }  
 
}

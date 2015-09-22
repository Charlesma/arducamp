#include <AFMotor.h>
 
AF_DCMotor motor(2, MOTOR12_64KHZ); // #2, 64KHz pwm  
 
void setup() {  
   
    Serial.begin(9600);           
   
    Serial.println("racing!");    
   
    motor.setSpeed(255);     // maximum speed
 
}  
 
void loop() {  
 
    Serial.print("tien");    
   
    motor.run(FORWARD);      
   
    delay(1000);    
   
    Serial.print("FW");  
   
    motor.run(BACKWARD);      
   
    delay(1000);    
   
    Serial.print("BW");  
   
    motor.run(RELEASE);      
   
    delay(1000);
 
}

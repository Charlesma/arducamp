#include <AFMotor.h>
// Motor with 200 steps per rev (1.8 degree)
// to motor port #2 (M3 and M4)
AF_Stepper motor(200, 2);
void setup() {
  // set up Serial library at 9600 bps
  Serial.begin(9600);
  Serial.println("Stepper test!");
  motor.setSpeed(10); // 10 rpm  
 
}
void loop() {
 
  Serial.println("Down");
  motor.step(500, FORWARD, MICROSTEP); //Down
  delay(2000);
 
  Serial.println("Up");
  motor.step(500, BACKWARD, MICROSTEP); //up
 
}

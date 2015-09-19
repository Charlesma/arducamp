int MOTION_IN = 2;
int LED_OUT = 10;
 
void setup() {
  pinMode(MOTION_IN, INPUT);
  pinMode(LED_OUT, OUTPUT);
}
 
void loop() {
  if (digitalRead(MOTION_IN) == HIGH) {
    digitalWrite(LED_OUT, HIGH);  // LED 전원 켜기
  } else {
    digitalWrite(LED_OUT, LOW);  // LED 전원 끄기
  }
}

int TILT_IN = 2;
int LED_OUT = 6;
 
void setup() {
  pinMode(TILT_IN, INPUT);
  pinMode(LED_OUT, OUTPUT);
}
 
void loop() {
  if (digitalRead(TILT_IN) == HIGH) {
    digitalWrite(LED_OUT, HIGH);  // LED 전원 켜기
  } else {
    digitalWrite(LED_OUT, LOW);  // LED 전원 끄기
  }
}

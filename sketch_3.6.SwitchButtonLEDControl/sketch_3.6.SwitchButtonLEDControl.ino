int BUTTON_INPUT = 2;
int LED_OUPUT = 13;
 
void setup() {
  pinMode(BUTTON_INPUT, INPUT); // 디지털 입력 설정 (생략 가능)
  pinMode(LED_OUPUT, OUTPUT);  // 디지털 출력 설정
}
 
void loop() {
  int buttonState = digitalRead(BUTTON_INPUT);
  if (buttonState == HIGH) {
    digitalWrite(LED_OUPUT, HIGH);
  }
  else {
    digitalWrite(LED_OUPUT, LOW);
  }
}

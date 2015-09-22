// setup 함수는 처음 한번만 실행됩니다.
void setup() {
  // 13번 디지털 핀을 출력 핀으로 설정합니다.
  pinMode(13, OUTPUT);
}
 
// loop 함수는 계속해서 영원히 반복 실행됩니다.
void loop() {
  digitalWrite(13, HIGH);   // LED 켜기 (HIGH is the voltage level)
  delay(1000);               // 1초 동안 대기 (1000 밀리 초)
  digitalWrite(13, LOW);    // LED 끄기
  delay(5000);               // 5초 동안 대기 (1000 밀리 초)
}

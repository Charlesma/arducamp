void setup() {
  // 시리얼 모니터와 통신하기 위해 초기화 합니다.
  Serial.begin(9600);
}
 
void loop() {
  // 아날로그 0번핀의 값을 읽어서 시리얼모니터에 출력합니다.
  Serial.println(analogRead(A0)); //0~ 1023 사이의 값이 입력됩니다
  delay(1000);               // 1초 동안 대기 (1000 밀리 초)
}

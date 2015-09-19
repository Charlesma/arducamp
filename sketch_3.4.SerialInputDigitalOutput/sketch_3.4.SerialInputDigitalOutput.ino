int LED_OUPUT = 13;
 
void setup() {
  Serial.begin(9600);
  pinMode(LED_OUPUT, OUTPUT);
}
 
void loop() {
  if (Serial.available() > 0) {  // 시리얼로부터 읽어올 값이 있는지 검사
 
    char readChar = Serial.read();  // 기시리얼 값을 1자씩 읽기
 
    Serial.println(readChar);  // 읽어온 값을 다시 시리얼 모니터에 표시
 
    if (readChar == '1') {
      digitalWrite(LED_OUPUT, HIGH); // LED 켜기
    } else {
      digitalWrite(LED_OUPUT, LOW);  // LED 끄기
    }
  }
}

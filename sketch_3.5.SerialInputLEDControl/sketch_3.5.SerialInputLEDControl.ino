int LED1_OUPUT = 6;
int LED2_OUPUT = 7;
 
void setup() {
  Serial.begin(9600);
  pinMode(LED1_OUPUT, OUTPUT);
  pinMode(LED2_OUPUT, OUTPUT);
}
 
void loop() {
  if (Serial.available() > 0) {  // 시리얼로부터 읽어올 값이 있는지 검사
 
    char readChar = Serial.read();  // 기시리얼 값을 1자씩 읽기
 
    Serial.println(readChar);  // 읽어온 값을 다시 시리얼 모니터에 표시
 
    if (readChar == '0') {
      digitalWrite(LED1_OUPUT, LOW);
      digitalWrite(LED2_OUPUT, LOW);
    } else if (readChar == '1') {
      digitalWrite(LED1_OUPUT, HIGH);
      digitalWrite(LED2_OUPUT, LOW);
    } else if (readChar == '2') {
      digitalWrite(LED1_OUPUT, LOW);
      digitalWrite(LED2_OUPUT, HIGH);
    } else if (readChar == '3') {
      digitalWrite(LED1_OUPUT, HIGH);
      digitalWrite(LED2_OUPUT, HIGH);
    }
  }
}

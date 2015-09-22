int ledPin = 9;
 
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  //9번핀에 LED를 출력합니다.
}
 
void loop() {
  int sensorValue = analogRead(A0); //아날로그 0번핀 입력값 저장
  // 아날로그 0번핀의 값을 읽어서 시리얼모니터에 출력합니다.
  Serial.println(sensorValue);
  //analogRead (0 ~ 1023) , analogWrite (0~255)
  analogWrite(ledPin, sensorValue / 4);
  delay(1);
}

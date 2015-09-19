int TRIGGER_OUT = 2;
int ECHO_IN = 3;
 
void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_OUT, OUTPUT);
  pinMode(ECHO_IN, INPUT);
}
 
void loop() {
  long duration, cm;
 
  digitalWrite(TRIGGER_OUT, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_OUT, LOW);
 
  duration = pulseIn(ECHO_IN, HIGH);
  cm = microseondsToCentimeters(duration);
 
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
 
  delay(300);
}
 
// 1/1000 초를 인치(Inch) 거리로 변환하는 함수
long microsencodsToInches(long microseconds)
{
  // 인치당 73.746초가 소요됨. 음파 속도는 초당 1130 피트를 이동함.
  // 왕복 거리 이므로 2로 나눔
  return microseconds / 74 / 2;
}
 
long microseondsToCentimeters(long microseconds)
{
  // 음파 속도는 초당 340 m/s, 1cm당 29 ms이 소요됨
  // 왕복 거리 이므로 2로 나눔
  return microseconds / 29 / 2;
}

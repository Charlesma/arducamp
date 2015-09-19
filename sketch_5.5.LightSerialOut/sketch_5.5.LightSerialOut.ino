void setup() {
  Serial.begin(9600);
}
 
void loop() {
  int value;
 
  value = analogRead(A0);
 
  float temp = (5.0 * value * 100 ) / 1024;
 
  Serial.println(temp);
 
  delay(1000);
}

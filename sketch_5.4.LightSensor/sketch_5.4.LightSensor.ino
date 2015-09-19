int LED_OUT = 10;
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  int value;
 
  value = analogRead(A0);
 
  Serial.println(value);
 
  if (value > 512) {
    digitalWrite(LED_OUT, HIGH);
  } else {
    digitalWrite(LED_OUT, LOW);
  }
 
  delay(300);
}

int LED_OUT = 13;
 
void setup() {
  pinMode(LED_OUT, OUTPUT);
}
 
void loop() {
  digitalWrite(LED_OUT, HIGH);
  delay(1000);
 
  digitalWrite(LED_OUT, LOW);
  delay(1000);
}

int PIEZO_OUT = 2;
 
void setup() {
  pinMode(PIEZO_OUT, OUTPUT);
}
 
void loop() {
  int read_light = analogRead(A0);
  int pitch = 200 + read_light / 4;
 
  tone(PIEZO_OUT, pitch);
}

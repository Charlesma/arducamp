#define VIBRATION_INPUT1  A0
#define VIBRATION_INPUT2  A1
#define VIBRATION_INPUT3  A2
 
#define PIEZO_OUTPUT 5
 
int previsou_value1 = 0;
int previsou_value2 = 0;
int previsou_value3 = 0;
const int threshold = 20;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIEZO_OUTPUT, OUTPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  int val1 = analogRead(VIBRATION_INPUT1);
  int val2 = analogRead(VIBRATION_INPUT2);
  int val3 = analogRead(VIBRATION_INPUT3);
 
  bool hitted = false;
  if (previsou_value1 + threshold < val1)
  {
    Serial.println("hit 1");
    tone(PIEZO_OUTPUT, 261); // C
    hitted = true;
  }
  if (previsou_value2 + threshold < val2)
  {
    Serial.println("hit 2");
    tone(PIEZO_OUTPUT, 330); // e
    //delay(100);
    //noTone(PIEZO_OUTPUT);
    hitted = true;
  }
  if (previsou_value3 + threshold < val3)
  {
    Serial.println("hit 3");
    tone(PIEZO_OUTPUT, 392); // F
    //delay(100);
    //noTone(PIEZO_OUTPUT);
    hitted = true;
  }
 
  if (hitted) {
    delay(100);
    noTone(PIEZO_OUTPUT);
  }
 
    previsou_value1 = val1;
    previsou_value2 = val2;
    previsou_value3 = val3;
}

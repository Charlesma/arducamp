/*
 "="    is ASCII character 61
 "0-9"  is ASCII characters 48 ~ 57
 "-"    is ASCII character 45
 "+"    is ASCII character 43
*/
 
byte inputByte; // serial buffer data
long calSum;    // sum of the numbers
int tmpNum;      // a temp variable number
 
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
 
 calSum = 0;
 tmpNum = 0;
 
 if (Serial.available() > 0) {
  while(Serial.available() > 0){ // while bytes remain in the serial buffer
 
    inputByte = Serial.read(); // read byte
 
    //Display Sum
    if (inputByte == 61) {
 
      Serial.print('=');
      delay(5);            
 
      Serial.println(calSum);
      delay(5);
    }
 
  //input number
    if (inputByte >= 48 && inputByte <= 57) {
      tmpNum = inputByte-48;
      calSum = tmpNum;
      Serial.print(tmpNum); delay(5);
    }
 
  // input "-" minus sign
    if (inputByte == 45) {
      inputByte = Serial.read(); // read in the next byte
      tmpNum = inputByte-48; // since ASCII number have codes of 48 ~ 57, this will convert to the decimal
   
      Serial.print('-');
      delay(5);
     
      Serial.print(tmpNum);
      delay(5);
     
    calSum = calSum - tmpNum; // total
    }
 
  // input "+" plus sign
    if (inputByte == 43) {
      inputByte = Serial.read(); // read in the next byte
      tmpNum = inputByte-48;  // since ASCII number have codes of 48 ~ 57, this will convert to the decimal
   
      Serial.print('+');
      delay(5);
   
      Serial.print(tmpNum);
      delay(5);
   
      calSum = calSum + tmpNum; // total
    }
   } //End of while
   
  }//End of if
}

#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
 
// ----edit-----------------------
int number_mp3 = 4;  // mp3 count
int delaytime = 20000;  // delay time
// ----edit-----------------------
 
long randomNumber = 1; //random number
int lastSong = 0;
 
int sensorPin = 8; //pir sensor number
int ledPin = 13; //test 용 LED
 
void setup()
{
  pinMode(sensorPin,INPUT);
  pinMode(ledPin,OUTPUT);
  Serial.begin (9600);
 
  /* mp3 setting */
    mp3_set_serial (Serial);      //set Serial for DFPlayer-mini mp3 module
    delay(1);                     // delay 1ms to set volume
    mp3_set_volume (30);          // 볼륨값  0~30
   
    mp3_play (1);    //play "mp3/0001.mp3"
}
 
void loop()
{
  //random fucntion
     randomNumber = random(number_mp3)+1;
 
  int  val = digitalRead(sensorPin);
 
  if(val == HIGH && randomNumber != lastSong ) {
      digitalWrite(ledPin, HIGH);  // turn LED ON
      Serial.println("Somebody is in this area!");  
     
      mp3_play (randomNumber);
      lastSong = randomNumber; // 마지막노래번호를 기억하기 위한 것            
      delay (delaytime);
      mp3_stop ();
       
       
  } else {
      digitalWrite(ledPin, LOW);  // turn LED ON
      Serial.println("No one!");
     
      mp3_stop ();
  }
 
  delay(500);
 
}

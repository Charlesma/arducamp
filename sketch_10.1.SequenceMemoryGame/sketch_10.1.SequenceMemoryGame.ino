#include "pitches.h"
 
int GAME_BUTTON_CNT = 10;
int PREV_NUMBER = -1;
int BTN_START_PIN = 2; // start button
int BTN_GAME_PIN[10] = {3,4,5,6,7,8,9,10,11,12}; // 1~10 button by order
int SOUND_PIN = 13;
 
enum GMODE {
  GMODE_GAME_START,       // 0, start new game, initialize all
  GMODE_HIT_BTN_CORRECT,  // 1, hit correct memorized button
  GMODE_HIT_BTN_WRONG,     // 2, hit wrong memorized button
  GMODE_USER_CHANGE,      // 3, change user
  GMODE_GAME_END          // 3
};
 
int melody1[] = {NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};
int noteDurations1[] = {4, 8, 8, 4, 4, 4, 4, 4};
 
int melody4[] = {  
    NOTE_E7, NOTE_E7, 0, NOTE_E7,
    0, NOTE_C7, NOTE_E7, 0,
    NOTE_G7, 0, 0,  0,
    NOTE_G6, 0, 0, 0,
   
    NOTE_C7, 0, 0, NOTE_G6,
    0, 0, NOTE_E6, 0,
    0, NOTE_A6, 0, NOTE_B6,
    0, NOTE_AS6, NOTE_A6, 0,
   
    NOTE_G6, NOTE_E7, NOTE_G7
  };
int noteDurations4[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9};
 
int CURRENT_STAGE = 0; // current game stage which start from zero
int MEMORY_STAGE = 0;  // number button memorized count
int order_memorize[50];
 
void setup() {
  // put your setup code here, to run once:
 
  pinMode(SOUND_PIN, OUTPUT);
  Serial.begin(9600);
  startGame();
}
 
void loop() {
 
  int buttonState = readButton();
 
  // start game  
  if (buttonState == 0) {
    startGame();
  }
  else if (1 <= buttonState && buttonState <= 10 ) {
   
    if (buttonState != PREV_NUMBER) {
 
      Serial.print("button changed :");
      Serial.print(PREV_NUMBER);
      Serial.print(" - ");
      Serial.println(buttonState);
     
      // at first clicked
      if (MEMORY_STAGE == 0 && CURRENT_STAGE == 0) {
          Serial.println("FIRST");
       
        order_memorize[0] = buttonState;
        MEMORY_STAGE = 1;
        CURRENT_STAGE = 0;
       
        PREV_NUMBER = -1; // reset previous
       
        soundEffect(GMODE_USER_CHANGE);
      }
      // add new number
      else if (MEMORY_STAGE == CURRENT_STAGE) {
        Serial.println("ADD NEW");
 
        order_memorize[CURRENT_STAGE] = buttonState;        
        MEMORY_STAGE++;
        CURRENT_STAGE = 0;
 
       
        PREV_NUMBER = -1;
       
        soundEffect(GMODE_USER_CHANGE);
      }
      // mid number
      else {
        Serial.print("CHECK [ ");
        Serial.print(CURRENT_STAGE);
        Serial.print( " / " );
        Serial.print(MEMORY_STAGE);
        Serial.print( " / " );
        Serial.print(order_memorize[CURRENT_STAGE]);
        Serial.print( " / " );
        Serial.print(buttonState);
        Serial.print(" ]");
       
        // correct number
        if (order_memorize[CURRENT_STAGE] == buttonState) {
          Serial.println("CHECK Correct!");
         
          CURRENT_STAGE++;
          PREV_NUMBER = buttonState;
         
          soundEffect(GMODE_HIT_BTN_CORRECT);
        }
        // wrong number
        else {
          Serial.println("CHECK Wrong!");
         
          soundEffect(GMODE_HIT_BTN_WRONG);
        }
      }
    }
  }
 
  delay(50);
}
 
void startGame() {
  soundEffect(GMODE_GAME_START);
  CURRENT_STAGE = 0;
  MEMORY_STAGE = 0;
  PREV_NUMBER = -1;
}
 
 
// game start sound
void soundEffect(int smode) {
  switch (smode)
  {
    case GMODE_GAME_START:
      playMemody(melody4, noteDurations4, sizeof(melody4)/sizeof(int));
    break;
    case GMODE_HIT_BTN_CORRECT:
      playTone(NOTE_D6, 8);
    break;
    case GMODE_HIT_BTN_WRONG:
      playMemody(melody1, noteDurations1, sizeof(melody1)/sizeof(int));
    break;
    case GMODE_USER_CHANGE:
      playTone(NOTE_B4, 2);
    break;
  }
}
 
// 0: START, 1~10: GAME BUTTON
int readButton() {
  int buttonState = digitalRead(BTN_START_PIN);
  if (buttonState == HIGH)
  {
    if (PREV_NUMBER == 0)
      return -1;
    else
      return 0;
  }
  else
  {
    for (int i = 0; i < GAME_BUTTON_CNT; i++)
    {
      buttonState = digitalRead(BTN_GAME_PIN[i]);
      if (buttonState == HIGH)
      {
          return i+1;
      }
    }
  }
 
  return -1;
}
 
 
void playMemody(int m[], int d[], int len) {
  for (int thisNote = 0; thisNote < len; thisNote++) {
 
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/d[thisNote];
    tone(SOUND_PIN, m[thisNote],noteDuration);
 
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(SOUND_PIN);
  }
}
 
void playTone(int m, int d) {
 
  int noteDuration = 1000/d;
  tone(SOUND_PIN, m,noteDuration);
 
  // to distinguish the notes, set a minimum time between them.
  // the note's duration + 30% seems to work well:
  int pauseBetweenNotes = noteDuration * 1.30;
  delay(pauseBetweenNotes);
  // stop the tone playing:
  noTone(SOUND_PIN);
}

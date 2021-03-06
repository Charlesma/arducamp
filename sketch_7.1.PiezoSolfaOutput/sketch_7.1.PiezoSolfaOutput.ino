#include <pitches.h>

#define PIEZO_OUT 3
#define MELODY_LEN 8

// melody
int melody[MELODY_LEN] = {
  NOTE_C4, // 도 (C)
  NOTE_D4, // 레 (D)
  NOTE_E4, // 미 (E)
  NOTE_F4, // 파 (F)
  NOTE_G4, // 솔 (G)
  NOTE_A4, // 라 (A)
  NOTE_B4, // 시 (B)
  NOTE_C5  // 도 (C)
};
 
// 멜로디의 각 소리 출력 시간
int duration[MELODY_LEN] = {
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1
};
 
void setup() {
 
  for (int i = 0; i < MELODY_LEN; i++) {
 
    int d = duration[i] * 250;
    int m = melody[i];
    tone(PIEZO_OUT, m, d); // 소리 출력
 
    int pauseBetweenNotes = d * 1.30;
      delay(pauseBetweenNotes);
  }
  noTone(PIEZO_OUT); // 소리 출력 중지
}
 
void loop() {
  // 내용 없음
}

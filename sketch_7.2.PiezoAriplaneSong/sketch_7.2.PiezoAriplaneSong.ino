#include "pitches.h"
 
int PIEZO_OUT = 3;
#define MELODY_LEN 25
 
// 멜로디의 각 소절 계이름
int melody[MELODY_LEN] = {
  NOTE_E4, // 미 (E)
  NOTE_D4, // 레 (D)
  NOTE_C4, // 도 (C)
  NOTE_D4, // 레 (D)
  NOTE_E4, // 미 (E)
  NOTE_E4, // 미 (E)
  NOTE_E4, // 미 (E)
  NOTE_D4, // 레 (D)
  NOTE_D4, // 레 (D)
  NOTE_D4, // 레 (D)
  NOTE_E4, // 미 (E)
  NOTE_E4, // 미 (E)
  NOTE_E4, // 미 (E)
  NOTE_E4, // 미 (E)
  NOTE_D4, // 레 (D)
  NOTE_C4, // 도 (C)
  NOTE_D4, // 레 (D)
  NOTE_E4, // 미 (E)
  NOTE_E4, // 미 (E)
  NOTE_E4, // 미 (E)
  NOTE_D4, // 레 (D)
  NOTE_D4, // 레 (D)
  NOTE_E4, // 미 (E)
  NOTE_D4, // 레 (D)
  NOTE_C4  // 도 (C)
};
 
// 멜로디의 각 소리 출력 시간
int duration[MELODY_LEN] = {
6,
2,
4,
4,
4,
4,
8,
4,
4,
8,
4,
4,
8,
6,
2,
4,
4,
4,
4,
8,
4,
4,
8,
2,
8
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

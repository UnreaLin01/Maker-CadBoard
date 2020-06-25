#include "Keyboard.h"

#define row1 12
#define row2 11
#define row3 10
#define row4 9
#define row5 8
#define row6 7
#define row7 6
#define row8 5
#define row9 4
#define row10 3

#define column1 A0
#define column2 A1
#define column3 A2
#define column4 A3
#define column5 A4
#define column6 A5

void setup() {
  Serial.begin(115200);
  Keyboard.begin();
}
void loop() {
  
}

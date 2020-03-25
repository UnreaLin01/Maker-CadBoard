#include "Keyboard.h"
#define MuxA 4
#define MuxB 5
#define MuxC 6

#define Mux1Input A4
#define Mux2Input A5

boolean nowSw[12];
boolean preSw[12];
byte funcSw[12] = {102, 103, 104, 99, 100, 101, 96, 97, 98, 105, 110, 108};

void setup() {
  Serial.begin(115200);
  Keyboard.begin();
  pinMode(MuxA,OUTPUT);
  pinMode(MuxB,OUTPUT);
  pinMode(MuxC,OUTPUT);
  pinMode(Mux1Input,INPUT);
  pinMode(Mux2Input,INPUT);
}
void loop() {
  for(int x = 0; x <= 5; x++){
    digitalWrite(MuxA, (x & 0b00000001));
    digitalWrite(MuxB, ((x & 0b00000010) >> 1));
    digitalWrite(MuxC, ((x & 0b00000100) >> 2));
    nowSw[x] = digitalRead(Mux1Input);
    nowSw[x+6] = digitalRead(Mux2Input);
  }
  for(int x = 0; x<= 11; x++){
    Serial.print(nowSw[x]);
  }
  Serial.println();

  for(int x = 0; x <= 11; x++){
    if(preSw[x] == HIGH && nowSw[x] == LOW){
      Keyboard.press(funcSw[x]);
    }else if(preSw[x] == LOW && nowSw[x] == HIGH){
      Keyboard.release(funcSw[x]);
    }
    preSw[x] = nowSw[x];
  }
 
}

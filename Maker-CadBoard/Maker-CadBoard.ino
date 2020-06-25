#include "Keyboard.h"

#define VCC 8
#define GND 7

#define MuxA 2
#define MuxB 3
#define MuxC 4
#define Mux1Input 5
#define Mux2Input 6

#define LED 13

boolean nowSw[12];
boolean preSw[12];
byte funcSw[12] = {KEY_ESC, '7', '4', '1', '2', '5', '8', '0', KEY_RETURN, '9', '6', '3'};

void setup() {
  Serial.begin(115200);
  Keyboard.begin();

  pinMode(VCC,OUTPUT);
  pinMode(GND,OUTPUT);
  digitalWrite(VCC,HIGH);
  digitalWrite(GND,LOW);
  
  pinMode(MuxA,OUTPUT);
  pinMode(MuxB,OUTPUT);
  pinMode(MuxC,OUTPUT);
  pinMode(Mux1Input,INPUT);
  pinMode(Mux2Input,INPUT);

  pinMode(LED,OUTPUT);
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

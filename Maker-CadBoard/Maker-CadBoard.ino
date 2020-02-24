#include "Keyboard.h"

boolean preSw1 = false;
boolean preSw2 = false;
boolean preSw3 = false;
boolean preSw4 = false;
boolean preSw5 = false;
boolean preSw6 = false;
boolean preSw7 = false;
boolean preSw8 = false;
boolean preSw9 = false;
boolean preSw10 = false;

long count = 0;

void setup() {
  Serial.begin(115200);
  Keyboard.begin();
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(A5,INPUT_PULLUP);
  pinMode(A4,INPUT_PULLUP);
  pinMode(A3,INPUT_PULLUP);
  pinMode(A2,INPUT_PULLUP);
  pinMode(A1,INPUT_PULLUP);
}

void loop() {
  boolean sw1 = digitalRead(2);
  boolean sw2 = digitalRead(3);
  boolean sw3 = digitalRead(4);
  boolean sw4 = digitalRead(5);
  boolean sw5 = digitalRead(6);
  boolean sw6 = digitalRead(A5);
  boolean sw7 = digitalRead(A4);
  boolean sw8 = digitalRead(A3);
  boolean sw9 = digitalRead(A2);
  boolean sw10 = digitalRead(A1);
  
  if((preSw1 == HIGH) && (sw1 == LOW)){
    Keyboard.press('1');
  }else if((preSw1 == LOW) && (sw1 == HIGH)){
    Keyboard.release('1');
  }
  if((preSw2 == HIGH) && (sw2 == LOW)){
    Keyboard.press('2');
  }else if((preSw2 == LOW) && (sw2 == HIGH)){
    Keyboard.release('2');
  }
  if((preSw3 == HIGH) && (sw3 == LOW)){
    Keyboard.press('3');
  }else if((preSw3 == LOW) && (sw3 == HIGH)){
    Keyboard.release('3');
  }
  if((preSw4 == HIGH) && (sw4 == LOW)){
    Keyboard.press('4');
  }else if((preSw4 == LOW) && (sw4 == HIGH)){
    Keyboard.release('4');
  }
  if((preSw5 == HIGH) && (sw5 == LOW)){
    Keyboard.press('5');
  }else if((preSw5 == LOW) && (sw5 == HIGH)){
    Keyboard.release('5');
  }
  
  if((preSw6 == HIGH) && (sw6 == LOW)){
    Keyboard.press('6');
  }else if((preSw6 == LOW) && (sw6 == HIGH)){
    Keyboard.release('6');
  }
  if((preSw7 == HIGH) && (sw7 == LOW)){
    Keyboard.press('7');
  }else if((preSw7 == LOW) && (sw7 == HIGH)){
    Keyboard.release('7');
  }
  if((preSw8 == HIGH) && (sw8 == LOW)){
    Keyboard.press('8');
  }else if((preSw8 == LOW) && (sw8 == HIGH)){
    Keyboard.release('8');
  }
  if((preSw9 == HIGH) && (sw9 == LOW)){
    Keyboard.press('9');
  }else if((preSw9 == LOW) && (sw9 == HIGH)){
    Keyboard.release('9');
  }
  if((preSw10 == HIGH) && (sw10 == LOW)){
    Keyboard.press(KEY_RETURN);
  }else if((preSw10 == LOW) && (sw10 == HIGH)){
    Keyboard.release(KEY_RETURN);
  }

  preSw1 = sw1;
  preSw2 = sw2;
  preSw3 = sw3;
  preSw4 = sw4;
  preSw5 = sw5;
  preSw6 = sw6;
  preSw7 = sw7;
  preSw8 = sw8;
  preSw9 = sw9;
  preSw10 = sw10;
}

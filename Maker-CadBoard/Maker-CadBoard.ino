#define Mux1A A3
#define Mux1B A4
#define Mux1C A5
#define Mux1Input 2

boolean preSw1 = false;
boolean preSw2 = false;
boolean preSw3 = false;
boolean preSw4 = false;
boolean preSw5 = false;
boolean preSw6 = false;
boolean preSw7 = false;
boolean preSw8 = false;


void setup() {
  Serial.begin(115200);
  
  pinMode(Mux1A,OUTPUT);
  pinMode(Mux1B,OUTPUT);
  pinMode(Mux1C,OUTPUT);
  pinMode(Mux1Input,INPUT);
}

void loop() {
  Serial.print(readMux1(0, 0, 0));
  Serial.print(readMux1(0, 0, 1));
  Serial.print(readMux1(0, 1, 0));
  Serial.print(readMux1(0, 1, 1));
  Serial.print(readMux1(1, 0, 0));
  Serial.print(readMux1(1, 0, 1));
  Serial.print(readMux1(1, 1, 0));
  Serial.print(readMux1(1, 1, 1));
  Serial.println();
}

boolean readMux1(boolean c,boolean b, boolean a){
  digitalWrite(Mux1A,a);
  digitalWrite(Mux1B,b);
  digitalWrite(Mux1C,c);
  return digitalRead(Mux1Input);
}

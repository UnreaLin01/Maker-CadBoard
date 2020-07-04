#include <Keyboard.h>
#include <FastLED.h>

#define LED_DATA_PIN 13
#define LED_IC WS2812B
#define LED_NUMS 56
#define LED_TYPE GRB
#define LED_BRIGHTNESS 96
CRGB leds[LED_NUMS];

#define ROW0 12
#define ROW1 11
#define ROW2 10
#define ROW3 9
#define ROW4 8
#define ROW5 7
#define ROW6 6
#define ROW7 5
#define ROW8 4
#define ROW9 3

#define COLUMN0 A0
#define COLUMN1 A1
#define COLUMN2 A2
#define COLUMN3 A3
#define COLUMN4 A4
#define COLUMN5 A5

#define KEY_ESC 177
#define KEY_F4 197
#define KEY_F7 200
#define KEY_F11 204

#define KEY_TILDE 96
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define KEY_8 56
#define KEY_9 57

#define KEY_TAB 179
#define KEY_Q 113
#define KEY_E 101
#define KEY_R 114
#define KEY_T 116
#define KEY_Y 121
#define KEY_ASTERISK 42
#define KEY_SLASH 47
#define KEY_0 48
#define KEY_DELETE 212

#define KEY_CAPS_LOCK 193
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_L 108
#define KEY_O 111
#define KEY_EQUAL 61
#define KEY_COMMA 44
#define KEY_DOT 46

#define KEY_LEFT_SHIFT 129
#define KEY_Z 122
#define KEY_X 120
#define KEY_C 99
#define KEY_V 118
#define KEY_M 109
#define KEY_HYPHEN 45
#define KEY_LEFT_ARROW 216
#define KEY_RIGHT_ARROW 215

#define KEY_LEFT_CTRL 128
#define KEY_LEFT_ALT 130
#define KEY_SPACE 32

const byte columnNum = 6; 
const byte rowNum = 10;
const char* column[columnNum] = {COLUMN0,COLUMN1,COLUMN2,COLUMN3,COLUMN4,COLUMN5};
const char* row[rowNum] = {ROW0,ROW1,ROW2,ROW3,ROW4,ROW5,ROW6,ROW7,ROW8,ROW9};

boolean swPreviousState[6][10] = {{false}};
boolean swState[6][10] = {{false}};
const int swMainFunc[6][10] = {
  {KEY_ESC        ,KEY_F4         ,KEY_F7         ,KEY_F11        ,-1             ,-1             ,-1             ,-1             ,-1             ,-1             },
  {KEY_TILDE      ,KEY_1          ,KEY_2          ,KEY_3          ,KEY_4          ,KEY_5          ,KEY_6          ,KEY_7          ,KEY_8          ,KEY_9          },
  {KEY_TAB        ,KEY_Q          ,KEY_E          ,KEY_R          ,KEY_T          ,KEY_Y          ,KEY_ASTERISK   ,KEY_SLASH      ,KEY_0          ,KEY_DELETE     },
  {KEY_CAPS_LOCK  ,KEY_A          ,KEY_S          ,KEY_D          ,KEY_L          ,KEY_O          ,KEY_EQUAL      ,KEY_COMMA      ,KEY_DOT        ,-1             },
  {KEY_LEFT_SHIFT ,KEY_Z          ,KEY_X          ,KEY_C          ,KEY_V          ,KEY_M          ,KEY_HYPHEN     ,KEY_LEFT_ARROW ,KEY_RIGHT_ARROW,-1             },
  {KEY_LEFT_CTRL  ,KEY_LEFT_ALT   ,-1             ,KEY_SPACE      ,-1             ,-1             ,-1             ,-1             ,-1             ,-1             }          
};

void setup() {
  FastLED.addLeds<LED_IC, LED_DATA_PIN, LED_TYPE>(leds, LED_NUMS);
  FastLED.setBrightness(LED_BRIGHTNESS);
  Keyboard.begin();
  Serial.begin(115200);
  for(int x = 0; x < columnNum; x++){pinMode(column[x],OUTPUT); digitalWrite(column[x],LOW);}
  for(int x = 0; x < rowNum; x++){pinMode(row[x],INPUT);}
  for(int x = 0; x < LED_NUMS; x++){leds[x] = CRGB::Black;}
  FastLED.show();
}

void swStateUpdate(){
  memcpy(swPreviousState,swState,sizeof(swState));
  for(int x = 0; x < columnNum; x++){
    digitalWrite(column[x],HIGH);
    for(int y = 0; y < rowNum; y++){swState[x][y] = digitalRead(row[y]);}
    digitalWrite(column[x],LOW);
  }
}

void loop() {
  for(int x = 0; x < columnNum; x++){
    for(int y = 0; y < rowNum; y++){
      if(swState[x][y] == HIGH && swPreviousState[x][y] == LOW){
        Keyboard.press(swMainFunc[x][y]);
      }else if(swState[x][y] == LOW && swPreviousState[x][y] == HIGH){
        Keyboard.release(swMainFunc[x][y]);
      }
    }
  }
  swStateUpdate();
}

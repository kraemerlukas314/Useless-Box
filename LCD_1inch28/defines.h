// include libraries
#include "Adafruit_GFX.h"
#include "Adafruit_GC9A01A.h"




// pin defines
#define PIN_BTN 2

#define TFT_DC 7
#define TFT_CS 10

Adafruit_GC9A01A tft(TFT_CS, TFT_DC);

// display defines
#define WHITE 0xffffff
#define BLACK 0x000000
#define BACKGROUND BLACK
#define MOUTH_COLOR WHITE
#define X_MIN 0
#define Y_MIN 0
#define X_MAX 240
#define Y_MAX 240
#define Y_MOUTH_START Y_MAX / 2.2
#define MOUTH_THICKNESS 20
#define MOUTH_MID Y_MAX * 0.625
#define EYES_DISTANCE_EDGES 40
#define EYES_SIZE 30


int eyesColor = 0x0066ff;
int eyesColorSize = EYES_SIZE / 2;
int eyesPupilSize = EYES_SIZE / 2.8;
int mouthStatus = 0;
int eyeLeftStatus = 0;
int eyeRightStatus = 0;
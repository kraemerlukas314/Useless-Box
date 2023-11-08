#include <SPI.h>
#include "LCD_Driver.h"
#include "GUI_Paint.h"
#include "image.h"
#include "Adafruit_GFX.h"
#include "Adafruit_GC9A01A.h"

#define TFT_DC 7
#define TFT_CS 10

// Hardware SPI on Feather or other boards
Adafruit_GC9A01A tft(TFT_CS, TFT_DC);
const int BACKGROUND = BLACK;
const int MOUTH_COLOR = WHITE;
const int X_MIN = 0;
const int Y_MIN = 0;
const int X_MAX = 240;
const int Y_MAX = 240;
const int Y_MOUTH_START = Y_MAX / 2.4;
const int MOUTH_THICKNESS = 15;
const int EYES_DISTANCE_EDGES = 30;
const int EYES_SIZE = 30;

int eyesColor = BLUE;


void setup() {



  tft.begin();
  tft.fillScreen(BLACK);
  eyesNeutral();
  mouthNeutral();
}

void displayClear() {
  //Clear Display (Set display to background color)
  tft.fillScreen(BACKGROUND);
}

void mouthReset() {
  //Draw a Rectangle from start of mouth to end of display
  tft.fillRect(X_MIN, Y_MOUTH_START, X_MAX, Y_MAX - Y_MOUTH_START, BACKGROUND);
}

void mouthSmile1() {
  mouthReset();
  tft.fillCircle(X_MAX / 2, Y_MAX / 2, Y_MOUTH_START, MOUTH_COLOR);
  tft.fillRect(X_MIN, Y_MOUTH_START, X_MAX, Y_MAX / 2 - Y_MOUTH_START, BACKGROUND);
  tft.fillCircle(X_MAX / 2, Y_MAX / 2 - MOUTH_THICKNESS, 90, BACKGROUND);
}

void mouthNeutral() {
  mouthReset();
  tft.drawLine(X_MAX * 0.125, Y_MAX * 0.625, X_MAX - (X_MAX * 0.125), Y_MAX * 0.625 + MOUTH_THICKNESS, MOUTH_COLOR);
}

void eyeLeftReset() {
  tft.fillRect(X_MIN, Y_MIN, X_MAX / 2, Y_MOUTH_START, BACKGROUND);
}

void eyeRightReset() {
  tft.fillRect(X_MAX / 2, Y_MIN, X_MAX / 2, Y_MOUTH_START, BACKGROUND);
}

void eyeLeftNeutral() {
  eyeLeftReset();
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE, EYES_DISTANCE_EDGES + EYES_SIZE, EYES_SIZE, WHITE);
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE, EYES_DISTANCE_EDGES + EYES_SIZE, EYES_SIZE / 3, eyesColor);
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE, EYES_DISTANCE_EDGES + EYES_SIZE, EYES_SIZE / 4, BLACK);
}

void eyeRightNeutral() {
  eyeLeftReset();
  tft.fillCircle(X_MAX - (EYES_DISTANCE_EDGES + EYES_SIZE), EYES_DISTANCE_EDGES + EYES_SIZE, EYES_SIZE, WHITE);
  tft.fillCircle(X_MAX - (EYES_DISTANCE_EDGES + EYES_SIZE), EYES_DISTANCE_EDGES + EYES_SIZE, EYES_SIZE / 3, eyesColor);
  tft.fillCircle(X_MAX - (EYES_DISTANCE_EDGES + EYES_SIZE), EYES_DISTANCE_EDGES + EYES_SIZE, EYES_SIZE / 4, BLACK);
}

void eyesNeutral() {
  eyeLeftNeutral();
  eyeRightNeutral();
}

void eyesNormal() {
}
void loop() {
  

}



/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

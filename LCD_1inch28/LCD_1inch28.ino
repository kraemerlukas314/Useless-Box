#include "Adafruit_GFX.h"
#include "Adafruit_GC9A01A.h"
#include "defines.h"
#define TFT_DC 7
#define TFT_CS 10

// Hardware SPI on Feather or other boards
Adafruit_GC9A01A tft(TFT_CS, TFT_DC);
//const int WHITE = 0xffffff;
//const int BLACK = 0x000000;
//const int BACKGROUND = BLACK;


int eyesColor = 0x0066ff;
int eyesColorSize = EYES_SIZE / 2;
int eyesPupilSize = EYES_SIZE / 2.8;
int mouthStatus = 0;
int eyeLeftStatus = 0;
int eyeRightStatus = 0;

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.fillScreen(BACKGROUND);
  eyesDrawStatus();
  mouthDrawStatus();
  pinMode(PIN_BTN, INPUT_PULLUP);
}

void loop() {
}

bool getButtonState() {
  digitalRead(PIN_BTN);
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
  tft.fillRoundRect(50, MOUTH_MID - (MOUTH_THICKNESS / 2), 140, MOUTH_THICKNESS, 30, WHITE);
}

void mouthPositive1() {
  tft.fillCircle(X_MAX / 2, Y_MAX * 0.542, X_MAX * 0.75, MOUTH_COLOR);
  tft.fillCircle(X_MAX / 2, Y_MAX * 0.375, X_MAX * 0.792, BACKGROUND);
}

void mouthPositive2() {
  tft.fillCircle(X_MAX / 2, Y_MAX * 0.625, X_MAX * 0.292, MOUTH_COLOR);
  tft.fillCircle(X_MAX / 2, Y_MAX / 2, X_MAX / 3, BACKGROUND);
}



void eyeLeftReset() {
  tft.fillRect(X_MIN, Y_MIN, X_MAX / 2, Y_MOUTH_START, BACKGROUND);
}

void eyeRightReset() {
  tft.fillRect(X_MAX / 2, Y_MIN, X_MAX / 2, Y_MOUTH_START, BACKGROUND);
}

void eyeLeftNeutral() {
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE, EYES_DISTANCE_EDGES + EYES_SIZE, EYES_SIZE, WHITE);
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE, EYES_DISTANCE_EDGES + EYES_SIZE, eyesColorSize, eyesColor);
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE, EYES_DISTANCE_EDGES + EYES_SIZE, eyesPupilSize, BLACK);
}

void eyeRightNeutral() {
  tft.fillCircle(X_MAX - (EYES_DISTANCE_EDGES + EYES_SIZE), EYES_DISTANCE_EDGES + EYES_SIZE, EYES_SIZE, WHITE);
  tft.fillCircle(X_MAX - (EYES_DISTANCE_EDGES + EYES_SIZE), EYES_DISTANCE_EDGES + EYES_SIZE, eyesColorSize, eyesColor);
  tft.fillCircle(X_MAX - (EYES_DISTANCE_EDGES + EYES_SIZE), EYES_DISTANCE_EDGES + EYES_SIZE, eyesPupilSize, BLACK);
}

void eyeLeftDrawStatus() {
  switch (eyeLeftStatus) {
    case (0): eyeLeftNeutral();
  }
}

void eyeRightDrawStatus() {
  switch (eyeRightStatus) {
    case (0): eyeRightNeutral();
  }
}

void eyesDrawStatus() {
  eyeRightReset();
  eyeLeftReset();
  eyeLeftDrawStatus();
  eyeRightDrawStatus();
}

void mouthDrawStatus(int aStatus) {
  mouthReset();
  switch (aStatus) {
    case (0): mouthNeutral();
    case (1): {
        mouthPositive1();
        eyesDrawStatus();
      }
    case (2): {
        mouthPositive2();
        eyesDrawStatus();
      }

  }
}

void mouthDrawStatus() {
  mouthDrawStatus(mouthStatus);
}







/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

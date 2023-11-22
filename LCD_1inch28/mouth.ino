#include "defines.h"
#include "eyes.ino"

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

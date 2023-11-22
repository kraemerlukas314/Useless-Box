#include "defines.h"

// Reset
void eyeLeftReset() {
  tft.fillRect(X_MIN, Y_MIN, X_MAX / 2, Y_MOUTH_START, BACKGROUND);
}

void eyeRightReset() {
  tft.fillRect(X_MAX / 2, Y_MIN, X_MAX / 2, Y_MOUTH_START, BACKGROUND);
}

// Setup
void eyesSetup() {
  tft.fillCircle(X_MAX - (EYES_DISTANCE_EDGES + EYES_SIZE), EYES_DISTANCE_EDGES + EYES_SIZE, EYES_SIZE, WHITE);
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE, EYES_DISTANCE_EDGES + EYES_SIZE, EYES_SIZE, WHITE);
}

// eye positions
// eyes middle
void eyeLeftMiddle() {
  eyeLeftDrawAt(0, 0);
}

void eyeRightMiddle() {
  eyeRightDrawAt(0, 0);
}

// draw status
void eyeLeftDrawStatus(int aStatus) {
  switch (aStatus) {
    case (0):
      eyeLeftMiddle();
  }
}

void eyeRightDrawStatus(int aStatus) {
  switch (aStatus) {
    case (0):
      eyeRightMiddle();
  }
}

void eyesDrawStatus(int aStatus) {
  eyesSetup();
  eyeLeftDrawStatus(aStatus);
  eyeRightDrawStatus(aStatus);
}

void eyesDrawStatus() {
  eyesSetup();
  eyeLeftDrawStatus(eyeLeftStatus);
  eyeRightDrawStatus(eyeRightStatus);
}

void eyeRightDrawAt(double x, double y) {
  tft.fillCircle(X_MAX - (EYES_DISTANCE_EDGES + EYES_SIZE) + (x * eyesColorSize), EYES_DISTANCE_EDGES + EYES_SIZE + (y * eyesColorSize), eyesColorSize, eyesColor);
  tft.fillCircle(X_MAX - (EYES_DISTANCE_EDGES + EYES_SIZE) + (x * eyesColorSize), EYES_DISTANCE_EDGES + EYES_SIZE + (y * eyesColorSize), eyesPupilSize, BLACK);
}

void eyeLeftDrawAt(double x, double y) {
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE + (x * eyesColorSize), EYES_DISTANCE_EDGES + EYES_SIZE + (y * eyesColorSize), eyesColorSize, eyesColor);
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE + (x * eyesColorSize), EYES_DISTANCE_EDGES + EYES_SIZE + (y * eyesColorSize), eyesPupilSize, BLACK);
}

void eyesDrawAt(double xl, double yl, double xr, double yr) {
  eyesSetup();
  eyeLeftDrawAt(xl, yl);
  eyeRightDrawAt(xr, yr);
}

// eyes special positions
// eyes look at switch

void eyesLookAtSwitch() {
  eyesDrawAt(0.8, -0.8, -0.8, -0.8);
}

// eyelids

void eyeLidLeftUp(double leftHeight, double rightHeight) {
  tft.fillTriangle(EYE_LEFT_MIDDLE_X, Y_MIN, X_MIN, EYES_DISTANCE_EDGES + leftHeight, EYE_RIGHT_MIDDLE_X, EYES_DISTANCE_EDGES + rightHeight, BACKGROUND);
}

void eyeLidRightUp(double leftHeight, double rightHeight) {
  tft.fillTriangle(EYE_RIGHT_MIDDLE_X, Y_MIN, X_MAX, EYES_DISTANCE_EDGES + rightHeight, EYE_RIGHT_MIDDLE_X - EYES_SIZE, EYES_DISTANCE_EDGES + leftHeight, BACKGROUND);
}

void eyeLidsUpDraw(double leftEyeLeftHeight, double leftEyeRightHeight, double rightEyeLeftHeight, double rightEyeRightHeight) {
  eyesDrawStatus();
  eyeLidLeftUp(leftEyeLeftHeight, leftEyeRightHeight);
  eyeLidRightUp(rightEyeLeftHeight, rightEyeRightHeight);
}

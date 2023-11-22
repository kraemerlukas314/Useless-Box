#include "defines.h"

void eyeLeftReset() {
  tft.fillRect(X_MIN, Y_MIN, X_MAX / 2, Y_MOUTH_START, BACKGROUND);
}

void eyeRightReset() {
  tft.fillRect(X_MAX / 2, Y_MIN, X_MAX / 2, Y_MOUTH_START, BACKGROUND);
}

void eyesSetup() {
  tft.fillCircle(X_MAX - (EYES_DISTANCE_EDGES + EYES_SIZE), EYES_DISTANCE_EDGES + EYES_SIZE, EYES_SIZE, WHITE);
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE, EYES_DISTANCE_EDGES + EYES_SIZE, EYES_SIZE, WHITE);
}

void eyeLeftNeutral() {
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE, EYES_DISTANCE_EDGES + EYES_SIZE, eyesColorSize, eyesColor);
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE, EYES_DISTANCE_EDGES + EYES_SIZE, eyesPupilSize, BLACK);
}

void eyeRightNeutral() {
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



void eyeRightLookAtSwitch() {
  tft.fillCircle(X_MAX - (EYES_DISTANCE_EDGES + EYES_SIZE), EYES_DISTANCE_EDGES, eyesColorSize, eyesColor);
  tft.fillCircle(X_MAX - (EYES_DISTANCE_EDGES + EYES_SIZE), EYES_DISTANCE_EDGES, eyesPupilSize, BLACK);

}

void eyeLeftLookAtSwitch() {
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE, EYES_DISTANCE_EDGES, eyesColorSize, eyesColor);
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE, EYES_DISTANCE_EDGES, eyesPupilSize, BLACK);
}

void eyesLookAtSwitch() {
  eyeLeftLookAtSwitch();
  eyeRightLookAtSwitch();
}

void eyesDrawStatus(int aStatus) {
  eyesSetup();
  eyeLeftDrawStatus();
  eyeRightDrawStatus();
}

void eyesDrawStatus() {
  eyeLeftDrawStatus();
}
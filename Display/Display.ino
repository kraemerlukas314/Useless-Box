#include "defines.h"


// Hardware SPI on Feather or other boards
// Adafruit_GC9A01A tft(TFT_CS, TFT_DC);
// const int WHITE = 0xffffff;
// const int BLACK = 0x000000;
// const int BACKGROUND = BLACK;

Adafruit_GC9A01A tft(TFT_CS, TFT_DC);

int eyesColor = 0x0066ff;
int eyesColorSize = EYES_SIZE / 2;
int eyesPupilSize = EYES_SIZE / 2.8;
int mouthStatus = 0;
int eyeLeftStatus = 0;
int eyeRightStatus = 0;

void setup() {
  Serial.begin(115200);
  tft.begin();
  pinMode(PIN_BTN, INPUT_PULLUP);
  displayClear();
  eyesDrawStatus();
  mouthDrawStatus();
}

void loop() {
}
bool getButtonState() {
  return digitalRead(PIN_BTN);
}

void displayClear() {
  // Clear Display (Set display to background color)
  tft.fillScreen(BACKGROUND);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

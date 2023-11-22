#include "defines.h"

// Hardware SPI on Feather or other boards
// Adafruit_GC9A01A tft(TFT_CS, TFT_DC);
// const int WHITE = 0xffffff;
// const int BLACK = 0x000000;
// const int BACKGROUND = BLACK;

void setup()
{
  Serial.begin(115200);
  tft.begin();
  tft.fillScreen(BACKGROUND);
  pinMode(PIN_BTN, INPUT_PULLUP);
}

void loop()
{
}

bool getButtonState()
{
  return digitalRead(PIN_BTN);
}

void displayClear()
{
  // Clear Display (Set display to background color)
  tft.fillScreen(BACKGROUND);
}



/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

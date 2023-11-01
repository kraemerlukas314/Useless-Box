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

void setup() {
  

  tft.begin();
  tft.fillScreen(BLACK);
  tft.fillCircle(120, 120, 100, WHITE);
  tft.fillRect(0, 0, 240, 120, BLACK);
  tft.fillCircle(120, 105, 90, BLACK);
  
}

void clearDisplay() {
  tft.fillScreen(BACKGROUND)
}

void smile1(bool clearDisplay) {
  if(clearDisplay) {
    clearDisplay()
  }

}
void loop() {
  smile1(true);
}



/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

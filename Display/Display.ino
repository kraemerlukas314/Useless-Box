#include "defines.h"
#include <EEPROM.h>



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
uint32_t totalButtonPresses;

void setup() {
  Serial.begin(115200);
  totalButtonPresses = EEPROM.read(0) | (EEPROM.read(1) << 8) | (EEPROM.read(2) << 16);  // get total button presses from EEPROM
  Serial.print("Total button presses read from EEPROM: ");
  Serial.println(totalButtonPresses);
  tft.begin();
  eyesDrawStatus();
  
  // pinMode(PIN_BTN, INPUT_PULLUP);
  // displayClear();
  // eyesDrawStatus();
  // mouthDrawStatus();
  // while (!getButtonState) {
  //   // ANZEIGE: Bitte Schalter umlegen
  // }
  // ANZEIGE: Insgesamt wurde der Schalter totalButtonPresses mal umgelegt
  // ANZEIGE: Kalibrierung
}


void loop() {
}

bool getButtonState() {
  return digitalRead(PIN_BTN);
}

// increments the total button counter and writes result to EEPROM
void incrementTotalButtonCounter() {
  ++totalButtonPresses;
  EEPROM.write(0, totalButtonPresses & 0xFF);          // Write the low byte
  EEPROM.write(1, (totalButtonPresses >> 8) & 0xFF);   // Write the middle byte
  EEPROM.write(2, (totalButtonPresses >> 16) & 0xFF);  // Write the high byte
}

void displayClear() {
  // Clear Display (Set display to background color)
  tft.fillScreen(BACKGROUND);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

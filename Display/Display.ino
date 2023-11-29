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
int eyesStatus = 0;
int eyeLidStatus1 = 5;
int eyeLidStatus2 = 5;
int eyeLidStatus3 = 5;
int eyeLidStatus4 = 5;
int happyness = random(1000);
uint32_t totalButtonPresses;

<<<<<<< HEAD
void setup() {
  Serial.begin(115200);
  pinMode(PIN_BTN, INPUT_PULLUP);
  totalButtonPresses = EEPROM.read(0) | (EEPROM.read(1) << 8) | (EEPROM.read(2) << 16);  // get total button presses from EEPROM
  Serial.print("Total button presses read from EEPROM: ");
  Serial.println(totalButtonPresses);
  tft.begin();
  displayClear();
  while (!getButtonState()) {
    // ANZEIGE: Bitte Schalter umlegen
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.setCursor(60, 50);
    tft.print("Bitte");
    tft.setCursor(28, 100);
    tft.print("Schalter");
    tft.setCursor(38, 150);
    tft.print("umlegen");
  }
  displayClear();
  while (getButtonState()) {
    // ANZEIGE: Kalibriere...
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(50, 50);
    tft.print("Kalibriere...");
    // ANZEIGE: wie oft wurde Schalter umgelegt?
    tft.setTextSize(2);
    tft.setCursor(10, 100);
    tft.print("Schaltercoutner:");
=======
void setup()
{
  // Serial.begin(115200);
  // pinMode(PIN_BTN, INPUT_PULLUP);
  // totalButtonPresses = EEPROM.read(0) | (EEPROM.read(1) << 8) | (EEPROM.read(2) << 16);  // get total button presses from EEPROM
  // Serial.print("Total button presses read from EEPROM: ");
  // Serial.println(totalButtonPresses);
  tft.begin();
  pinMode(PIN_BTN, INPUT_PULLUP);
  // displayClear();
  //  while (!getButtonState) {
  //    // ANZEIGE: Bitte Schalter umlegen
  //  }
  //  displayClear();
  //  while (getButtonState) {
  //    Serial.println("IN WHILE");
  //    pinMode(13, OUTPUT);
  //    digitalWrite(13, HIGH);
  //    delay(5000);
  //    // ANZEIGE: Bitte Schalter umlegen
  //    tft.setTextColor(WHITE);
>>>>>>> 52ea7686b798f091904cba4317afcb3129054f34

    tft.setTextSize(5);
    tft.setCursor(30, 160);

<<<<<<< HEAD
    // falls Zähler kleiner 99999 ist, werden die Stellen davor mit Nullen aufgefüllt
    String formattedString = String(totalButtonPresses, DEC);
    formattedString = formattedString.length() < 5 ? "00000" + formattedString : formattedString;
    tft.print(formattedString);
  }
=======
  //   // Print "Hello, World!" at coordinates (10, 10)
  //   tft.setCursor(10, 10);
  //   tft.print(totalButtonPresses);
  // }
  // ANZEIGE: Insgesamt wurde der Schalter totalButtonPresses mal umgelegt
  // ANZEIGE: Kalibrierung
  Serial.begin(115200);
  Serial.println(EYE_LEFT_MIDDLE_X);
  Serial.println(EYE_RIGHT_MIDDLE_X);
>>>>>>> 52ea7686b798f091904cba4317afcb3129054f34
  displayClear();
  mouthDrawStatus();
  eyesDrawStatus();
}

void loop()
{
  if (!getButtonState && happyness < 5000)
  {
    happyness++;
  }
  Serial.println(happyness);
  delay(1000);
}

bool getButtonState()
{
  return digitalRead(PIN_BTN);
}

// increments the total button counter and writes result to EEPROM
void incrementTotalButtonCounter()
{
  ++totalButtonPresses;
  EEPROM.write(0, totalButtonPresses & 0xFF);         // Write the low byte
  EEPROM.write(1, (totalButtonPresses >> 8) & 0xFF);  // Write the middle byte
  EEPROM.write(2, (totalButtonPresses >> 16) & 0xFF); // Write the high byte
}

void displayClear()
{
  // Clear Display (Set display to background color)
  tft.fillScreen(BACKGROUND);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

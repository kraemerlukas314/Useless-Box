#include "defines.h"

// Hardware SPI on Feather or other boards
// Adafruit_GC9A01A tft(TFT_CS, TFT_DC);
// const int WHITE = 0xffffff;
// const int BLACK = 0x000000;
// const int BACKGROUND = BLACK;

Adafruit_GC9A01A tft(TFT_CS, TFT_DC);

Servo servo;

int eyesColor = 0x0066ff;
int eyesColorSize = EYES_SIZE / 2;
int eyesPupilSize = EYES_SIZE / 2.8;
int mouthStatus = 0;
int mouthStatusOld = -1;
int eyesStatus = 0;
int eyesStatusOld = -10000;
double eyeLidsStatus[4] = {3, 3, 3, 3};
double eyeLidsStatusOld[4] = {-1, -1, -1, -1};
long timeLast = millis();
int happiness = random(100);
int blinker = 0;
int blinkTimer = random(3, 10);
byte servoPosSwitch = 0;
byte servoPosHome = 0;
byte servoPosCurrent = 0;
uint32_t totalButtonPresses = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(PIN_BTN, INPUT_PULLUP);
  servo.attach(PIN_SERVO);
  servo.write(180);
  servoPosCurrent = 180;
  delay(1000);
  totalButtonPresses = EEPROMReadlong(0);
  Serial.print("Total button presses read from EEPROM: ");
  Serial.println(totalButtonPresses);
  tft.begin();
  displayClear();
  // falls Zähler kleiner 99999 ist, werden die Stellen davor mit Nullen aufgefüllt
  String formattedString = String(totalButtonPresses);
  while (formattedString.length() < 6)
  {
    formattedString = "0" + formattedString;
  }
  tft.setTextSize(6);
  tft.setCursor(16, 95);
  tft.print(formattedString);
  while (!getButtonState())
  {
  }
  // Calibrate servo position
  while (getButtonState() && servoPosCurrent > 0)
  {
    servoPosCurrent = servoPosCurrent - 1;
    servo.write(servoPosCurrent);
    Serial.println(servoPosCurrent);
    delay(15);
  }
  Serial.print("Final Servo pos: ");
  Serial.println(servoPosCurrent);
  displayClear();
  mouthDrawStatus();
  eyesDrawStatus();
}

void loop()
{
  while (millis() - timeLast < intervall)
  {
    delay(1);
  }
  timeLast = millis();

  // increase happiness
  if (!getButtonState() && happiness < 500)
  {
    happiness += happinessAdder;
  }

  // Blinking
  if (blinker <= 0)
  {
    eyesBlink();
    blinker = blinkTimer;
  }
  else
  {
    --blinker;
  }

  // button has been pressed
  if (getButtonState())
  {

    useSwitch();
  }

  // Draw / update everything
  Serial.println(mouthStatus);
  mouthDrawStatus();
  eyesDrawStatus();
  eyeLidsUpDrawStatus();
  Serial.print("Happiness: ");
  Serial.println(happiness);
}

bool getButtonState()
{
  static int lastButtonState = HIGH, buttonState;
  static unsigned long lastDebounceTime;

  buttonState = digitalRead(PIN_BTN);
  if (buttonState != lastButtonState)
    lastDebounceTime = millis();

  return (millis() - lastDebounceTime) > 50 ? lastButtonState = buttonState : !lastButtonState;
}

// increments the total button counter and writes result to EEPROM
void incrementTotalButtonCounter()
{
  ++totalButtonPresses;
  EEPROMWritelong(0, totalButtonPresses);
  // EEPROMWritelong(0, 0);
}

long EEPROMReadlong(long address)
{
  long four = EEPROM.read(address);
  long three = EEPROM.read(address + 1);
  long two = EEPROM.read(address + 2);
  long one = EEPROM.read(address + 3);

  return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
}

void EEPROMWritelong(int address, long value)
{
  byte four = (value & 0xFF);
  byte three = ((value >> 8) & 0xFF);
  byte two = ((value >> 16) & 0xFF);
  byte one = ((value >> 24) & 0xFF);

  EEPROM.write(address, four);
  EEPROM.write(address + 1, three);
  EEPROM.write(address + 2, two);
  EEPROM.write(address + 3, one);
}

void displayClear()
{
  // Clear Display (Set display to background color)
  tft.fillScreen(BACKGROUND);
  Serial.println("Display cleared");
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

#include "defines.h"

Adafruit_GC9A01A tft(TFT_CS, TFT_DC);

Servo servo;

int eyesColor = 0x0066ff;
int eyesColorSize = EYES_SIZE / 2;
int eyesPupilSize = EYES_SIZE / 2.8;
int mouthStatus = 0;
int eyesStatus = 0;
double eyeLidsStatus[4] = {3, 3, 3, 3};
long timeLast = millis();
int happiness = random(1000);
int blinker = 0;
int blinkTimer = random(3, 10);
byte servoPosSwitch = 0;
byte servoPosHome = 0;
byte servoPosCurrent = 0;
uint32_t totalButtonPresses = 0;
byte SERVO_TOGGLE_POS; // is a variable but is only changed once
byte SERVO_HOME_POS;
const byte SERVO_DELTA_TOOGLE_HOME = 70; // difference between toogle pos and home pos

void setup()
{
  Serial.begin(115200);
  pinMode(PIN_BTN, INPUT_PULLUP);
  servo.attach(PIN_SERVO);
  totalButtonPresses = EEPROMReadlong();
  Serial.print("Total button presses read from EEPROM: ");
  Serial.println(totalButtonPresses);
  tft.begin();
  displayClear();
  Serial.println("Before");
  incrementTotalButtonCounter();
  incrementTotalButtonCounter();
  Serial.println("After");
  delay(1000);
  exit(0);

  // if counter is < 999999 -> fill empty digits with zeros so string always has length 6
  String formattedString = String(totalButtonPresses);
  while (formattedString.length() < 6)
  {
    formattedString = "0" + formattedString;
  }
  tft.setTextSize(6);
  tft.setCursor(16, 95);
  tft.print(formattedString);

  // wait for user to toggle button
  while (!getButtonState())
  {
  }
  // Calibrate servo position
  servoPosCurrent = servo.read();
  while (getButtonState() && servoPosCurrent > 0)
  {
    servoPosCurrent = servoPosCurrent - 1;
    servo.write(servoPosCurrent);
    Serial.println(servoPosCurrent);
    delay(15);
  }
  Serial.print("Final Servo pos: ");
  Serial.println(servoPosCurrent);
  SERVO_TOGGLE_POS = servoPosCurrent;
  SERVO_HOME_POS = SERVO_TOGGLE_POS - SERVO_DELTA_TOOGLE_HOME;
  servo.write(SERVO_HOME_POS);

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
  if (!getButtonState() && happiness < 5000)
  {
    happiness++;
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
    happiness -= dissatisfaction;
    useSwitch();
  }

  // Draw / update everything
  mouthDrawStatus();
  eyesDrawStatus();
  eyeLidsUpDrawStatus();
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
  Serial.print("Total button presses: ");
  Serial.println(totalButtonPresses);
  EEPROMWritelong(totalButtonPresses);
}

long EEPROMReadlong()
{
  long four = 0;
  for (int i = 0; i < 16; ++i) {
    if (EEPROM.read(i) > 0) four = EEPROM.read(i);
  }
  long three = EEPROM.read(16);
  long two = EEPROM.read(17);
  long one = EEPROM.read(18);
  Serial.println("When reading from eeprom, this is the result:");
  Serial.print("Four: ");
  Serial.print(four);
  Serial.print(" Three: ");
  Serial.print(three);
  Serial.print(" two: ");
  Serial.print(two);
  Serial.print(" One: ");
  Serial.println(one);

  return ((one << 0) & 0xFF) + ((two << 8) & 0xFFFF) + ((three << 16) & 0xFFFFFF) + ((four << 24) & 0xFFFFFFFF);
}

void EEPROMWritelong(long value)
{
  byte four = (value & 0xFF);
  byte three = ((value >> 8) & 0xFF);
  byte two = ((value >> 16) & 0xFF);
  byte one = ((value >> 24) & 0xFF);

  // to avoid eeprom wear down, least significant byte (that changes very frequently)
  // is written somewhere between address 0 and 15

  // determine address from 0 - 15 with highest value in it
  // this must be the address that was written to last
  byte highest_val = 0;
  byte highest_val_address = 0;
  for (int i = 0; i < 16; ++i) {
    byte current_val = EEPROM.read(i);
    if (current_val > highest_val) highest_val = current_val;
    highest_val_address = i;
  }
  if (highest_val == 0) highest_val_address = millis() % 16;
  Serial.print("Highest val address: ");
  Serial.print(highest_val_address);
  Serial.print("  value before inc: ");
  Serial.print(EEPROM.read(highest_val_address));
  Serial.print(" Byte to write : ");
  Serial.println(four);

  EEPROM.write(highest_val_address, four);
  EEPROM.write(16, three);
  EEPROM.write(17, two);
  EEPROM.write(18, one);
}

void displayClear()
{
  // Clear Display (Set display to background color)
  tft.fillScreen(BACKGROUND);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

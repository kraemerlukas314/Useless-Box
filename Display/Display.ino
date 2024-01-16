#include "defines.h"

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
int blinkTimer = 150;
byte servoPosSwitch = 0;
byte servoPosHome = 0;
byte servoPosCurrent = 0;
byte SERVO_TOGGLE_POS; // is a variable but is only changed once
byte SERVO_HOME_POS;
const byte SERVO_DELTA_TOOGLE_HOME = 120; // difference between toogle pos and home pos
int activeAnimation = -1;
int eyeLeftActualPositionX = 0;
int eyeLeftActualPositionY = 0;
int eyeRightActualPositionX = 0;
int eyeRightActualPositionY = 0;
int eyeLidActualPositionLL = 0;
int eyeLidActualPositionLR = 0;
int eyeLidActualPositionRL = 0;
int eyeLidActualPositionRR = 0;
int mouthActualStatus = -100000;
int eyesActualColor = 0;
bool buttonPushedByArm = true;
int animationStep = 0;
bool animationFinished = true;
bool armAnimationInited = false;
int armAnimationDeg = 0;

void setup()
{
  randomSeed(analogRead(0));
  Serial.begin(115200);
  Serial.println("---- NEW START ----");
  tft.begin();
  pinMode(PIN_BTN, INPUT_PULLUP);
  servo.attach(PIN_SERVO);
  servo.write(180);
  servo.detach();
  displayClear();

  // if counter is < 999999 -> fill empty digits with zeros so string always has length 6
  String formattedString = String(getButtonPresses());
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
  servo.attach(PIN_SERVO);
  // Calibrate servo position
  servoPosCurrent = servo.read();
  while (getButtonState() && servoPosCurrent > 0)
  {
    servoPosCurrent = servoPosCurrent - 1;
    servo.write(servoPosCurrent);
    delay(15);
  }
  SERVO_TOGGLE_POS = servoPosCurrent + 5;
  SERVO_HOME_POS = 180; // SERVO_TOGGLE_POS + SERVO_DELTA_TOOGLE_HOME;
  servo.write(SERVO_HOME_POS);
  displayClear();
  eyesRedraw();
  eyeLidsRedraw();
  mouthDrawStatus(0);
}

void loop()
{
  while (millis() - timeLast < intervall)
  {
  }
  timeLast = millis();

  if (!getButtonState() && activeAnimation == -1)
  {
    if (happiness < MAX_HAPPINESS)
    {
      happiness += happinessAdder;
    }
    handleStandardExpression();
  }
  else if (!getButtonState() && activeAnimation != -1 && !buttonPushedByArm)
  {
    Serial.println("Button pressed while playing animation. Cancelling animation...");
    armAnimationInited = false;
    resetAnimation();
    activeAnimation = -1;
    animationStep = 0;
    if (happiness + happinessAdder * 10 <= MAX_HAPPINESS)
    {
      happiness += happinessAdder * 10;
    }
    incrementButtonPresses();
  }
  else if (getButtonState() && activeAnimation == -1)
  {
    if (happiness - dissatisfaction >= MIN_HAPPINESS)
    {
      happiness -= dissatisfaction;
    }
    activeAnimation = random(1, maxArmAnimations + 1);
    animationStep = 0;
    buttonPushedByArm = false;

    Serial.println("Starting new animation: " + String(activeAnimation));
  }

  if (activeAnimation != -1)
  {
    handleStandardExpression();
    handleButtonPressed();
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
}

bool getButtonState()
{
  static int lastButtonState = HIGH, buttonState;
  static unsigned long lastDebounceTime;

  buttonState = digitalRead(PIN_BTN);
  if (buttonState != lastButtonState)
    lastDebounceTime = millis();

  return !((millis() - lastDebounceTime) > 50 ? lastButtonState = buttonState : !lastButtonState);
}

// increments the total button counter and writes result to EEPROM
void incrementButtonPresses()
{
  EEPROMWritelong(getButtonPresses() + 1);
}

uint32_t getButtonPresses()
{
  // TODO: read from eeprom:
  byte one = 0;
  for (int i = 0; i < 16; ++i)
  {
    if (EEPROM.read(i) > 0)
      one = EEPROM.read(i);
  }
  byte two = EEPROM.read(16);
  byte three = EEPROM.read(17);
  byte four = EEPROM.read(18);
  return (uint32_t)four << 24 | (uint32_t)three << 16 | (uint32_t)two << 8 | (uint32_t)one;
}

void EEPROMWritelong(long value)
{
  byte one = (value & 0xFF);
  byte two = ((value >> 8) & 0xFF);
  byte three = ((value >> 16) & 0xFF);
  byte four = ((value >> 24) & 0xFF);

  // to avoid eeprom wear down, least significant byte (that changes very frequently)
  // is written somewhere between address 0 and 15
  byte address_to_write = 0;
  for (int i = 0; i < 16; ++i)
  {
    if (EEPROM.read(i) > 0)
      address_to_write = i;
  }
  // there's 0 in every address, so choose random between 0 and 15
  if (address_to_write == 0)
  {
    address_to_write = millis() % 16;
  }
  EEPROM.write(address_to_write, one);
  EEPROM.write(16, two);
  EEPROM.write(17, three);
  EEPROM.write(18, four);
}

void displayClear()
{
  // Clear Display (Set display to background color)
  tft.fillScreen(BACKGROUND);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

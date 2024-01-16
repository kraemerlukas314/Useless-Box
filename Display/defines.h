// include libraries
#include "Adafruit_GFX.h"
#include "Adafruit_GC9A01A.h"
#include <EEPROM.h>
#include <Servo.h>

// pin defines
#define PIN_BTN 2
#define PIN_SERVO A2

#define TFT_DC 7
#define TFT_CS 10

// display defines
#define WHITE 0xffffff
#define BLACK 0x000000
#define BACKGROUND BLACK
#define MOUTH_COLOR WHITE
#define X_MIN 0
#define Y_MIN 0
#define X_MAX 240
#define Y_MAX 240
#define Y_MOUTH_START Y_MAX / 2.2
#define MOUTH_THICKNESS 20
#define MOUTH_MID Y_MAX * 0.625
#define EYES_DISTANCE_EDGES 40
#define EYES_SIZE 30
#define EYE_LEFT_MIDDLE_X EYES_DISTANCE_EDGES + EYES_SIZE
#define EYE_LEFT_MIDDLE_Y EYES_DISTANCE_EDGES + EYES_SIZE
#define EYE_RIGHT_MIDDLE_X (X_MAX - (EYES_DISTANCE_EDGES + EYES_SIZE))
#define EYE_RIGHT_MIDDLE_Y EYES_DISTANCE_EDGES + EYES_SIZE
#define intervall 10
#define dissatisfaction 400
#define eyeLidsStandard \
    {                   \
        3, 3, 3, 3      \
    } // kommentar
#define happinessAdder 2
#define MIN_HAPPINESS -2000
#define MAX_HAPPINESS 1000
#define maxArmAnimations 4
#define MOUTH_POSITION_BOTTOM 30
#include "defines.h"

// Left eye:
//  Reset
void eyeLeftReset()
{
  tft.fillRect(X_MIN, Y_MIN, X_MAX / 2, Y_MOUTH_START, BACKGROUND);
}

void eyeLeftDrawAt(double x, double y)
{
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE + (x * eyesColorSize), EYES_DISTANCE_EDGES + EYES_SIZE + (y * eyesColorSize), eyesColorSize, eyesColor);
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE + (x * eyesColorSize), EYES_DISTANCE_EDGES + EYES_SIZE + (y * eyesColorSize), eyesPupilSize, BLACK);
}

// right eye:
//  Reset
void eyeRightReset()
{
  tft.fillRect(X_MAX / 2, Y_MIN, X_MAX / 2, Y_MOUTH_START, BACKGROUND);
}

void eyeRightDrawAt(double x, double y)
{
  tft.fillCircle(X_MAX - (EYES_DISTANCE_EDGES + EYES_SIZE) + (x * eyesColorSize), EYES_DISTANCE_EDGES + EYES_SIZE + (y * eyesColorSize), eyesColorSize, eyesColor);
  tft.fillCircle(X_MAX - (EYES_DISTANCE_EDGES + EYES_SIZE) + (x * eyesColorSize), EYES_DISTANCE_EDGES + EYES_SIZE + (y * eyesColorSize), eyesPupilSize, BLACK);
}

// both eyes:
// Setup
void eyesSetup()
{
  tft.fillCircle(X_MAX - (EYES_DISTANCE_EDGES + EYES_SIZE), EYES_DISTANCE_EDGES + EYES_SIZE, EYES_SIZE, WHITE);
  tft.fillCircle(EYES_DISTANCE_EDGES + EYES_SIZE, EYES_DISTANCE_EDGES + EYES_SIZE, EYES_SIZE, WHITE);
}

void setEyesColor(int newColor)
{
  if (newColor != eyesColor)
  {
    eyesColor = newColor;
  }
}

void eyesDrawAt(double xl, double yl, double xr, double yr, bool force, bool fromEyeLids)
{
  if (force || eyesColor != eyesActualColor || xl != eyeLeftActualPositionX || yl != eyeLeftActualPositionY || xr != eyeRightActualPositionX || yr != eyeRightActualPositionY)
  {
    eyesSetup();
    eyeLeftDrawAt(xl, yl);
    eyeRightDrawAt(xr, yr);
    if (!fromEyeLids)
    {
      eyeLidsRedraw(true);
    }
    eyeLeftActualPositionX = xl;
    eyeLeftActualPositionY = yl;
    eyeRightActualPositionX = xr;
    eyeRightActualPositionY = yr;
    eyesActualColor = eyesColor;
  }
}

void eyesDrawAt(double xl, double yl, double xr, double yr)
{
  eyesDrawAt(xl, yl, xr, yr, false, false);
}

void eyesRedraw(bool fromEyeLids)
{
  eyesDrawAt(eyeLeftActualPositionX, eyeLeftActualPositionY, eyeRightActualPositionX, eyeRightActualPositionY, true, fromEyeLids);
}

void eyesRedraw()
{
  eyesDrawAt(eyeLeftActualPositionX, eyeLeftActualPositionY, eyeRightActualPositionX, eyeRightActualPositionY, true, false);
}

// eyelids
// left
void eyeLidLeft(double leftHeight, double rightHeight)
{
  tft.fillTriangle(EYE_LEFT_MIDDLE_X, Y_MIN, X_MIN, EYES_DISTANCE_EDGES + leftHeight, EYE_RIGHT_MIDDLE_X - EYES_SIZE, EYES_DISTANCE_EDGES + rightHeight, BACKGROUND);
}

// right
void eyeLidRight(double leftHeight, double rightHeight)
{
  tft.fillTriangle(EYE_RIGHT_MIDDLE_X, Y_MIN, X_MAX, EYES_DISTANCE_EDGES + rightHeight, EYE_LEFT_MIDDLE_X + EYES_SIZE, EYES_DISTANCE_EDGES + leftHeight, BACKGROUND);
}

// both

void eyeLidsDrawAt(double leftEyeLeftHeight, double leftEyeRightHeight, double rightEyeLeftHeight, double rightEyeRightHeight, bool force, bool fromEyes)
{
  if (force || leftEyeLeftHeight != eyeLidActualPositionLL || leftEyeRightHeight != eyeLidActualPositionLR || rightEyeLeftHeight != eyeLidActualPositionRL || rightEyeRightHeight != eyeLidActualPositionRR)
  {
    if (!fromEyes && (leftEyeLeftHeight < eyeLidActualPositionLL || leftEyeRightHeight < eyeLidActualPositionLR || rightEyeLeftHeight < eyeLidActualPositionRL || rightEyeRightHeight < eyeLidActualPositionRR))
    {
      eyesRedraw(true);
    }
    eyeLidLeft(leftEyeLeftHeight, leftEyeRightHeight);
    eyeLidRight(rightEyeLeftHeight, rightEyeRightHeight);

    eyeLidActualPositionLL = leftEyeLeftHeight;
    eyeLidActualPositionLR = leftEyeRightHeight;
    eyeLidActualPositionRL = rightEyeLeftHeight;
    eyeLidActualPositionRR = rightEyeRightHeight;
  }
}

void eyeLidsRedraw(bool fromEyes)
{
  eyeLidsDrawAt(eyeLidActualPositionLL, eyeLidActualPositionLR, eyeLidActualPositionRL, eyeLidActualPositionRR, true, fromEyes);
}

void eyeLidsRedraw()
{
  eyeLidsRedraw(false);
}

void eyeLidsDrawAt(double leftEyeLeftHeight, double leftEyeRightHeight, double rightEyeLeftHeight, double rightEyeRightHeight)
{
  eyeLidsDrawAt(leftEyeLeftHeight, leftEyeRightHeight, rightEyeLeftHeight, rightEyeRightHeight, false, false);
}

void eyesBlink()
{
  eyeLidLeft(70, 70);
  eyeLidRight(70, 70);
  delay(100);
  eyesRedraw();
}

// #include "defines.h"

// // eye positions
// // eyes middle
// void eyeLeftMiddle()
// {
//   eyeLeftDrawAt(0, 0);
// }

// void eyeRightMiddle()
// {
//   eyeRightDrawAt(0, 0);
// }

// // draw status

// void eyesDrawStatus(int aStatus, int *oldStatus, bool force)
// {

//   if (aStatus != *oldStatus || force)
//   {

//     switch (aStatus)
//     {
//     case (0):
//     {
//       eyesDrawAt(0, 0, 0, 0);
//       break;
//     }
//     case (500):
//     {
//       // look at switch
//       eyesDrawAt(0.8, -0.8, -0.8, -0.8);
//       break;
//     }
//     default:
//     {
//       eyesDrawStatus(0);
//       break;
//     }
//     }
//     *oldStatus = aStatus;
//   }
// }

// void eyesDrawStatus(int aStatus)
// {
//   eyesDrawStatus(aStatus, &eyesStatusOld, false);
// }

// void eyesDrawStatus()
// {
//   eyesDrawStatus(eyesStatus, &eyesStatusOld, false);
// }

// void eyesDrawStatus(bool force)
// {
//   eyesDrawStatus(eyesStatus, &eyesStatusOld, force);
// }

// // eyelids

// void eyeLidsUpDraw(double leftEyeLeftHeight, double leftEyeRightHeight, double rightEyeLeftHeight, double rightEyeRightHeight)
// {
//   eyeLidLeftUp(leftEyeLeftHeight, leftEyeRightHeight);
//   eyeLidRightUp(rightEyeLeftHeight, rightEyeRightHeight);
// }

// void eyeLidsUpDrawStatus(bool force)
// {

//   if (force || (eyeLidsStatus[0] != eyeLidsStatusOld[0]) || (eyeLidsStatus[1] != eyeLidsStatusOld[1]) || (eyeLidsStatus[2] != eyeLidsStatusOld[2]) || (eyeLidsStatus[3] != eyeLidsStatusOld[3]))
//   {
//     eyeLidsUpDraw(eyeLidsStatus[0], eyeLidsStatus[1], eyeLidsStatus[2], eyeLidsStatus[3]);
//     eyeLidsStatusOld[0] = eyeLidsStatus[0];
//     eyeLidsStatusOld[1] = eyeLidsStatus[1];
//     eyeLidsStatusOld[2] = eyeLidsStatus[2];
//     eyeLidsStatusOld[3] = eyeLidsStatus[3];
//   }
// }

// void eyeLidsUpDrawStatus()
// {
//   eyeLidsUpDrawStatus(false);
// }

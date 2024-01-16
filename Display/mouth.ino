#include "defines.h"

void mouthReset()
{
  // Draw a Rectangle from start of mouth to end of display
  tft.fillRect(X_MIN, Y_MOUTH_START, X_MAX, Y_MAX - Y_MOUTH_START, BACKGROUND);
}

void mouthDrawStatus(int status)
{
  if (status != mouthActualStatus)
  {
    mouthActualStatus = status;
    switch (status)
    {
    case -10:
      mouthDraw(90, -8, -4, true);
      break;
    case -8:
      mouthDraw(80, -8, -4, true);
      break;

    case -6:
      mouthDraw(75, -7, -4, true);
      break;

    case -4:
      mouthDraw(70, -7, -4, true);
      break;

    case -2:
      mouthDraw(60, -6, -4, true);
      break;

    case 0:
      mouthDraw(50, 8, -2, true);
      break;

    case 2:
      mouthDraw(60, 8, -2, true);
      break;

    case 4:
      mouthDraw(65, 8, -2, true);
      break;

    case 6:
      mouthDraw(70, 8, -2, true);
      break;

    case 8:
      mouthDraw(80, 8, -2, true);
      break;

    default:
      break;
    }
  }
}

void mouthDraw(int rad, int offset, int thickness, bool redrawEyes)
{
  mouthReset();
  int posY = Y_MAX - MOUTH_POSITION_BOTTOM - rad;
  if (offset < 0)
  {
    posY = Y_MAX / 2 + MOUTH_POSITION_BOTTOM + rad;
  }
  tft.fillCircle(X_MAX / 2, posY, rad, MOUTH_COLOR);
  tft.fillCircle(X_MAX / 2, posY - offset, rad - thickness, BACKGROUND);

  if (redrawEyes)
  {
    eyesRedraw();
  }
}

void mouthPositive2()
{
  tft.fillCircle(X_MAX / 2, Y_MAX * 0.625 - 20, X_MAX * 0.292, MOUTH_COLOR);
  tft.fillCircle(X_MAX / 2, Y_MAX / 2 - 20, X_MAX / 3, BACKGROUND);
  eyesRedraw();
}

// void mouthDrawStatus(int aStatus, int *oldStatus)
// {
//   if (aStatus != *oldStatus)
//   {
//     mouthReset();
//     switch (aStatus)
//     {
//     case (0):
//       mouthNeutral();
//       break;
//     case (1):
//     {
//       mouthPositive1();
//       eyesDrawStatus();
//       break;
//     }
//     case (2):
//     {
//       mouthPositive2();
//       eyesDrawStatus();
//       break;
//     }
//     }
//     *oldStatus = aStatus;
//   }
// }

// void mouthDrawStatus()
// {
//   mouthDrawStatus(mouthStatus, &mouthStatusOld);
// }

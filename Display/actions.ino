#include "defines.h"

void refreshEmotions()
{
    if (happiness >= 0 && happiness <= 100)
    {
        mouthStatus = 0;
        eyesStatus = 0;
        eyeLidsStatus[0] = 3;
        eyeLidsStatus[1] = 3;
        eyeLidsStatus[2] = 3;
        eyeLidsStatus[3] = 3;
    }
    else if (happiness > 100 && happiness <= 200)
    {
        mouthStatus = 1;
        eyesStatus = 0;
        eyeLidsStatus[0] = 3;
        eyeLidsStatus[1] = 3;
        eyeLidsStatus[2] = 3;
        eyeLidsStatus[3] = 3;
    }
    else if (happiness > 200 && happiness <= 300)
    {
        mouthStatus = 2;
        eyesStatus = 0;
        eyeLidsStatus[0] = 5;
        eyeLidsStatus[1] = 3;
        eyeLidsStatus[2] = 3;
        eyeLidsStatus[3] = 5;
    }
}

void handleButtonPressed()
{
    switch (activeAnimation)
    {
    case 0:
        resetAnimation();
        break;
    case 1:
        animation1();
        break;

    case 2:
        animation2();
        break;

    default:
        break;
    }
}

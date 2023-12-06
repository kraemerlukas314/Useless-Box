#include "defines.h"

void useSwitch()
{
    if (happiness >= 0 && happiness <= 100)
    {
        mouthStatus = 0;
        eyesStatus = 0;
        eyeLidsStatus = eyeLidsStandard;
    }
    else if (happiness > 100 && happiness <= 200)
    {
        mouthStatus = 1;
        eyesStatus = 0;
        eyeLidsStatus = eyeLidsStandard;
    }
    else if (happiness > 200 && happiness <= 300)
    {
        mouthStatus = 2;
        eyesStatus = 0;
        eyeLidsStatus = {5, 3, 3, 5};
    }
}
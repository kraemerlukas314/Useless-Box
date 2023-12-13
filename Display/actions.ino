#include "defines.h"

void useSwitch()
{
    happiness -= dissatisfaction;
    Serial.print("happiness2: ");
    Serial.println(happiness);
    if (happiness >= 0 && happiness <= 100)
    {
        Serial.println("happiness > 0");
        mouthStatus = 0;
        eyesStatus = 0;
        eyeLidsStatus[0] = 3;
        eyeLidsStatus[1] = 3;
        eyeLidsStatus[2] = 3;
        eyeLidsStatus[3] = 3;
    }
    else if (happiness > 100 && happiness <= 200)
    {
        Serial.println("happiness > 100");
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
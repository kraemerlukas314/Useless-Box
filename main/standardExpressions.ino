#include "defines.h"

void handleStandardExpression()
{
    if (happiness >= -1000 && happiness < -800)
    {

        eyeLidsDrawAt(5, 35, 35, 5);
        setEyesColor(0xF800);
        mouthDrawStatus(-10);
    }
    else if (happiness >= -800 && happiness < -600)
    {
        eyeLidsDrawAt(5, 25, 25, 5);
        mouthDrawStatus(-8);
        setEyesColor(0xD02D);
    }
    else if (happiness >= -600 && happiness < -400)
    {
        eyeLidsDrawAt(5, 20, 20, 5);
        mouthDrawStatus(-6);
        setEyesColor(0xD0B1);
    }
    else if (happiness >= -400 && happiness < -200)
    {
        eyeLidsDrawAt(5, 15, 15, 5);
        mouthDrawStatus(-4);
        setEyesColor(0xB0BA);
    }
    else if (happiness >= -200 && happiness < 0)
    {
        eyeLidsDrawAt(5, 10, 10, 5);
        mouthDrawStatus(-2);
        setEyesColor(0x60BA);
    }
    else if (happiness >= 0 && happiness < 200)
    {
        eyeLidsDrawAt(3, 3, 3, 3);
        mouthDrawStatus(0);
        setEyesColor(0x09FA);
    }
    else if (happiness >= 200 && happiness < 400)
    {
        mouthDrawStatus(2);
        setEyesColor(0x15B9);
    }
    else if (happiness >= 400 && happiness < 600)
    {
        mouthDrawStatus(4);
        setEyesColor(0x25CA);
    }
    else if (happiness >= 600 && happiness < 800)
    {
        mouthDrawStatus(6);
        setEyesColor(0x15A7);
    }
    else if (happiness >= 800 && happiness < 1000)
    {
        mouthDrawStatus(8);
        setEyesColor(0x1CE0);
    }
    if (happiness > 0)
    {
        if (tiredness >= 1000 && tiredness < 2000)
        {
            eyeLidsDrawAt(10, 10, 10, 10);
        }
        else if (tiredness >= 2000 && tiredness < 3000)
        {
            eyeLidsDrawAt(20, 20, 20, 20);
        }
        else if (tiredness >= 3000 && tiredness < 4000)
        {
            eyeLidsDrawAt(50, 50, 50, 50);
        }
        else if (tiredness >= 4000 && tiredness < 5000)
        {
            eyeLidsDrawAt(70, 70, 70, 70);
            sleeping = true;
        }
    }
}
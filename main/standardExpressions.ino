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
        eyeLidsDrawAt(3, 3, 3, 3);
        mouthDrawStatus(2);
        setEyesColor(0x15B9);
    }
    else if (happiness >= 400 && happiness < 600)
    {
        eyeLidsDrawAt(3, 3, 3, 3);
        mouthDrawStatus(4);
        setEyesColor(0x25CA);
    }
    else if (happiness >= 600 && happiness < 800)
    {
        eyeLidsDrawAt(3, 3, 3, 3);
        mouthDrawStatus(6);
        setEyesColor(0x15A7);
    }
    else if (happiness >= 800 && happiness < 1000)
    {
        eyeLidsDrawAt(3, 3, 3, 3);
        mouthDrawStatus(8);
        setEyesColor(0x1CE0);
    }
}
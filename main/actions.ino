#include "defines.h"

void handleButtonPressed()
{
    switch (activeAnimation)
    {
    case 1:
        animation1();
        break;

    case 2:
        animation2();
        break;

    case 3:
        animation3();
        break;

    case 4:
        animation4();
        break;

    case 5:
        animation5();
        break;

    default:
        break;
    }
}
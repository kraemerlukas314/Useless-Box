#include "defines.h"

void animation1()
{
    Serial.println("animation 1");
    switch (animationStep)
    {
    case 0:
        if (moveArm(SERVO_TOGGLE_POS, 10))
        {
            animationStep = 1;
            animationInitilized = false;
        }

        break;
    case 1:
        if (moveArm(SERVO_HOME_POS, 1))
        {
            animationStep = 0;
            activeAnimation = -1;
            animationInitilized = false;
        }
        break;

    default:
        animationStep = 0;
        activeAnimation = -1;
        animationInitilized = false;
        break;
    }
}

void animation2()
{
    Serial.println("Animation 2");
    switch (animationStep)
    {
    case 1:
        if (moveArm(SERVO_HOME_POS / 2, 1))
        {
            ++animationStep;
            animationInitilized = false;
        }
        break;
    case 2:
        if (moveArm(SERVO_HOME_POS, 1))
        {
            ++animationStep;
            animationInitilized = false;
        }
        break;
    case 3:
        if (moveArm(SERVO_TOGGLE_POS, 1))
        {
            ++animationStep;
            animationInitilized = false;
        }
        break;
    case 4:
        if (moveArm(SERVO_HOME_POS, 1))
        {
            animationStep = 0;
            activeAnimation = -1;
            animationInitilized = false;
        }
        break;

    default:
        animationStep = 0;
        activeAnimation = -1;
        animationInitilized = false;
        break;
    }
}

bool moveArm(byte targetPos, byte steps)
{
    byte posNow = servo.read();
    if (!animationInitilized)
    {
        Serial.println("TargetPos: " + String(targetPos));
        Serial.println("PosNow: " + String(posNow));
        step = round((targetPos - posNow) / steps);
        animationInitilized = true;
        Serial.println("Animation initialized with step " + String(step));
    }
    servo.write(round((posNow + step)));
    // Serial.println("Position now: " + String(posNow) + ", wanted position: " + String(targetPos));
    posNow = servo.read();

    return (step < 0 && posNow <= targetPos) || (step > 0 && posNow >= targetPos);
}

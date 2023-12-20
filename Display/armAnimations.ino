#include "defines.h"

void animation1()
{
    switch (animationStep)
    {
    case 0:
        if (moveArm(SERVO_TOGGLE_POS, 10))
        {
            Serial.println("Animation 1 Done");
            animationStep = 1;
            animationInitilized = false;
        }
        else
        {
            // Serial.println("Animation 1 not done yet");
        }

        break;
    case 1:
        if (moveArm(SERVO_HOME_POS, 1))
        {
            Serial.println("Animation 2 Done");
            animationStep = 0;
            activeAnimation = -1;
            animationInitilized = false;
        }
        else
        {
            // Serial.println("Animation 2 not done yet");
        }
        break;

    default:
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
        step = (targetPos - posNow) / steps;
        animationInitilized = true;
        Serial.println("Animation initialized with step " + String(step));
    }
    servo.write(round((posNow + step)));
    // Serial.println("Position now: " + String(posNow) + ", wanted position: " + String(targetPos));
    posNow = servo.read();

    return (step < 0 && posNow <= targetPos) || (step > 0 && posNow >= targetPos);
}

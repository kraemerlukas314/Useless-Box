#include "defines.h"

void resetAnimation()
{
    if (moveArm(SERVO_HOME_POS, 1))
    {
        armAnimationInited = false;
        activeAnimation = -1;
        animationStep = 0;
        animationFinished = true;
        servo.detach();
    }
}

void animation1()
{
    switch (animationStep)
    {
    case 0:
        Serial.println("AnimationStep: " + String(animationStep));
        servo.attach(PIN_SERVO);
        animationStep++;

        break;

    case 1:
        Serial.println("AnimationStep: " + String(animationStep));
        if (moveArm(SERVO_TOGGLE_POS, 5))
        {
            armAnimationInited = false;
            animationStep++;
        }
        break;

    case 2:
        Serial.println("AnimationStep: " + String(animationStep));
        if (moveArm(SERVO_HOME_POS, 2))
        {
            armAnimationInited = false;
            animationStep++;
        }
        break;
    case 3:
        Serial.println("AnimationStep: " + String(animationStep));
        servo.detach();
        animationFinished = true;
        animationStep = 0;
        activeAnimation = -1;
        break;

    default:
        break;
    }
}

void animation2()
{
    switch (animationStep)
    {
    case 0:
        servo.attach(PIN_SERVO);
        animationStep++;
        break;

    case 1:
        if (moveArm(SERVO_HOME_POS - ((SERVO_HOME_POS - SERVO_TOGGLE_POS) / 2), 2))
        {
            armAnimationInited = false;
            animationStep++;
        }
        break;

    case 2:
        if (moveArm(SERVO_HOME_POS, 1))
        {
            armAnimationInited = false;
            animationStep++;
        }
        break;

    case 3:
        delay(random(500, 2000));
        armAnimationInited = false;
        animationStep++;
        break;

    case 4:
        if (moveArm(SERVO_TOGGLE_POS, 1))
        {
            armAnimationInited = false;
            animationStep++;
        }
        break;

    case 5:
        delay(1000);
        armAnimationInited = false;
        animationStep++;
        break;

    case 6:
        if (moveArm(SERVO_HOME_POS, 1))
        {
            armAnimationInited = false;
            animationStep++;
        }
        break;

    case 7:
        servo.detach();
        animationFinished = true;
        animationStep = 0;
        activeAnimation = -1;
        break;

    default:
        break;
    }
}

void animation3()
{
    switch (animationStep)
    {
    case 0:
        servo.attach(PIN_SERVO);
        animationStep++;
        break;

    case 1:
        delay(random(0, 2000));
        armAnimationInited = false;
        animationStep++;
        delay(random(0, 1000));
        break;

    case 2:

        if (moveArm(SERVO_TOGGLE_POS + 10, 1))
        {
            armAnimationInited = false;
            animationStep++;
        }
        break;

    case 3:
        if (moveArm(SERVO_HOME_POS, 1))
        {
            armAnimationInited = false;
            animationStep++;
        }
        break;

    case 4:
        delay(random(300, 1500));
        armAnimationInited = false;
        animationStep++;
        break;

    case 5:
        if (moveArm(SERVO_TOGGLE_POS, 1))
        {
            armAnimationInited = false;
            animationStep++;
        }
        break;

    case 6:
        if (moveArm(SERVO_HOME_POS, 1))
        {
            armAnimationInited = false;
            animationStep++;
        }
        break;

    case 7:
        servo.detach();
        animationFinished = true;
        animationStep = 0;
        activeAnimation = -1;
        break;

    default:
        break;
    }
}

void animation4()
{
    switch (animationStep)
    {
    case 0:
        servo.attach(PIN_SERVO);
        animationStep++;
        break;

    case 1:
        for (byte i = 0; i < random(1, 40); i++)
        {
            moveArm(SERVO_HOME_POS - 10, 1);
            delay(300);
            moveArm(SERVO_HOME_POS, 1);
        }
        armAnimationInited = false;
        animationStep++;
        break;

    case 2:
        for (byte i = 0; i < random(1, 5); i++)
        {
            moveArm(SERVO_TOGGLE_POS + 3, 1);
            delay(random(200, 500));
            moveArm(SERVO_HOME_POS - ((SERVO_HOME_POS - SERVO_TOGGLE_POS) / 2), 1);
        }
        armAnimationInited = false;
        animationStep++;
        break;

    case 3:
        if (moveArm(SERVO_HOME_POS, 3))
        {
            armAnimationInited = false;
            animationStep++;
        }
        break;

    case 4:
        servo.detach();
        animationFinished = true;
        animationStep = 0;
        activeAnimation = -1;
        break;

    default:
        break;
    }
}

void animation5()
{
    switch (animationStep)
    {
    case 0:
        servo.attach(PIN_SERVO);
        animationStep++;
        break;

    case 1:
        if (moveArm(SERVO_TOGGLE_POS, 20))
        {
            armAnimationInited = false;
            animationStep++;
        }
        break;
    case 2:
        if (moveArm(SERVO_TOGGLE_POS + 10, 2))
        {
            armAnimationInited = false;
            animationStep++;
        }
        break;

    case 3:
        if (moveArm(SERVO_TOGGLE_POS - 10, 1))
        {
            armAnimationInited = false;
            animationStep++;
        }
        break;

    case 4:
        delay(random(500, 5000));
        armAnimationInited = false;
        animationStep++;
        break;

    case 5:
        if (moveArm(SERVO_HOME_POS, 5))
        {
            armAnimationInited = false;
            animationStep++;
        }
        break;

    case 6:
        servo.detach();
        animationFinished = true;
        animationStep = 0;
        activeAnimation = -1;
        break;

    default:
        break;
    }
}

bool moveArm(byte targetPos, byte steps)
{
    byte posNow = servo.read();
    if (!armAnimationInited)
    {
        Serial.println("TargetPos: " + String(targetPos));
        Serial.println("PosNow: " + String(posNow));
        armAnimationDeg = round((targetPos - posNow) / steps);
        armAnimationInited = true;
        if (armAnimationDeg == 0)
        {
            return true;
        }
        Serial.println("Animation initialized with step " + String(armAnimationDeg));
    }

    if (posNow + armAnimationDeg <= SERVO_TOGGLE_POS)
    {
        buttonPushedByArm = true;
    }
    if (posNow + armAnimationDeg != posNow)
    {
        if (posNow + armAnimationDeg >= SERVO_TOGGLE_POS)
        {
            servo.write(posNow + armAnimationDeg);
        }
        else
        {
            servo.write(SERVO_TOGGLE_POS);
            return true;
        }
    }
    else
    {
        return true;
    }

    delay(abs(armAnimationDeg * 10));
    posNow = servo.read();
    Serial.println("PosNow: " + String(posNow));

    return (armAnimationDeg <= 0 && posNow <= targetPos) || (armAnimationDeg >= 0 && posNow >= targetPos);
}
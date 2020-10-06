#include "PID.h"
#include "Arduino.h"

float PID::update(float procVar, float dt)
{
    float error = setpoint - procVar;
    integral += error * dt;

    float derivative = (error - prevError) / dt;
    prevError = error;
    output = (Kp * error) + (Ki * integral) + (Kd * derivative);

    return output;
}
#ifndef PID_H
#define PID_H

class PID
{
public:
    float Kp = 0, Ki = 0, Kd = 0;
    float integral = 0;
    float setpoint = 0;
    float procVar;

    PID() {  }; // Default initializer
    PID(float p, float i, float d) { Kp = p, Ki = i; Kd = d; }; // Gains initializer
    PID(float p, float i, float d, float s) { Kp = p, Ki = i; Kd = d; setpoint = s; }; // Full initializer

    float update(float procVar, float dt); // Updates PID maths and returns new output
private:
    float prevError = 0;
};

#endif
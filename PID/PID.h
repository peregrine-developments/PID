#ifndef PID_H
#define PID_H

class PID
{
public:
    float Kp = 0, Ki = 0, Kd = 0;
    float setpoint = 0;

    float output = 0;

    PID() {  }; // Default initializer
    PID(float p, float i, float d) { Kp = p, Ki = i; Kd = d; }; // Gains initializer
    PID(float p, float i, float d, float s) { Kp = p, Ki = i; Kd = d; setpoint = s; }; // Full initializer

    float getKp() { return Kp; }; // Gains getters
    float getKi() { return Ki; };
    float getKd() { return Kd; };
    void setKp(float newKp) { Kp = newKp; }; // Gains setters
    void setKi(float newKi) { Ki = newKi; };
    void setKd(float newKd) { Kd = newKd; };

    float update(float procVar, float dt); // Updates PID maths and returns new output
    float get() { return output; }; // Returns last calculated PID value

    float getSetpoint() { return setpoint; }; // Returns last set setpoint
    void setSetpoint(float newSetpoint) { setpoint = newSetpoint; }; // Sets new setpiont
private:
    float integral = 0;
    float prevError = 0;
};

#endif
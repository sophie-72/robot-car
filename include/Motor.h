#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
private:
  int forwardPin;
  int backwardPin;
  int speedPin;

public:
  Motor(int forwardPin, int backwardPin, int speedPin);
  void forward();
  void backward();
  void setSpeed();
  void stop();
};

#endif
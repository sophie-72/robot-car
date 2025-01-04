#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
private:
  int forwardPin;
  int backwardPin;
  int speedPin;
  int normalSpeed;

public:
  Motor(int forwardPin, int backwardPin, int speedPin, int defaultSpeed);
  void forward() const;
  void backward() const;
  void setSpeed(int speed) const;
  void reduceSpeedToHalf() const;
  void resetSpeedToDefault() const;
  void stop() const;
};

#endif
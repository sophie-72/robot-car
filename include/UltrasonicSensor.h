#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include <Arduino.h>

class UltrasonicSensor {
private:
  int triggerPin;
  int echoPin;

public:
  UltrasonicSensor(int triggerPin, int echoPin);
  float getDistanceInCentimeters();
};

#endif //ULTRASONICSENSOR_H

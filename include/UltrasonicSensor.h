#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

class UltrasonicSensor {
  int triggerPin;
  int echoPin;

public:
  UltrasonicSensor(int triggerPin, int echoPin);

  float getDistanceInCentimeters() const;
};

#endif //ULTRASONICSENSOR_H

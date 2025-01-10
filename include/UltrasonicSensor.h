#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

class UltrasonicSensor {
  int echoPin;

public:
  UltrasonicSensor(int echoPin);

  float getDistanceInCentimeters() const;
};

#endif //ULTRASONICSENSOR_H

#ifndef ECHOSENSOR_H
#define ECHOSENSOR_H

class EchoSensor {
  int echoPin;

public:
  explicit EchoSensor(int echoPin);

  float getDistanceInCentimeters() const;
};

#endif //ECHOSENSOR_H

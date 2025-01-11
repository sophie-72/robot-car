#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include "SharedTrigger.h"
#include "EchoSensor.h"

class UltrasonicSensor {
    SharedTrigger trigger;
    EchoSensor echo;
    float tooCloseThresholdInCentimeters;

public:
    UltrasonicSensor(SharedTrigger trigger, EchoSensor echo, float tooCloseThresholdInCentimeters);

    float getDistance() const;

    bool isTooCloseToObstacle() const;
};

#endif //ULTRASONICSENSOR_H

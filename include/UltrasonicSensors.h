#ifndef ULTRASONICSENSORS_H
#define ULTRASONICSENSORS_H

#include "UltrasonicSensor.h"

class UltrasonicSensors {
    int triggerPin;

public:
    UltrasonicSensors(int triggerPin);

    void triggerSensors() const;
};


#endif //ULTRASONICSENSORS_H

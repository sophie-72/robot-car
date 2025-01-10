#ifndef ULTRASONICSENSORS_H
#define ULTRASONICSENSORS_H

#include "UltrasonicSensor.h"

class UltrasonicSensors {
    int triggerPin;
    UltrasonicSensor frontUltrasonicSensor;
    UltrasonicSensor leftUltrasonicSensor;
    UltrasonicSensor rightUltrasonicSensor;

public:
    UltrasonicSensors(int triggerPin, UltrasonicSensor frontUltrasonicSensor, UltrasonicSensor leftUltrasonicSensor, UltrasonicSensor rightUltrasonicSensor);

    void triggerSensors() const;
};


#endif //ULTRASONICSENSORS_H

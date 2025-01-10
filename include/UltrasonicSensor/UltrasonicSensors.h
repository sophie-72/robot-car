#ifndef ULTRASONICSENSORS_H
#define ULTRASONICSENSORS_H

#include "SharedTrigger.h"
#include "EchoSensor.h"
#include "SensorsDistances.h"

class UltrasonicSensors {
    SharedTrigger trigger;
    EchoSensor frontSensor;
    EchoSensor leftSensor;
    EchoSensor rightSensor;

    public:
      UltrasonicSensors(SharedTrigger trigger, EchoSensor frontSensor, EchoSensor leftSensor, EchoSensor rightSensor);

      SensorsDistances getDistances() const;
};

#endif //ULTRASONICSENSORS_H

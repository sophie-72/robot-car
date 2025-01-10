#include <Arduino.h>

#include "UltrasonicSensor/UltrasonicSensors.h"
#include "UltrasonicSensor/SharedTrigger.h"
#include "UltrasonicSensor/EchoSensor.h"
#include "UltrasonicSensor/SensorsDistances.h"

UltrasonicSensors::UltrasonicSensors(SharedTrigger trigger, EchoSensor frontSensor, EchoSensor leftSensor, EchoSensor rightSensor)
    : trigger(trigger), frontSensor(frontSensor), leftSensor(leftSensor), rightSensor(rightSensor) {

}

SensorsDistances UltrasonicSensors::getDistances() const {
    trigger.triggerSensors();
    float frontSensorDistance = frontSensor.getDistanceInCentimeters();
    delay(10);
    trigger.triggerSensors();
    float leftSensorDistance = leftSensor.getDistanceInCentimeters();
    delay(10);
    trigger.triggerSensors();
    float rightSensorDistance = rightSensor.getDistanceInCentimeters();
    delay(10);

    return SensorsDistances(frontSensorDistance, leftSensorDistance, rightSensorDistance);
}


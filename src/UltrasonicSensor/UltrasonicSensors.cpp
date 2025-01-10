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
    float leftSensorDistance = leftSensor.getDistanceInCentimeters();
    float rightSensorDistance = rightSensor.getDistanceInCentimeters();

    return SensorsDistances(frontSensorDistance, leftSensorDistance, rightSensorDistance);
}


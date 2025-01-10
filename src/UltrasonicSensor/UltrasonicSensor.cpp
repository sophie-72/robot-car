#include <Arduino.h>

#include "UltrasonicSensor/UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(SharedTrigger trigger, EchoSensor echo)
    : trigger(trigger), echo(echo) {

}

float UltrasonicSensor::getDistance() const {
    trigger.triggerSensors();
    float distance = echo.getDistanceInCentimeters();
    delay(10);

    return distance;
}
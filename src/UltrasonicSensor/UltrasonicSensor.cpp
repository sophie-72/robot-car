#include <Arduino.h>
#include "UltrasonicSensor/UltrasonicSensor.h"

constexpr float TOO_CLOSE_THRESHOLD_IN_CENTIMETERS = 30.0f;

UltrasonicSensor::UltrasonicSensor(SharedTrigger trigger, EchoSensor echo)
    : trigger(trigger), echo(echo) {

}

float UltrasonicSensor::getDistance() const {
    trigger.triggerSensors();
    float distance = echo.getDistanceInCentimeters();
    delay(10);
    return distance;
}

bool UltrasonicSensor::isTooCloseToObstacle() const {
    return getDistance() < TOO_CLOSE_THRESHOLD_IN_CENTIMETERS;
}
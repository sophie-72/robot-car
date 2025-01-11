#include <Arduino.h>
#include "UltrasonicSensor/UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(SharedTrigger trigger, EchoSensor echo, float tooCloseThresholdInCentimeters)
    : trigger(trigger), echo(echo), tooCloseThresholdInCentimeters(tooCloseThresholdInCentimeters) {

}

float UltrasonicSensor::getDistance() const {
    trigger.triggerSensors();
    float distance = echo.getDistanceInCentimeters();
    delay(10);
    return distance;
}

bool UltrasonicSensor::isTooCloseToObstacle() const {
    return getDistance() < tooCloseThresholdInCentimeters;
}
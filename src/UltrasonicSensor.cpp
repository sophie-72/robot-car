#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int triggerPin, int echoPin) {
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;

    pinMode(this->triggerPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
}

float UltrasonicSensor::getDistanceInCentimeters() {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    long duration = pulseIn(echoPin, HIGH);

    if (duration == 0) {
        return -1;
    }

    return (duration / 2.0) / 29.1; // Convert to cm
}

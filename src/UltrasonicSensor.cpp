#include <Arduino.h>
#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(const int triggerPin, const int echoPin)
    : triggerPin(triggerPin), echoPin(echoPin) {
    pinMode(this->triggerPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
}

float UltrasonicSensor::getDistanceInCentimeters() const {
    delay(100);
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    const unsigned long duration = pulseIn(echoPin, HIGH);

    if (duration == 0) {
        return -1.0f;
    }

    return (static_cast<float>(duration) / 2.0f) / 29.1f; // Convert to cm
}

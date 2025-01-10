#include <Arduino.h>
#include "UltrasonicSensor.h"

constexpr float SPEED_OF_SOUND_IN_CENTIMETERS_PER_MICROSECOND = 0.0343f;

UltrasonicSensor::UltrasonicSensor(const int triggerPin, const int echoPin)
    : triggerPin(triggerPin), echoPin(echoPin) {
    pinMode(this->triggerPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
}

float UltrasonicSensor::getDistanceInCentimeters() const {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    const unsigned long duration = pulseIn(echoPin, HIGH);

    return (static_cast<float>(duration) / 2.0f) * SPEED_OF_SOUND_IN_CENTIMETERS_PER_MICROSECOND;
}

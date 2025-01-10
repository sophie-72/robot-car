#include <Arduino.h>
#include "UltrasonicSensor/EchoSensor.h"

constexpr float SPEED_OF_SOUND_IN_CENTIMETERS_PER_MICROSECOND = 0.0343f;

EchoSensor::EchoSensor(const int echoPin)
    : echoPin(echoPin) {
    pinMode(this->echoPin, INPUT);
}

float EchoSensor::getDistanceInCentimeters() const {
    const unsigned long duration = pulseIn(echoPin, HIGH);

    return static_cast<float>(duration) / 2.0f * SPEED_OF_SOUND_IN_CENTIMETERS_PER_MICROSECOND;
}

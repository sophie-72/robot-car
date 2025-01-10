#include <Arduino.h>
#include "UltrasonicSensors.h"

UltrasonicSensors::UltrasonicSensors(int triggerPin) : triggerPin(triggerPin) {
    pinMode(this->triggerPin, OUTPUT);
}

void UltrasonicSensors::triggerSensors() const {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
}

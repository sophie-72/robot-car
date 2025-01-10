#include <Arduino.h>
#include "UltrasonicSensor/SharedTrigger.h"

SharedTrigger::SharedTrigger(int triggerPin) : triggerPin(triggerPin) {
    pinMode(this->triggerPin, OUTPUT);
}

void SharedTrigger::triggerSensors() const {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
}

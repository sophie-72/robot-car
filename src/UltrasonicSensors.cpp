#include <Arduino.h>
#include "UltrasonicSensors.h"

UltrasonicSensors::UltrasonicSensors(int triggerPin, UltrasonicSensor frontUltrasonicSensor, UltrasonicSensor leftUltrasonicSensor, UltrasonicSensor rightUltrasonicSensor)
    : triggerPin(triggerPin), frontUltrasonicSensor(frontUltrasonicSensor), leftUltrasonicSensor(leftUltrasonicSensor), rightUltrasonicSensor(rightUltrasonicSensor) {
    pinMode(this->triggerPin, OUTPUT);
}

void UltrasonicSensors::triggerSensors() const {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
}

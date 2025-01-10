#include <Arduino.h>
#include "Motor.h"

Motor::Motor(const int forwardPin, const int backwardPin, const int speedPin, const int defaultSpeed)
  : forwardPin(forwardPin), backwardPin(backwardPin), speedPin(speedPin), normalSpeed(defaultSpeed) {
  pinMode(this->forwardPin, OUTPUT);
  pinMode(this->backwardPin, OUTPUT);
  pinMode(this->speedPin, OUTPUT);

  setSpeed(this->normalSpeed);
}

void Motor::forward() const {
  digitalWrite(this->forwardPin, HIGH);
  digitalWrite(this->backwardPin, LOW);
}

void Motor::backward() const {
  digitalWrite(this->forwardPin, LOW);
  digitalWrite(this->backwardPin, HIGH);
}

void Motor::setSpeed(const int speed) const {
  analogWrite(this->speedPin, speed);
}

void Motor::reduceSpeedToHalf() const {
  setSpeed(normalSpeed / 2);
}

void Motor::resetSpeedToDefault() const {
  setSpeed(normalSpeed);
}


void Motor::stop() const {
  digitalWrite(this->forwardPin, LOW);
  digitalWrite(this->backwardPin, LOW);
}

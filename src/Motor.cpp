#include "Motor.h"

Motor::Motor(int forwardPin, int backwardPin, int speedPin) {
  this->forwardPin = forwardPin;
  this->backwardPin = backwardPin;
  this->speedPin = speedPin;

  pinMode(this->forwardPin, OUTPUT);
  pinMode(this->backwardPin, OUTPUT);
  pinMode(this->speedPin, OUTPUT);
}

void Motor::forward() const {
  digitalWrite(this->forwardPin, HIGH);
  digitalWrite(this->backwardPin, LOW);
}

void Motor::backward() const {
  digitalWrite(this->forwardPin, LOW);
  digitalWrite(this->backwardPin, HIGH);
}

void Motor::setSpeed(int speed) const {
  analogWrite(this->speedPin, speed);
}

void Motor::stop() const {
  digitalWrite(this->forwardPin, LOW);
  digitalWrite(this->backwardPin, LOW);
}

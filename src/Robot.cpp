#include <Arduino.h>
#include "Robot.h"

constexpr float TOO_CLOSE_THRESHOLD_IN_CENTIMETERS = 25.0;

Robot::Robot(const Motor &leftMotor, const Motor &rightMotor, const UltrasonicSensor &ultrasonicSensor)
  : leftMotor(leftMotor), rightMotor(rightMotor), ultrasonicSensor(ultrasonicSensor) {
}

void Robot::moveForward() const {
  this->leftMotor.resetSpeedToDefault();
  this->rightMotor.resetSpeedToDefault();

  this->leftMotor.forward();
  this->rightMotor.forward();
}

void Robot::moveBackward() const {
  this->leftMotor.resetSpeedToDefault();
  this->rightMotor.resetSpeedToDefault();

  this->leftMotor.backward();
  this->rightMotor.backward();
}

void Robot::turnLeft() const {
  this->leftMotor.reduceSpeedToHalf();
  this->rightMotor.reduceSpeedToHalf();

  this->leftMotor.backward();
  this->rightMotor.forward();
}

void Robot::turnRight() const {
  this->leftMotor.reduceSpeedToHalf();
  this->rightMotor.reduceSpeedToHalf();

  this->leftMotor.forward();
  this->rightMotor.backward();
}

bool Robot::isInFrontOfObstacle() const {
  Serial.println(this->ultrasonicSensor.getDistanceInCentimeters());
  return this->ultrasonicSensor.getDistanceInCentimeters() < TOO_CLOSE_THRESHOLD_IN_CENTIMETERS;
}

void Robot::avoidObstacle() const {
  while (isInFrontOfObstacle()) {
    turnRight();
    delay(500);
  }
}

bool Robot::isNotMoving() const {
  return this->ultrasonicSensor.getDistanceInCentimeters() == -1.0;
}


void Robot::move() const {
  if (isInFrontOfObstacle()) {
    if (isNotMoving()) {
      moveBackward();
      delay(500);
      turnLeft();
      delay(500);
    } else {
      avoidObstacle();
    }
  } else {
    moveForward();
  }
}

void Robot::stop() const {
  this->leftMotor.stop();
  this->rightMotor.stop();
}

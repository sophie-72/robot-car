#include <Arduino.h>
#include "Robot.h"

constexpr float TOO_CLOSE_THRESHOLD_IN_CENTIMETERS = 25.0f;
constexpr float NOT_MOVING_DIFFERENCE_THRESHOLD_IN_CENTIMETERS = 3.0f;
constexpr float ERROR_THRESHOLD_IN_CENTIMETERS = 2000.0f;

Robot::Robot(const Motor &leftMotor, const Motor &rightMotor, const UltrasonicSensors &ultrasonicSensors)
  : leftMotor(leftMotor), rightMotor(rightMotor), ultrasonicSensors(ultrasonicSensors) {
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

Direction Robot::getAvailableDirection() const {
  const SensorsDistances sensorsDistances = this->ultrasonicSensors.getDistances();

  if (sensorsDistances.getFrontSensorDistance() > TOO_CLOSE_THRESHOLD_IN_CENTIMETERS) {
    return Direction::Forward;
  }

  if (sensorsDistances.getRightSensorDistance() > TOO_CLOSE_THRESHOLD_IN_CENTIMETERS) {
    return Direction::Right;
  }

  if (sensorsDistances.getLeftSensorDistance() > TOO_CLOSE_THRESHOLD_IN_CENTIMETERS) {
    return Direction::Left;
  }

  return Direction::Backward;
}


void Robot::move() const {
  const Direction direction = getAvailableDirection();

  if (direction == Direction::Forward) {
    moveForward();
  }else if (direction == Direction::Right) {
    turnRight();
  }else if (direction == Direction::Left) {
    turnLeft();
  }else {
    moveBackward();
  }

}

void Robot::stop() const {
  this->leftMotor.stop();
  this->rightMotor.stop();
}

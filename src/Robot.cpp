#include "Robot.h"

constexpr float TOO_CLOSE_THRESHOLD_IN_CENTIMETERS = 25.0f;

Robot::Robot(const Motor &leftMotor, const Motor &rightMotor, const UltrasonicSensor &frontUltrasonicSensor, const UltrasonicSensor &leftUltrasonicSensor, const UltrasonicSensor &rightUltrasonicSensor)
  : leftMotor(leftMotor), rightMotor(rightMotor), frontUltrasonicSensor(frontUltrasonicSensor), leftUltrasonicSensor(leftUltrasonicSensor), rightUltrasonicSensor(rightUltrasonicSensor) {
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
  if (frontUltrasonicSensor.getDistance() > TOO_CLOSE_THRESHOLD_IN_CENTIMETERS) {
    return Direction::Forward;
  }

  if (leftUltrasonicSensor.getDistance() > TOO_CLOSE_THRESHOLD_IN_CENTIMETERS) {
    return Direction::Left;
  }

  if (rightUltrasonicSensor.getDistance() > TOO_CLOSE_THRESHOLD_IN_CENTIMETERS) {
    return Direction::Right;
  }

  return Direction::Backward;
}


void Robot::move() const {
  const Direction direction = getAvailableDirection();

  if (direction == Direction::Forward) {
    moveForward();
  } else if (direction == Direction::Right) {
    turnRight();
  } else if (direction == Direction::Left) {
    turnLeft();
  } else {
    moveBackward();
  }
}

void Robot::stop() const {
  this->leftMotor.stop();
  this->rightMotor.stop();
}

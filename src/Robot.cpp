#include "Robot.h"

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

void Robot::stop() const {
  this->leftMotor.stop();
  this->rightMotor.stop();
}

Direction Robot::getAvailableDirection() const {
  if (!frontUltrasonicSensor.isTooCloseToObstacle()) {
    return Direction::Forward;
  }

  if (!leftUltrasonicSensor.isTooCloseToObstacle()) {
    return Direction::Left;
  }

  if (!rightUltrasonicSensor.isTooCloseToObstacle()) {
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

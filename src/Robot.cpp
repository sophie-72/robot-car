#include <Arduino.h>
#include "Robot.h"

Robot::Robot(const Motor &leftMotor, const Motor &rightMotor, const UltrasonicSensor &frontUltrasonicSensor,
             const UltrasonicSensor &leftUltrasonicSensor, const UltrasonicSensor &rightUltrasonicSensor)
  : leftMotor(leftMotor), rightMotor(rightMotor), frontUltrasonicSensor(frontUltrasonicSensor),
    leftUltrasonicSensor(leftUltrasonicSensor), rightUltrasonicSensor(rightUltrasonicSensor) {
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

bool Robot::hasObstaclesFrontLeftRight() const {
  return frontUltrasonicSensor.isTooCloseToObstacle() && leftUltrasonicSensor.isTooCloseToObstacle() &&
         rightUltrasonicSensor.isTooCloseToObstacle();
}

bool Robot::hasObstaclesFrontLeft() const {
  return frontUltrasonicSensor.isTooCloseToObstacle() && leftUltrasonicSensor.isTooCloseToObstacle();
}

bool Robot::hasObstaclesFrontRight() const {
  return frontUltrasonicSensor.isTooCloseToObstacle() && rightUltrasonicSensor.isTooCloseToObstacle();
}

bool Robot::hasObstacleFront() const {
  return frontUltrasonicSensor.isTooCloseToObstacle();
}


bool Robot::hasObstacleLeft() const {
  return leftUltrasonicSensor.isTooCloseToObstacle();
}

bool Robot::hasObstacleRight() const {
  return rightUltrasonicSensor.isTooCloseToObstacle();
}


void Robot::move() const {
  if (hasObstaclesFrontLeftRight()) {
    stop();
  } else if (hasObstaclesFrontLeft() || hasObstacleFront()) {
    turnRight();
  } else if (hasObstaclesFrontRight()) {
    turnLeft();
  } else if (hasObstacleLeft()) {
    turnRight();
    delay(100);
    moveForward();
  } else if (hasObstacleRight()) {
    turnLeft();
    delay(100);
    moveForward();
  } else {
    moveForward();
  }
}

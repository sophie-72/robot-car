#include "Robot.h"

const float TOO_CLOSE_THRESHOLD_IN_CENTIMETERS = 30.0;

Robot::Robot(Motor leftMotor, Motor rightMotor, UltrasonicSensor ultrasonicSensor)
    : leftMotor(leftMotor), rightMotor(rightMotor), ultrasonicSensor(ultrasonicSensor) {

}

void Robot::moveForward() {
  this->leftMotor.resetSpeedToDefault();
  this->rightMotor.resetSpeedToDefault();

  this->leftMotor.forward();
  this->rightMotor.forward();
}

void Robot::moveBackward() {
  this->leftMotor.resetSpeedToDefault();
  this->rightMotor.resetSpeedToDefault();

  this->leftMotor.backward();
  this->rightMotor.backward();
}

void Robot::turnLeft() {
  this->leftMotor.reduceSpeedToHalf();
  this->rightMotor.reduceSpeedToHalf();

  this->leftMotor.backward();
  this->rightMotor.forward();
}

void Robot::turnRight() {
  this->leftMotor.reduceSpeedToHalf();
  this->rightMotor.reduceSpeedToHalf();

  this->leftMotor.forward();
  this->rightMotor.backward();
}

bool Robot::isInFrontOfObstacle() {
  return this->ultrasonicSensor.getDistanceInCentimeters() < TOO_CLOSE_THRESHOLD_IN_CENTIMETERS;
}

void Robot::avoidObstacle() {
  while (isInFrontOfObstacle()) {
    turnLeft();
  }
}

void Robot::move() {
  if (isInFrontOfObstacle()) {
    avoidObstacle();
  }else{
    moveForward();
  }
}

void Robot::stop() {
  this->leftMotor.stop();
  this->rightMotor.stop();
}
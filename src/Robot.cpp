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

bool Robot::isInFrontOfObstacle() const {
  float distance = this->ultrasonicSensors.getDistances().getFrontSensorDistance();
  Serial.println(distance);
  return distance < TOO_CLOSE_THRESHOLD_IN_CENTIMETERS;
}

void Robot::avoidObstacle() const {
  while (isInFrontOfObstacle()) {
    turnRight();
    delay(500);
  }
}

bool Robot::isNotMoving() const {
  constexpr int numberOfMeasures = 3;
  float distances[numberOfMeasures];
  float minDistance = TOO_CLOSE_THRESHOLD_IN_CENTIMETERS;
  float maxDistance = 0.0f;

  for (float & distance : distances) {
    delay(100);
    const float currentDistance = this->ultrasonicSensors.getDistances().getFrontSensorDistance();
    distance = currentDistance;

    if (currentDistance < ERROR_THRESHOLD_IN_CENTIMETERS) {
      if (currentDistance < minDistance) {
        minDistance = currentDistance;
      }

      if (currentDistance > maxDistance) {
        maxDistance = currentDistance;
      }
    }
  }

  return maxDistance - minDistance < NOT_MOVING_DIFFERENCE_THRESHOLD_IN_CENTIMETERS;
}


void Robot::move() const {
  if (isNotMoving()) {
    moveBackward();
    delay(500);
    turnLeft();
    delay(500);
  } else {
    if (isInFrontOfObstacle()) {
      avoidObstacle();
    } else {
      moveForward();
    }
  }
}

void Robot::stop() const {
  this->leftMotor.stop();
  this->rightMotor.stop();
}

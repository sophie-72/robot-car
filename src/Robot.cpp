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
  Serial.println(sensorsDistances.getFrontSensorDistance());
  Serial.println(sensorsDistances.getLeftSensorDistance());
  Serial.println(sensorsDistances.getRightSensorDistance());

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
  /*if (isNotMoving()) {
    moveBackward();
    delay(500);
    turnLeft();
    delay(500);
  } else {
    if (hasObstacleInFront()) {
      avoidObstacle();
    } else {
      moveForward();
    }
  }*/

  const Direction direction = getAvailableDirection();

  if (direction == Direction::Forward) {
    Serial.println("Moving forward");
    moveForward();
  }else if (direction == Direction::Right) {
    Serial.println("Moving right");
    turnRight();
  }else if (direction == Direction::Left) {
    Serial.println("Moving left");
    turnLeft();
  }else {
    Serial.println("Moving backward");
    moveBackward();
  }

}

void Robot::stop() const {
  this->leftMotor.stop();
  this->rightMotor.stop();
}

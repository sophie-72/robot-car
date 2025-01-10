#include "UltrasonicSensor/SensorsDistances.h"

SensorsDistances::SensorsDistances(float frontSensorDistance, float leftSensorDistance, float rightSensorDistance)
    : frontSensorDistance(frontSensorDistance), leftSensorDistance(leftSensorDistance), rightSensorDistance(rightSensorDistance) {

}

float SensorsDistances::getFrontSensorDistance() const{
  return frontSensorDistance;
}

float SensorsDistances::getLeftSensorDistance() const {
  return leftSensorDistance;
}

float SensorsDistances::getRightSensorDistance() const {
  return rightSensorDistance;
}
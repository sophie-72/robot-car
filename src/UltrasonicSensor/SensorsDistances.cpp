#include "UltrasonicSensor/SensorsDistances.h"

SensorsDistances::SensorsDistances(float frontSensorDistance, float leftSensorDistance, float rightSensorDistance)
    : frontSensorDistance(frontSensorDistance), leftSensorDistance(leftSensorDistance), rightSensorDistance(rightSensorDistance) {

}

float SensorsDistances::getFrontSensorDistance() {
  return frontSensorDistance;
}

float SensorsDistances::getLeftSensorDistance() {
  return leftSensorDistance;
}

float SensorsDistances::getRightSensorDistance() {
  return rightSensorDistance;
}
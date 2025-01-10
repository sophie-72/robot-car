#ifndef SENSORSDISTANCES_H
#define SENSORSDISTANCES_H

class SensorsDistances {
    float frontSensorDistance;
    float leftSensorDistance;
    float rightSensorDistance;

  public :
    SensorsDistances(float frontSensorDistance, float leftSensorDistance, float rightSensorDistance);

    float getFrontSensorDistance();

    float getLeftSensorDistance();

    float getRightSensorDistance();
};

#endif //SENSORSDISTANCES_H

#ifndef SENSORSDISTANCES_H
#define SENSORSDISTANCES_H

class SensorsDistances {
    float frontSensorDistance;
    float leftSensorDistance;
    float rightSensorDistance;

  public :
    SensorsDistances(float frontSensorDistance, float leftSensorDistance, float rightSensorDistance);

    float getFrontSensorDistance() const;

    float getLeftSensorDistance() const;

    float getRightSensorDistance() const;
};

#endif //SENSORSDISTANCES_H

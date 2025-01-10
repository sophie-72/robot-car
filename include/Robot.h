#ifndef ROBOT_H
#define ROBOT_H

#include "Motor.h"
#include "UltrasonicSensor/UltrasonicSensor.h"

class Robot {
    Motor leftMotor;
    Motor rightMotor;
    UltrasonicSensor frontUltrasonicSensor;
    UltrasonicSensor leftUltrasonicSensor;
    UltrasonicSensor rightUltrasonicSensor;

    void moveForward() const;

    void moveBackward() const;

    void turnLeft() const;

    void turnRight() const;

    void stop() const;

    bool hasObstaclesFrontLeftRight() const;

    bool hasObstaclesFrontLeft() const;

    bool hasObstaclesFrontRight() const;

    bool hasObstacleFront() const;

    bool hasObstacleLeft() const;

    bool hasObstacleRight() const;

public:
    Robot(const Motor &leftMotor, const Motor &rightMotor, const UltrasonicSensor &frontUltrasonicSensor,
          const UltrasonicSensor &leftUltrasonicSensor, const UltrasonicSensor &rightUltrasonicSensor);

    void move() const;
};

#endif //ROBOT_H

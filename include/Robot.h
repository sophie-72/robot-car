#ifndef ROBOT_H
#define ROBOT_H

#include "Motor.h"
#include "UltrasonicSensor.h"

class Robot {
private:
    Motor leftMotor;
    Motor rightMotor;
    UltrasonicSensor ultrasonicSensor;
    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();
    bool isInFrontOfObstacle();
    void avoidObstacle();

public:
    Robot(Motor leftMotor, Motor rightMotor, UltrasonicSensor ultrasonicSensor);
    void move();
    void stop();
};

#endif //ROBOT_H

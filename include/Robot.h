#ifndef ROBOT_H
#define ROBOT_H

#include "Motor.h"
#include "UltrasonicSensor.h"

class Robot {
private:
    Motor leftMotor;
    Motor rightMotor;
    UltrasonicSensor ultrasonicSensor;
    void moveForward() const;
    void moveBackward() const;
    void turnLeft() const;
    void turnRight() const;
    bool isInFrontOfObstacle() const;
    void avoidObstacle() const;
    bool isNotMoving() const;

public:
    Robot(const Motor &leftMotor, const Motor &rightMotor, const UltrasonicSensor &ultrasonicSensor);
    void move() const;
    void stop() const;
};

#endif //ROBOT_H

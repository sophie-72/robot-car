#include <Arduino.h>
#include "Robot.h"
#include "Motor.h"
#include "UltrasonicSensor.h"

constexpr int leftMotorForwardPin = 8;
constexpr int leftMotorBackwardPin = 7;
constexpr int leftMotorSpeedPin = 9;

constexpr int rightMotorForwardPin = 5;
constexpr int rightMotorBackwardPin = 4;
constexpr int rightMotorSpeedPin = 3;

constexpr int ultrasonicSensorTriggerPin = 11;
constexpr int ultrasonicSensorEchoPin = 10;

Motor leftMotor(leftMotorForwardPin, leftMotorBackwardPin, leftMotorSpeedPin);
Motor rightMotor(rightMotorForwardPin, rightMotorBackwardPin, rightMotorSpeedPin);
UltrasonicSensor ultrasonicSensor(ultrasonicSensorTriggerPin, ultrasonicSensorEchoPin);
Robot robot(leftMotor, rightMotor, ultrasonicSensor);

void setup() {
    Serial.begin(9600);
    Serial.println("Robot Initialized!");
}

void loop() {
    robot.move();
    delay(500);
}
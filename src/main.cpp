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

Motor leftMotor(rightMotorForwardPin, rightMotorBackwardPin, rightMotorSpeedPin, 255);
Motor rightMotor(leftMotorForwardPin, leftMotorBackwardPin, leftMotorSpeedPin, 244);
UltrasonicSensor ultrasonicSensor(ultrasonicSensorTriggerPin, ultrasonicSensorEchoPin);
Robot *robot;


void setup() {
    Serial.begin(9600);
    robot = new Robot(leftMotor, rightMotor, ultrasonicSensor);
    Serial.println("Robot Initialized!");
}

void loop() {
    robot->move();
    delay(100);
}

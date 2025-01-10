#include <Arduino.h>
#include "Robot.h"
#include "Motor.h"
#include "UltrasonicSensor/SharedTrigger.h"
#include "UltrasonicSensor/EchoSensor.h"
#include "UltrasonicSensor/UltrasonicSensors.h"

constexpr int leftMotorForwardPin = 8;
constexpr int leftMotorBackwardPin = 7;
constexpr int leftMotorSpeedPin = 9;

constexpr int rightMotorForwardPin = 5;
constexpr int rightMotorBackwardPin = 4;
constexpr int rightMotorSpeedPin = 3;

constexpr int ultrasonicSensorTriggerPin = 11;
constexpr int frontUltrasonicSensorEchoPin = 10;
constexpr int leftUltrasonicSensorEchoPin = 13;
constexpr int rightUltrasonicSensorEchoPin = 12;

Motor leftMotor(rightMotorForwardPin, rightMotorBackwardPin, rightMotorSpeedPin, 255);
Motor rightMotor(leftMotorForwardPin, leftMotorBackwardPin, leftMotorSpeedPin, 244);

SharedTrigger sharedTrigger(ultrasonicSensorTriggerPin);
EchoSensor frontUltrasonicSensor(frontUltrasonicSensorEchoPin);
EchoSensor leftUltrasonicSensor(leftUltrasonicSensorEchoPin);
EchoSensor rightUltrasonicSensor(rightUltrasonicSensorEchoPin);
UltrasonicSensors ultrasonicSensors(sharedTrigger, frontUltrasonicSensor, leftUltrasonicSensor, rightUltrasonicSensor);

Robot *robot;


void setup() {
    Serial.begin(9600);
    robot = new Robot(leftMotor, rightMotor, ultrasonicSensors);
    Serial.println("Robot Initialized!");
}

void loop() {
    robot->move();
    delay(100);
}

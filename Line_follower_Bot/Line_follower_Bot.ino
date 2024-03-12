//Line_follower_Bot
#include <Arduino.h>

// Define pins for motor control
const int motorPin1 = 2; // Motor 1 control pin 1
const int motorPin2 = 3; // Motor 1 control pin 2
const int motorPin3 = 14; // Motor 2 control pin 1
const int motorPin4 = 15; // Motor 2 control pin 2

// Define pins for IR sensors
const int irSensorPin1 = 13; // IR sensor 1 pin
const int irSensorPin2 = 12; // IR sensor 2 pin

void setup() {
  // Initialize motor control pins
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  // Initialize IR sensor pins
  pinMode(irSensorPin1, INPUT);
  pinMode(irSensorPin2, INPUT);
}

void loop() {
  byte ir1Value = digitalRead(irSensorPin1);
  byte ir2Value = digitalRead(irSensorPin2);

  // Checking if both sensors detect the line
  if (ir1Value && ir2Value) {
    // Both sensors on the line, move forward
    stopMotors();
  } else if (ir1Value) {
    // Left sensor detects the line, turn right
    turnLeft();
    delay(1);
  } else if (ir2Value) {
    // Right sensor detects the line, turn left
    turnRight();
    delay(1);
  } else {
    // Both sensors off the line, stop
    moveForward();
  }
}

void moveForward() {
  // Code to move forward
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

void turnLeft() {
  // Code  to turn left
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

void turnRight() {
  // Code to turn right
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}

void stopMotors() {
  // Code to stop the motors
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}
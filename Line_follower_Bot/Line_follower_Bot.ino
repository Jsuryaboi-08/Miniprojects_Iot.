#include <Arduino.h>

// Define pins for motor control
const int motorPin1 = XX; // Motor 1 control pin 1
const int motorPin2 = XX; // Motor 1 control pin 2
const int motorPin3 = XX; // Motor 2 control pin 1
const int motorPin4 = XX; // Motor 2 control pin 2

// Define pins for IR sensors
const int irSensorPin1 = XX; // IR sensor 1 pin
const int irSensorPin2 = XX; // IR sensor 2 pin

// Defining threshold for line detection
const int threshold = 500; 

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
  int ir1Value = analogRead(irSensorPin1);
  int ir2Value = analogRead(irSensorPin2);

  // Checking if both sensors detect the line
  if (ir1Value < threshold && ir2Value < threshold) {
    // Both sensors on the line, move forward
    moveForward();
  } else if (ir1Value < threshold) {
    // Left sensor detects the line, turn right
    turnRight();
  } else if (ir2Value < threshold) {
    // Right sensor detects the line, turn left
    turnLeft();
  } else {
    // Both sensors off the line, stop
    stopMotors();
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
  // Code to turn left
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
  digitalWrite(motorPin4, LOW);
}
//Line_follower_Bot
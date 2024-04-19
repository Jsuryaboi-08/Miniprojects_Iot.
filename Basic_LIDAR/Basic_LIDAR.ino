#include <Servo.h>

#define servopin 8
#define trigpin 2
#define echopin 4
#define LED 11
#define MIN_DISTANCE 10 // Minimum distance in cm to detect an object
#define MAX_ANGLE 170   // Maximum angle for the servo to sweep
#define MIN_ANGLE 10    // Minimum angle for the servo to sweep
#define ANGLE_INCREMENT 1   // Angle increment for each sweep
#define DISTANCE_AVERAGE 5  // Number of distance readings to average

Servo servo;

int angle = MIN_ANGLE;

void Led_Blink(int pinnum) {
  digitalWrite(pinnum, HIGH);
  delay(100);
  digitalWrite(pinnum, LOW);
  delay(100);
}

void setup() {
  Serial.begin(115200);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(LED, OUTPUT);
  servo.attach(servopin);
}

void takeDistanceReadings(int numReadings) {
  int sum = 0;
  for (int i = 0; i < numReadings; i++) {
    //pulse
    digitalWrite(trigpin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin, LOW);

    //distance
    int duration = pulseIn(echopin, HIGH);
    int dist_actual = duration / 58;
    sum += dist_actual;
  }
  int avgDist = sum / numReadings;
  Serial.print("Averaged Distance in CM: ");
  Serial.println(avgDist);
}

void sweepServo() {
  for (angle = MIN_ANGLE; angle <= MAX_ANGLE; angle += ANGLE_INCREMENT) {
    servo.write(angle);
    takeDistanceReadings(DISTANCE_AVERAGE);
  }
  for (angle = MAX_ANGLE; angle >= MIN_ANGLE; angle -= ANGLE_INCREMENT) {
    servo.write(angle);
    takeDistanceReadings(DISTANCE_AVERAGE);
  }
}

void loop() {
  sweepServo();

  if (angle <= MAX_ANGLE && angle >= MIN_ANGLE) {
    Led_Blink(LED);
    Serial.println("Object detected");
  }
}
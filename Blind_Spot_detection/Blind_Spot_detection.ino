#include <Arduino.h>

// Pins
#define RGB_RED_PIN 3
#define RGB_GREEN_PIN 5
#define RGB_BLUE_PIN 6
#define ECHO_PIN 8
#define TRIG_PIN 12
#define BUZZER_PIN 13

// Sensor parameters
#define TRIGGER_DISTANCE_1 30
#define TRIGGER_DISTANCE_2 10

// LED fade parameters
#define LED_FADE_STEP 3
#define LED_FADE_DELAY 5

// Buzzer parameters
int BUZZER_ON_DELAY = 500;
int BUZZER_OFF_DELAY = 500;

// Function prototypes
void initializePins();
int measureDistance();
void fadeRed();
void fadeOrange();
void fadeBlue();
void buzz();

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  // Initialize pins
  initializePins();
}

void loop() {
  // Measure distance
  int distance = measureDistance();

  // Determine LED and buzzer behavior based on distance
  if (distance <= TRIGGER_DISTANCE_1 && distance > TRIGGER_DISTANCE_2) {
    fadeOrange(); // Fade LED to orange
    buzz();      // Activate buzzer
  } else if (distance <= TRIGGER_DISTANCE_2) {
    fadeRed();   // Fade LED to red
    BUZZER_ON_DELAY = 100; //To make buzzer to buzz faster
    BUZZER_OFF_DELAY = 100;
    buzz();      // Activate buzzer
  } else {
    fadeBlue();  // Fade LED to blue
    BUZZER_ON_DELAY = 1000;// to make buzzer to buzz slower
    BUZZER_OFF_DELAY = 1000;
    buzz();      // Activate buzzer
  }
}

void initializePins() {
  // Set pin modes
  pinMode(RGB_RED_PIN, OUTPUT);
  pinMode(RGB_GREEN_PIN, OUTPUT);
  pinMode(RGB_BLUE_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

int measureDistance() {
  // Send ultrasonic pulse and measure duration
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;
  
  // Print distance for debugging
  Serial.println(distance);
  return distance;
}

void fadeRed() {
  // Fade LED to red
  for (int i = 255; i > 0; i -= LED_FADE_STEP) {
    analogWrite(RGB_RED_PIN, i);
    analogWrite(RGB_GREEN_PIN, 255);
    analogWrite(RGB_BLUE_PIN, 255);
    delay(LED_FADE_DELAY);
  }
  for (int i = 0; i < 255; i += LED_FADE_STEP) {
    analogWrite(RGB_RED_PIN, i);
    analogWrite(RGB_GREEN_PIN, 255);
    analogWrite(RGB_BLUE_PIN, 255);
    delay(LED_FADE_DELAY);
  }
}

void fadeOrange() {
  // Fade LED to orange
  for (int i = 255; i > 0; i -= LED_FADE_STEP) {
    analogWrite(RGB_RED_PIN, i);
    analogWrite(RGB_GREEN_PIN, i > 230 ? i : 230);
    analogWrite(RGB_BLUE_PIN, 255);
    delay(LED_FADE_DELAY);
  }
  for (int i = 0; i < 255; i += LED_FADE_STEP) {
    analogWrite(RGB_RED_PIN, i);
    analogWrite(RGB_GREEN_PIN, i < 230 ? 240 : i);
    analogWrite(RGB_BLUE_PIN, 255);
    delay(LED_FADE_DELAY);
  }
}

void fadeBlue() {
  // Fade LED to blue
  for (int i = 255; i > 0; i -= LED_FADE_STEP) {
    analogWrite(RGB_RED_PIN, 255);
    analogWrite(RGB_GREEN_PIN, 255);
    analogWrite(RGB_BLUE_PIN, i);
    delay(LED_FADE_DELAY);
  }for (int i = 0; i < 255; i += LED_FADE_STEP) {
    analogWrite(RGB_RED_PIN, 255);
    analogWrite(RGB_GREEN_PIN, 255);
    analogWrite(RGB_BLUE_PIN, i);
    delay(LED_FADE_DELAY);
  }
}

void buzz() {
  // Activate buzzer
  digitalWrite(BUZZER_PIN, HIGH);
  delay(BUZZER_ON_DELAY);
  digitalWrite(BUZZER_PIN, LOW);
  delay(BUZZER_OFF_DELAY);
}

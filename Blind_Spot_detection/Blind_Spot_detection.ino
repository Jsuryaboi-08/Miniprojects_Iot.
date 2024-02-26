//miniproject on blindspot detection system.

//initializing the rgb strip pins
#include <Arduino.h>
#define b 6
#define g 5
#define r 3
//initializing the ultrasonic sensor pins
#define echoPin 8
#define trigPin 12
//sensor accuracy based values for indicating distances.
#define trigDist1 30
#define trigDist2 10
// buzzer pins
#define buzzpin 13
long duration;
int distance;

bool fade = true;

void setup() {
  //initializing the pins for outputs/inputs respectively.
  Serial.begin(9600);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzpin, OUTPUT);
}
// calculating the distance between the host and object.
void calDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
}
//red pulsing animation to the led
void fadedRed(int val) {
  for (int i = 255; i > 0; i -= val) {
    analogWrite(r, i);
    analogWrite(g, 255);
    analogWrite(b, 255);
    delay(5);
  }
  for (int i = 0; i < 255; i += val) {
    analogWrite(r, i);
    analogWrite(g, 255);
    analogWrite(b, 255);
    delay(5);
  }
}


//orange color pulse to the led
void fadedOrange(int val) {
  for (int i = 255; i > 0; i -= val) {
    analogWrite(r, i);
    analogWrite(b, 255);
    analogWrite(g, i > 230 ? i : 230);
    delay(5);
  }
  for (int i = 0; i < 255; i += val) {
    analogWrite(r, i);
    analogWrite(b, 255);
    analogWrite(g, i < 230 ? 240 : i);
    delay(5);
  }
}

//blue pulse
void fadeInBlue(){  
 if(fade==true){   
  for(int i=255; i>0; i-=1){     
   analogWrite(g, 255);     
   analogWrite(r, 255);     
   analogWrite(b, i);      
   delay(5);    
  }  
 }  
 fade=false;  
 analogWrite(g, 255);  
 analogWrite(r, 255); 
 analogWrite(b, 0);
}
//checking for distance and calling the pulse functions accordingly.
void loop() {  
 calDistance(); 
 if(distance<=trigDist1 && distance>trigDist2){  
  fadedOrange(3);  
  fade=true; 
  digitalWrite(buzzpin, HIGH);
  delay(500);
  digitalWrite(buzzpin, LOW);
  delay(500);
 }
 else if(distance<=trigDist2){  
  fadedRed(3);  
  fade=true; digitalWrite(buzzpin, HIGH);
  delay(50);
  digitalWrite(buzzpin, LOW);
  delay(50);

 } 
 else{  
  fadeInBlue(); 
  digitalWrite(buzzpin, HIGH);
  delay(1000);
  digitalWrite(buzzpin, LOW);
  delay(1000);
 }
}

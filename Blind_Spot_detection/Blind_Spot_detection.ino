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
long duration;
int distance;
 
bool fade=true;
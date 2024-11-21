// Arduino Obstacle Avoiding Car
// Libraries Required:
// AFMotor Library: https://learn.adafruit.com/adafruit-motor-shield/library-install
// NewPing Library: https://github.com/livetronic/Arduino-NewPing
// Servo Library: https://github.com/arduino-libraries/Servo.git
// Install the libraries using Sketch >> Include Library >> Add .ZIP Library.

#include <AFMotor.h>  // Motor control library
#include <NewPing.h>  // Ultrasonic sensor library
#include <Servo.h>    // Servo motor library

// Pin Definitions for Ultrasonic Sensor
#define TRIG_PIN A0 // Trigger pin for HC-SR04
#define ECHO_PIN A1 // Echo pin for HC-SR04
#define MAX_DISTANCE 200 // Maximum distance for ultrasonic sensor (in cm)

// Motor Speed Configuration
#define MAX_SPEED 190 // Maximum speed for motors
#define MAX_SPEED_OFFSET 20 // Offset for speed adjustment

// Ultrasonic Sensor Initialization
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

// Motor Initialization
AF_DCMotor motor1(1, MOTOR12_1KHZ); // Motor connected to M1
AF_DCMotor motor2(2, MOTOR12_1KHZ); // Motor connected to M2
AF_DCMotor motor3(3, MOTOR34_1KHZ); // Motor connected to M3
AF_DCMotor motor4(4, MOTOR34_1KHZ); // Motor connected to M4

// Servo Initialization
Servo myservo;  

// Global Variables
boolean goesForward = false; // Tracks forward movement state
int distance = 100;          // Stores measured distance
int speedSet = 0;            // Speed control variable

void setup() {
  // Initialize servo motor and set initial position
  myservo.attach(10);  
  myservo.write(115); // Neutral position for servo
  delay(2000); // Allow time for servo to stabilize

  // Perform initial distance readings to stabilize the sensor
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
  int distanceR = 0; // Distance to the right
  int distanceL = 0; // Distance to the left
  delay(40); // Short delay to prevent excessive polling

  // Check if obstacle is too close
  if (distance <= 15) {
    moveStop();       // Stop the car
    delay(100);
    moveBackward();   // Move backward slightly
    delay(300);
    moveStop();       // Stop again
    delay(200);

    // Scan surroundings
    distanceR = lookRight(); // Measure distance to the right
    delay(200);
    distanceL = lookLeft();  // Measure distance to the left
    delay(200);

    // Decide the direction based on scanned distances
    if (distanceR >= distanceL) {
      turnRight(); // Turn right if right distance is greater
      moveStop();
    } else {
      turnLeft(); // Turn left if left distance is greater
      moveStop();
    }
  } else {
    // If no obstacle is close, move forward
    moveForward();
  }

  // Update distance measurement
  distance = readPing();
}

// Function to scan right and return distance
int lookRight() {
  myservo.write(50); // Rotate servo to the right
  delay(500); // Allow servo to stabilize
  int distance = readPing(); // Read distance
  delay(100);
  myservo.write(115); // Reset servo to neutral position
  return distance;
}

// Function to scan left and return distance
int lookLeft() {
  myservo.write(170); // Rotate servo to the left
  delay(500); // Allow servo to stabilize
  int distance = readPing(); // Read distance
  delay(100);
  myservo.write(115); // Reset servo to neutral position
  return distance;
}

// Function to read distance from the ultrasonic sensor
int readPing() { 
  delay(70); // Short delay to prevent sensor overuse
  int cm = sonar.ping_cm(); // Measure distance in cm
  if (cm == 0) {
    cm = 250; // Return a high value if no obstacle is detected
  }
  return cm;
}

// Function to stop all motors
void moveStop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
} 
  
// Function to move the car forward
void moveForward() {
  if (!goesForward) {
    goesForward = true;
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);

    // Gradually increase speed to prevent sudden jerks
    for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) {
      motor1.setSpeed(speedSet);
      motor2.setSpeed(speedSet);
      motor3.setSpeed(speedSet);
      motor4.setSpeed(speedSet);
      delay(5);
    }
  }
} 

// Function to move the car backward
void moveBackward() {
  goesForward = false;
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

  // Gradually increase speed to prevent sudden jerks
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
  }
}  

// Function to turn the car right
void turnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);     
  delay(500); // Allow time for the turn
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);      
} 
 
// Function to turn the car left
void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);   
  delay(500); // Allow time for the turn
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

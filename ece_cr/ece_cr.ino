/*
 * Obstacle Avoiding Robot
 * Author: Sai Teja Jarabala
 *
 * Description:
 * This program controls an obstacle-avoiding robot using an ultrasonic sensor (HC-SR04), 
 * a servo motor for directional sensing, and DC motors for movement. The robot detects 
 * obstacles and navigates around them by choosing the direction with the most clearance.
 *
 * Hardware Requirements:
 * - Arduino Board (e.g., Uno, Mega)
 * - Ultrasonic Sensor (HC-SR04)
 * - Servo Motor
 * - DC Motors (4x)
 * - Motor Driver Shield (e.g., Adafruit Motor Shield)
 * - Power Supply
 */

#include <AFMotor.h>        // Adafruit Motor Shield library
#include <NewPing.h>        // Ultrasonic sensor library
#include <Servo.h>          // Servo motor library

// Ultrasonic sensor pins and parameters
#define TRIG_PIN A0 
#define ECHO_PIN A1 
#define MAX_DISTANCE 200     // Maximum distance for ultrasonic sensor (in cm)

// Motor speed settings
#define MAX_SPEED 190        // Maximum speed for DC motors
#define MAX_SPEED_OFFSET 20  // Speed adjustment for smoother motion

// Initialize ultrasonic sensor
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

// Initialize motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

// Initialize servo motor for obstacle scanning
Servo myservo;   

// Control flags and variables
boolean goesForward = false;
int distance = 100;
int speedSet = 0;

void setup() {
  // Attach servo motor to pin 10
  myservo.attach(10);  
  myservo.write(115); // Set servo to forward-facing position
  delay(2000);

  // Initialize distance measurement for stability
  for (int i = 0; i < 4; i++) {
    distance = readPing();
    delay(100);
  }
}

void loop() {
  int distanceR = 0; // Distance to the right
  int distanceL = 0; // Distance to the left
  delay(40);

  // Check if an obstacle is within the threshold
  if (distance <= 15) {
    moveStop();
    delay(100);
    moveBackward(); // Move backward briefly
    delay(300);
    moveStop();
    delay(200);

    // Scan for the best direction
    distanceR = lookRight();
    delay(200);
    distanceL = lookLeft();
    delay(200);

    // Decide which direction to turn based on measured distances
    if (distanceR >= distanceL) {
      turnRight();
      moveStop();
    } else {
      turnLeft();
      moveStop();
    }
  } else {
    // Move forward if no obstacle is detected
    moveForward();
  }

  // Update distance measurement
  distance = readPing();
}

// Function to scan the right direction
int lookRight() {
  myservo.write(50); // Rotate servo to the right
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115); // Reset servo to forward position
  return distance;
}

// Function to scan the left direction
int lookLeft() {
  myservo.write(170); // Rotate servo to the left
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115); // Reset servo to forward position
  return distance;
}

// Function to read the distance from the ultrasonic sensor
int readPing() { 
  delay(70);
  int cm = sonar.ping_cm(); // Measure distance in cm
  return (cm == 0) ? 250 : cm; // Return 250 if no object detected
}

// Function to stop all motors
void moveStop() {
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

// Function to move the robot forward
void moveForward() {
  if (!goesForward) {
    goesForward = true;
    motor1.run(FORWARD);      
    motor2.run(FORWARD);
    motor3.run(FORWARD); 
    motor4.run(FORWARD);     

    // Gradually increase speed to avoid battery overload
    for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) {
      motor1.setSpeed(speedSet);
      motor2.setSpeed(speedSet);
      motor3.setSpeed(speedSet);
      motor4.setSpeed(speedSet);
      delay(5);
    }
  }
}

// Function to move the robot backward
void moveBackward() {
  goesForward = false;
  motor1.run(BACKWARD);      
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);  

  // Gradually increase speed to avoid battery overload
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
  }
}

// Function to turn the robot to the right
void turnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);     
  delay(500);
  motor1.run(FORWARD);      
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);      
}

// Function to turn the robot to the left
void turnLeft() {
  motor1.run(BACKWARD);     
  motor2.run(BACKWARD);  
  motor3.run(FORWARD);
  motor4.run(FORWARD);   
  delay(500);
  motor1.run(FORWARD);     
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

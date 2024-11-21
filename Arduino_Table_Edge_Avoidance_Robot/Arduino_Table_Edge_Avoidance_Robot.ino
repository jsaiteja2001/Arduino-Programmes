// Arduino Table Edge Avoidance Robot
// Author: Sai Teja Jarabala
// This program controls a robot that avoids table edges using IR sensors and Bluetooth commands.
// Before uploading the code, ensure the AFMotor.h library is installed.

#include <AFMotor.h> // Library for controlling DC motors via Adafruit Motor Shield

// Motor Initialization
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

// IR Sensor Pin Definitions
int IR1 = A0; // Right IR sensor
int IR2 = A1; // Left IR sensor

// Bluetooth Command Variable
char command;

void setup() {
  // Initialize Serial Communication
  Serial.begin(9600); // Set baud rate for Bluetooth communication
  
  // Configure IR Sensor Pins as Input
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
}

void loop() {
  // Check if a command is received via Bluetooth
  if (Serial.available() > 0) { 
    command = Serial.read(); // Read the received command
    Stop(); // Stop the robot before executing a new command
    
    Serial.println(command); // Print the received command for debugging
    
    // Execute commands based on Bluetooth input
    switch (command) {
      case 'F':  
        forward(); // Move forward
        break;
      case 'B':  
        back(); // Move backward
        break;
      case 'L':  
        left(); // Turn left
        break;
      case 'R':
        right(); // Turn right
        break;
    }
  }
  
  // Read IR Sensor Values
  int Right = digitalRead(IR1);
  int Left = digitalRead(IR2);
  
  // Check if any sensor detects a table edge
  if (Right == 1 || Left == 1) {
    moveBackward(); // Move backward to avoid falling
  } else if (Right == 0 && Left == 0) {
    // Wait for the next Bluetooth command
    if (Serial.available() > 0) {
      command = Serial.read();
    }
  }
}

// Function to move the robot forward
void forward() {
  motor1.setSpeed(150);
  motor1.run(FORWARD);
  motor2.setSpeed(150);
  motor2.run(FORWARD);
  motor3.setSpeed(150);
  motor3.run(FORWARD);
  motor4.setSpeed(150);
  motor4.run(FORWARD);
}

// Function to move the robot backward
void back() {
  motor1.setSpeed(150);
  motor1.run(BACKWARD);
  motor2.setSpeed(150);
  motor2.run(BACKWARD);
  motor3.setSpeed(150);
  motor3.run(BACKWARD);
  motor4.setSpeed(150);
  motor4.run(BACKWARD);
}

// Function to turn the robot left
void left() {
  motor1.setSpeed(200);
  motor1.run(BACKWARD);
  motor2.setSpeed(200);
  motor2.run(BACKWARD);
  motor3.setSpeed(200);
  motor3.run(FORWARD);
  motor4.setSpeed(200);
  motor4.run(FORWARD);
}

// Function to turn the robot right
void right() {
  motor1.setSpeed(200);
  motor1.run(FORWARD);
  motor2.setSpeed(200);
  motor2.run(FORWARD);
  motor3.setSpeed(200);
  motor3.run(BACKWARD);
  motor4.setSpeed(200);
  motor4.run(BACKWARD);
}

// Function to stop all motors
void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

// Function to move the robot backward for edge avoidance
void moveBackward() {
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

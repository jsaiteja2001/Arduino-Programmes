/*
 * Arduino Bluetooth Controlled Robot Car
 * Author: Sai Teja Jarabala
 *
 * Description:
 * This code allows for controlling a robot car using a Bluetooth module.
 * The robot can move forward, backward, turn left, and turn right based on serial input.
 * Additionally, it controls LEDs or other devices connected to digital pins.
 * 
 * Hardware Requirements:
 * - Arduino Board (e.g., Uno, Mega)
 * - Adafruit Motor Shield
 * - 4 DC Motors
 * - Bluetooth Module (e.g., HC-05/HC-06)
 * - Optional LEDs or devices connected to digital pins 8, 10, 11, 12
 * - Jumper Wires
 */

#include <AFMotor.h> // Include the Adafruit Motor Shield library

// Create motor objects for each motor port on the shield
AF_DCMotor motor1(1); // Motor connected to M1
AF_DCMotor motor2(2); // Motor connected to M2
AF_DCMotor motor3(3); // Motor connected to M3
AF_DCMotor motor4(4); // Motor connected to M4

char incomingByte; // Variable to store incoming serial data

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud

  // Set initial speed for all motors
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  // Stop all motors initially
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

  // Set digital pins as outputs for controlling additional devices
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  // Check if data is available on the serial port
  while (Serial.available() > 0) {
    incomingByte = Serial.read(); // Read the incoming byte

    // Control robot movement based on the received command
    if (incomingByte == '8') {
      moveForward(); // Move forward
    } else if (incomingByte == '2') {
      moveBackward(); // Move backward
    } else if (incomingByte == '6') {
      turnRight(); // Turn right
    } else if (incomingByte == '4') {
      turnLeft(); // Turn left
    } else if (incomingByte == '5') {
      stopMotors(); // Stop all motors
    }

    // Control devices connected to digital pins
    if (incomingByte == '1') {
      digitalWrite(8, HIGH);  // Turn device on pin 8 ON
      digitalWrite(10, LOW);  // Turn device on pin 10 OFF
    } else if (incomingByte == '3') {
      digitalWrite(8, LOW);   // Turn device on pin 8 OFF
      digitalWrite(10, HIGH); // Turn device on pin 10 ON
    } else if (incomingByte == '0') {
      digitalWrite(8, LOW);   // Turn device on pin 8 OFF
      digitalWrite(10, LOW);  // Turn device on pin 10 OFF
    }

    if (incomingByte == '7') {
      digitalWrite(11, LOW);  // Turn device on pin 11 OFF
    } else if (incomingByte == '9') {
      digitalWrite(11, HIGH); // Turn device on pin 11 ON
    }
  }
}

// Function to move the robot forward
void moveForward() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

// Function to move the robot backward
void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

// Function to turn the robot right
void turnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

// Function to turn the robot left
void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

// Function to stop all motors
void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

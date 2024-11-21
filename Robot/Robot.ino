/*
 * Hand Gesture Based Welcome Robot
 * Author: Sai Teja Jarabala
 *
 * Description:
 * This code controls a hand gesture-based welcome robot with functionalities for head movement,
 * hand gestures, and a mobile base with four wheels. The robot uses servos for the head and hands
 * and supports motion commands for the wheels.
 */

#include <Servo.h>

// Define servo motors
Servo headservo; // Head servo motor
Servo rsm;       // Right shoulder motor
Servo lsm;       // Left shoulder motor
Servo ram;       // Right arm motor
Servo lam;       // Left arm motor

// Define control variables
int angle = 90;      // Initial angle for head servo
char incomingByte;   // To store received serial data

void setup() {
  Serial.begin(9600); // Start Serial communication

  // Initialize wheel control pins as output
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(18, OUTPUT); // LED or additional signal pin

  // Attach servos to respective pins
  headservo.attach(2);
  lsm.attach(3);
  rsm.attach(4);
  lam.attach(5);
  ram.attach(6);

  // Set initial positions for servos
  headservo.write(90); // Head centered
  lsm.write(165);      // Left shoulder at initial position
  rsm.write(0);        // Right shoulder at initial position
  lam.write(0);        // Left arm at initial position
  ram.write(180);      // Right arm at initial position
}

void loop() {
  // Check if data is available on Serial
  while (Serial.available() > 0) {
    incomingByte = Serial.read(); // Read incoming byte

    // Wheel movement controls
    if (incomingByte == 0x38) { // Move forward
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(8, LOW);
    } else if (incomingByte == 0x32) { // Move backward
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(8, HIGH);
    } else if (incomingByte == 0x34) { // Turn left
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, HIGH);
    } else if (incomingByte == 0x36) { // Turn right
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, LOW);
    } else if (incomingByte == 0x35) { // Stop
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
    }

    // Head movement controls
    else if (incomingByte == 0x37) { // Move head up
      angle = angle + 15;
      headservo.write(angle);
    } else if (incomingByte == 0x39) { // Move head down
      angle = angle - 15;
      headservo.write(angle);
    }

    // Hand gesture movements
    else if (incomingByte == 0x31) { // Perform greeting gesture
      for (unsigned int ang = 0; ang <= 90; ang += 15) {
        lam.write(ang);
        ram.write(180 - ang);
        delay(100);
      }
      for (unsigned int ang1 = 15; ang1 <= 75; ang1 += 15) {
        lam.write(90 - ang1);
        ram.write(90 + ang1);
        lsm.write(165 - ang1);
        rsm.write(ang1);
        delay(100);
      }
      for (unsigned int ang2 = 75; ang2 >= 15; ang2 -= 15) {
        lam.write(90 - ang2);
        ram.write(90 + ang2);
        lsm.write(165 - ang2);
        rsm.write(ang2);
        delay(100);
      }
      for (unsigned int ang3 = 0; ang3 <= 75; ang3 += 15) {
        lam.write(75 - ang3);
        ram.write(105 + ang3);
        delay(100);
      }
    }

    else if (incomingByte == 0x33) { // Wave hand gesture
      for (unsigned int ang5 = 0; ang5 <= 105; ang5 += 15) {
        rsm.write(ang5);
        ram.write(180 - ang5);
        delay(100);
      }
      delay(500);
      for (unsigned int ang6 = 105; ang6 >= 0; ang6 -= 15) {
        rsm.write(ang6);
        ram.write(180 - ang6);
        delay(100);
      }
    }

    // Additional signaling
    else if (incomingByte == 19) {
      digitalWrite(18, HIGH);
    }
  }
}

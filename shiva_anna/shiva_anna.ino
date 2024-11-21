/*
 * Robotic Arm Control Program
 * Author: Sai Teja Jarabala
 *
 * Description:
 * This program controls a robotic arm with five servo motors: base, shoulder, elbow, wrist, and wrist roll.
 * The servos execute a series of motions, simulating the robotic arm's movements for demonstration purposes.
 */

#include <Servo.h>

// Define servo objects for each joint of the robotic arm
Servo base;       // Base servo motor
Servo shl;        // Shoulder servo motor
Servo elbow;      // Elbow servo motor
Servo wrist;      // Wrist servo motor
Servo wristroll;  // Wrist roll servo motor

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);

  // Attach servos to their respective pins
  base.attach(5);
  shl.attach(4);
  elbow.attach(3);
  wrist.attach(6);
  wristroll.attach(7);

  // Set initial positions for the servos
  base.write(180);    // Base at 180 degrees
  shl.write(10);      // Shoulder at 10 degrees
  elbow.write(10);    // Elbow at 10 degrees
  wrist.write(0);     // Wrist at 0 degrees
  wristroll.write(0); // Wrist roll at 0 degrees
}

void loop() {
  // Base rotation: Sweep from 0 to 180 degrees
  for (unsigned int ang = 0; ang <= 180; ang += 15) {
    base.write(ang);
    delay(100); // Wait 100ms for smooth movement
  }

  // Shoulder and elbow movement: Raise the shoulder and extend the elbow
  for (unsigned int ang1 = 0; ang1 <= 45; ang1 += 15) {
    shl.write(ang1);        // Raise shoulder
    elbow.write(ang1 * 2);  // Extend elbow proportionally
    delay(100);             // Wait 100ms for smooth movement
  }

  // Elbow movement: Full sweep from 0 to 180 degrees
  for (unsigned int ang = 0; ang <= 180; ang += 15) {
    elbow.write(ang);
    delay(100); // Wait 100ms for smooth movement
  }

  // Wrist and wrist roll movement: Move wrist up and rotate wrist roll
  for (unsigned int ang2 = 0; ang2 <= 90; ang2 += 15) {
    wrist.write(ang2);             // Move wrist up
    wristroll.write(ang2 / 4);     // Rotate wrist roll proportionally
    delay(150);                    // Wait 150ms for smooth movement
  }

  // Return to starting position: Move base and elbow back to initial positions
  for (unsigned int ang = 180; ang >= 2; ang -= 15) {
    base.write(ang);               // Rotate base back to starting position
    elbow.write(ang / 2);          // Retract elbow proportionally
    delay(150);                    // Wait 150ms for smooth movement
    Serial.println("Returning to start position...");
  }
}

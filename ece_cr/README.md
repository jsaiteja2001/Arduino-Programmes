# Obstacle Avoiding Robot

## Overview
This project involves creating an obstacle-avoiding robot using an Arduino, ultrasonic sensors, a servo motor, and four DC motors. The robot autonomously navigates its environment, detects obstacles using an ultrasonic sensor, and chooses the best direction to avoid collisions.

## Features
- **Autonomous Navigation**: The robot moves forward and avoids obstacles in its path.
- **Obstacle Detection**: Uses an ultrasonic sensor to detect obstacles up to 200 cm away.
- **Dynamic Decision Making**: Turns left or right based on the direction with the most clearance.
- **Servo Integration**: The ultrasonic sensor is mounted on a servo for directional scanning.
- **Smooth Motion Control**: Gradual acceleration and deceleration to protect hardware and conserve battery life.

---

## Hardware Requirements
- **Arduino Board** (e.g., Uno, Mega)
- **Ultrasonic Sensor** (e.g., HC-SR04)
- **Servo Motor**
- **DC Motors** (4x)
- **Adafruit Motor Shield** or equivalent motor driver
- **Power Supply** (for motors and Arduino)
- **Jumper Wires**
- **Chassis** (for mounting components and wheels)

---

## Software Requirements
- **Arduino IDE**
- Required Libraries:
  - `AFMotor`: For motor control with the Adafruit Motor Shield.
  - `NewPing`: For interfacing with the ultrasonic sensor.
  - `Servo`: For controlling the servo motor.

---

## Circuit Connections
### Ultrasonic Sensor (HC-SR04)
| Pin  | Arduino Pin |
|------|-------------|
| VCC  | 5V          |
| GND  | GND         |
| TRIG | A0          |
| ECHO | A1          |

### Servo Motor
| Servo Pin | Arduino Pin |
|-----------|-------------|
| Signal    | 10          |
| VCC       | 5V          |
| GND       | GND         |

### Motors (via Motor Shield)
| Motor  | Shield Port |
|--------|-------------|
| Motor 1| M1          |
| Motor 2| M2          |
| Motor 3| M3          |
| Motor 4| M4          |

---

## Installation and Usage
1. **Install Arduino Libraries**:
   - Open Arduino IDE.
   - Go to **Tools > Manage Libraries**.
   - Search for `AFMotor`, `NewPing`, and `Servo` libraries, and install them.

2. **Connect Hardware**:
   - Assemble the robot with the ultrasonic sensor mounted on the servo.
   - Connect the motors, ultrasonic sensor, and servo motor to the Arduino as per the circuit connections above.

3. **Upload the Code**:
   - Copy the provided code into the Arduino IDE.
   - Connect the Arduino to your computer via USB.
   - Select the correct COM port and board type.
   - Click **Upload** to load the program onto the Arduino.

4. **Power the Robot**:
   - Provide power to the motors through an external power supply.
   - Ensure the Arduino has a separate power source (e.g., USB or battery).

---

## How It Works
1. **Initialization**:
   - The robot initializes the servo motor and measures the distance using the ultrasonic sensor.
   - The robot starts moving forward.

2. **Obstacle Detection**:
   - The ultrasonic sensor continuously scans for obstacles within a range of 15 cm.
   - If an obstacle is detected, the robot stops, moves backward briefly, and scans both left and right directions to find the best path.

3. **Turning**:
   - Based on the distance readings, the robot turns to the direction with the most clearance and resumes moving forward.

4. **Continuous Operation**:
   - The robot repeats this process, navigating its environment autonomously.

---

## Troubleshooting
- **Robot Not Moving**:
  - Check motor connections to the motor shield.
  - Ensure the power supply for the motors is sufficient.

- **Servo Not Rotating**:
  - Verify the servo motor connection to pin 10.
  - Ensure the `Servo` library is installed.

- **Distance Not Detected**:
  - Check the ultrasonic sensor connections.
  - Ensure the `NewPing` library is installed.

---

## Customization
- **Adjust Speed**:
  - Modify the `MAX_SPEED` value in the code to increase or decrease motor speed.

- **Change Obstacle Distance**:
  - Update the `distance <= 15` condition in the `loop()` function to set a different obstacle detection threshold.

- **Add Additional Sensors**:
  - Integrate IR sensors or other modules for enhanced navigation and obstacle detection.

---

### **Summary**
This `README.md` file provides:
1. An overview of the project.
2. Hardware and software requirements.
3. Circuit connections and setup instructions.
4. Detailed usage, troubleshooting, and customization guidance.

You can use or modify this documentation as needed for your project.


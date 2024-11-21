# Arduino Obstacle Avoiding Car

## Overview
This project demonstrates an Arduino-based obstacle-avoiding car that uses an ultrasonic sensor for distance measurement, a servo motor for directional scanning, and DC motors for movement. The car is programmed to avoid obstacles by scanning the surroundings and selecting the optimal path for navigation.

---

## Features
- **Obstacle Avoidance**: Detects obstacles and navigates around them.
- **Directional Scanning**: Servo motor scans left and right for optimal paths.
- **Smooth Speed Control**: Gradual acceleration to protect battery health.
- **Movement**: Moves forward, backward, and turns left or right based on obstacle detection.

---

## Requirements
### Hardware
- Arduino board (e.g., Uno, Mega)
- Adafruit Motor Shield
- HC-SR04 Ultrasonic Sensor
- 4 DC motors
- Servo motor
- External power supply for motors
- Jumper wires and connectors

### Libraries
Install the following libraries before uploading the code:
1. [AFMotor Library](https://learn.adafruit.com/adafruit-motor-shield/library-install)
2. [NewPing Library](https://github.com/livetronic/Arduino-NewPing)
3. [Servo Library](https://github.com/arduino-libraries/Servo.git)

#### How to Install Libraries
1. Download the ZIP files from the provided links.
2. Open Arduino IDE and navigate to:
   - **Sketch** → **Include Library** → **Add .ZIP Library**.
3. Select the downloaded ZIP files to add them.

---

## How It Works
1. The ultrasonic sensor detects the distance to obstacles in front of the car.
2. If an obstacle is detected within 15 cm:
   - The car stops and reverses briefly.
   - The servo rotates the ultrasonic sensor to scan left and right.
   - The car chooses the direction with more space and turns accordingly.
3. If no obstacles are detected, the car continues moving forward.

---

## Connections
### Ultrasonic Sensor
- **TRIG_PIN**: A0
- **ECHO_PIN**: A1

### Servo Motor
- **Signal Pin**: Digital Pin 10

### Motors
- **Motor 1**: Motor Shield M1
- **Motor 2**: Motor Shield M2
- **Motor 3**: Motor Shield M3
- **Motor 4**: Motor Shield M4

---

## Installation and Setup
1. Connect all hardware components as per the connections mentioned above.
2. Install the required libraries in the Arduino IDE.
3. Upload the provided code to the Arduino board.

---

## Usage
1. Power up the system (both the Arduino and external power supply for motors).
2. Place the car on a flat surface.
3. The car will:
   - Start scanning the environment.
   - Move forward, turn, or reverse based on the presence of obstacles.

---

## Code Overview
### Key Functions
- **`readPing()`**: Reads the distance to the nearest obstacle using the ultrasonic sensor.
- **`lookRight()` and `lookLeft()`**: Rotate the servo motor to scan the surroundings.
- **Movement Functions**:
  - `moveForward()`: Moves the car forward.
  - `moveBackward()`: Moves the car backward.
  - `turnLeft()`: Turns the car to the left.
  - `turnRight()`: Turns the car to the right.
  - `moveStop()`: Stops the car.

---

## Troubleshooting
1. **Car Not Moving**:
   - Check motor connections and ensure external power supply is connected.
   - Verify library installations and Arduino code upload.
2. **Incorrect Turns**:
   - Check servo motor calibration.
   - Adjust angles in the `lookRight()` and `lookLeft()` functions if needed.
3. **Distance Not Detected**:
   - Verify ultrasonic sensor connections.
   - Check for any obstructions in front of the sensor.

---

## License
This project is licensed under the [MIT License](./LICENSE).

---

## Author
**Sai Teja Jarabala**

For questions, suggestions, or contributions, feel free to open an issue in the [GitHub Repository](https://github.com/jsaiteja2001).

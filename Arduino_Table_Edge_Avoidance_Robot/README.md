# Arduino Table Edge Avoidance Robot

## Overview
This project implements a table edge avoidance robot using Arduino, IR sensors, and Bluetooth commands. The robot moves forward, backward, left, or right based on Bluetooth commands and automatically avoids table edges using IR sensors.

## Features
- **Bluetooth Control**: Control the robot remotely via Bluetooth.
- **Edge Detection**: Avoids falling off table edges using IR sensors.
- **Smooth Movement**: Speed and direction of DC motors are smoothly controlled.

## Requirements
### Hardware
- Arduino Board (e.g., Uno, Mega)
- Adafruit Motor Shield
- 4 DC Motors
- 2 IR Sensors
- Bluetooth Module (e.g., HC-05/HC-06)
- Jumper Wires

### Libraries
- **AFMotor**: Required for controlling the motors. Install it using Arduino IDE:
  - Go to **Sketch** → **Include Library** → **Manage Libraries**, search for "AFMotor," and install it.

## How to Use
1. **Connections**:
   - **IR Sensors**: Connect to analog pins `A0` (Right) and `A1` (Left).
   - **Motors**: Connect to the Motor Shield's `M1`, `M2`, `M3`, and `M4` terminals.
   - **Bluetooth Module**: Connect to Arduino's TX and RX pins.
2. **Upload the Code**:
   - Use the Arduino IDE to upload the provided code to your board.
3. **Control the Robot**:
   - Send the following commands via a Bluetooth terminal app:
     - `F`: Move Forward
     - `B`: Move Backward
     - `L`: Turn Left
     - `R`: Turn Right

## Functions
- **Forward Movement**: Moves all motors forward.
- **Backward Movement**: Moves all motors backward.
- **Left Turn**: Rotates the left motors backward and right motors forward.
- **Right Turn**: Rotates the right motors backward and left motors forward.
- **Edge Avoidance**: Automatically reverses if an edge is detected by IR sensors.

## Troubleshooting
- **Robot Not Responding**:
  - Check motor and sensor connections.
  - Ensure the Bluetooth module is paired correctly.
- **Edge Not Detected**:
  - Verify the IR sensor connections and functionality.

## License
This project is licensed under the [MIT License](./LICENSE).

## Author
**Sai Teja Jarabala**

For questions or contributions, visit the repository at [GitHub](https://github.com/jsaiteja2001).

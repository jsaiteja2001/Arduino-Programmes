# Bluetooth Controlled Robot Car

## Overview
This project demonstrates a Bluetooth-controlled robot car using an Arduino. The robot moves forward, backward, turns left or right, and stops based on commands sent via Bluetooth. It uses a motor driver module (e.g., L298N) to control two DC motors.

## Features
- **Bluetooth Control**: Remotely control the robot using a smartphone or Bluetooth terminal.
- **Movement Options**: Supports forward, backward, left turn, right turn, and stop commands.
- **Simple Command Protocol**: Single-character commands for intuitive control.

## Hardware Requirements
- **Arduino Board** (e.g., Uno, Mega)
- **Motor Driver Module** (e.g., L298N)
- **2 DC Motors**
- **Bluetooth Module** (e.g., HC-05, HC-06)
- **Power Supply** (for motors and Arduino)
- **Jumper Wires** and **Breadboard**

## Software Requirements
- **Arduino IDE**
- **Bluetooth Terminal App** (for Android or iOS)

## Setup and Wiring
### Motor Driver Connections
- **Motor A**: Connect to pins 2 and 3 on the motor driver module.
- **Motor B**: Connect to pins 4 and 5 on the motor driver module.
- **Power Supply**: Provide appropriate power for the motors and motor driver.

### Bluetooth Module Connections
- **VCC**: Connect to 5V on Arduino.
- **GND**: Connect to GND on Arduino.
- **TX**: Connect to RX on Arduino (use a voltage divider if necessary).
- **RX**: Connect to TX on Arduino.

## Commands
Use a Bluetooth terminal app to send the following commands to control the robot:

| Command | Action       |
|---------|--------------|
| `0`     | Move Forward |
| `1`     | Turn Left    |
| `2`     | Turn Right   |
| `3`     | Move Backward|
| `4`     | Stop         |

## Usage
1. **Upload the Code**: Use the Arduino IDE to upload the provided code to your Arduino board.
2. **Pair the Bluetooth Module**:
   - Turn on the robot.
   - Pair the Bluetooth module with your smartphone or computer.
   - Default PIN is usually `1234` or `0000`.
3. **Control the Robot**:
   - Open a Bluetooth terminal app.
   - Send single-character commands (e.g., `0`, `1`, `2`, `3`, `4`) to control the robot's movement.

## Troubleshooting
- **Robot Not Responding**:
  - Verify Bluetooth pairing and ensure the module is powered.
  - Check motor connections and ensure the driver module is working.
- **Motors Moving Incorrectly**:
  - Reverse the connections for the motors on the motor driver module.

## License
This project is licensed under the [MIT License](./LICENSE).

## Author
**Sai Teja Jarabala**

For any questions or contributions, please visit the [GitHub Repository](https://github.com/jsaiteja2001).

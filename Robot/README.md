# Hand Gesture Based Welcome Robot

## Overview
This project implements a hand gesture-based welcome robot with a moving head, arms, and a mobile base. The robot performs pre-programmed gestures and movements in response to serial commands. It is equipped with a camera in its head for interaction and observation.

## Features
- **Head Movement**: Controlled via servo motor, allowing upward and downward motion.
- **Hand Gestures**: Performs greeting and waving gestures using servo motors.
- **Mobile Base**: Moves forward, backward, left, and right, or stops using a motorized base.
- **Fully Programmable**: Controlled using serial commands.

## Hardware Requirements
- **Arduino Board** (e.g., Uno, Mega)
- **Servo Motors** (5x: head, shoulders, and arms)
- **DC Motors** (4x for the wheels)
- **Motor Driver Module**
- **Acrylic Sheet** for the hand structure
- **Wheels** for the mobile base
- **Camera** (optional, mounted on the head)
- **Power Supply** for motors and servos
- **Jumper Wires and Breadboard**

## Software Requirements
- **Arduino IDE**
- Required Libraries:
  - `Servo`

## Setup and Wiring
- **Servos**:
  - Head servo: Connect to pin `2`.
  - Left shoulder servo: Connect to pin `3`.
  - Right shoulder servo: Connect to pin `4`.
  - Left arm servo: Connect to pin `5`.
  - Right arm servo: Connect to pin `6`.

- **DC Motors**:
  - Connect motors to a motor driver module controlled by pins `12`, `11`, `10`, and `8`.

- **Additional Signals**:
  - LED or other signaling devices connected to pin `18`.

## Serial Commands
| Command | Action                   |
|---------|--------------------------|
| `0x38`  | Move Forward             |
| `0x32`  | Move Backward            |
| `0x34`  | Turn Left                |
| `0x36`  | Turn Right               |
| `0x35`  | Stop                     |
| `0x37`  | Move Head Up             |
| `0x39`  | Move Head Down           |
| `0x31`  | Perform Greeting Gesture |
| `0x33`  | Perform Waving Gesture   |

## License
This project is licensed under the [MIT License](./LICENSE).

## Author
**Sai Teja Jarabala**

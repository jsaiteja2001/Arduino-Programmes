# Arduino Bluetooth Controlled Robot Car

## Overview
This project involves creating a Bluetooth-controlled robot car using an Arduino and the Adafruit Motor Shield. The robot can move forward, backward, and turn left or right based on commands received via Bluetooth. Additionally, it can control devices (like LEDs) connected to specific digital pins.

## Features
- **Bluetooth Control**: Control the robot remotely using a Bluetooth-enabled device.
- **Multiple Movements**: Supports forward, backward, left turn, and right turn motions.
- **Device Control**: Control additional devices (e.g., LEDs) connected to digital pins.
- **Simple Command Protocol**: Uses single-character commands for easy control.

## Requirements

### Hardware
- **Arduino Board** (e.g., Uno, Mega)
- **Adafruit Motor Shield**
- **4 DC Motors**
- **Bluetooth Module** (e.g., HC-05, HC-06)
- **Optional Devices** connected to digital pins 8, 10, 11, 12 (e.g., LEDs)
- **Power Supply** for motors and Arduino
- **Jumper Wires and Breadboard**

### Software
- **Arduino IDE**
- **AFMotor Library**: Ensure the `AFMotor.h` library is installed. You can install it via the Library Manager in the Arduino IDE.

## Setup and Wiring

### Motor Connections
- **Motor 1**: Connected to M1 on the Motor Shield
- **Motor 2**: Connected to M2 on the Motor Shield
- **Motor 3**: Connected to M3 on the Motor Shield
- **Motor 4**: Connected to M4 on the Motor Shield

### Bluetooth Module Connections
- **VCC**: Connect to 5V on Arduino
- **GND**: Connect to GND on Arduino
- **TX**: Connect to RX on Arduino (may require voltage divider)
- **RX**: Connect to TX on Arduino

### Digital Pins for Device Control
- **Pin 8**: Device 1 (e.g., LED)
- **Pin 10**: Device 2 (e.g., LED)
- **Pin 11**: Device 3 (e.g., LED)
- **Pin 12**: (Unused in code, available for additional use)

## How to Use

1. **Upload the Code**: Upload the provided code to your Arduino board using the Arduino IDE.

2. **Pair Bluetooth Module**:
   - Power the robot and ensure the Bluetooth module is discoverable.
   - Pair the module with your smartphone or computer using the default PIN (usually `1234` or `0000`).

3. **Install a Bluetooth Terminal App**:
   - Use a Bluetooth terminal app on your smartphone (e.g., "Bluetooth Terminal" for Android).

4. **Control Commands**:
   - Send the following single-character commands to control the robot:

     | Command | Action                   |
     |---------|--------------------------|
     | `8`     | Move Forward             |
     | `2`     | Move Backward            |
     | `4`     | Turn Left                |
     | `6`     | Turn Right               |
     | `5`     | Stop                     |
     | `1`     | Turn ON Device on Pin 8  |
     | `3`     | Turn ON Device on Pin 10 |
     | `0`     | Turn OFF Devices on Pins 8 & 10 |
     | `7`     | Turn OFF Device on Pin 11|
     | `9`     | Turn ON Device on Pin 11 |

5. **Power Supply**:
   - Ensure that your motors are powered by an external power source appropriate for their voltage and current requirements.
   - Do not power the motors directly from the Arduino's 5V pin.

## Notes

- **Safety First**: Always disconnect power before making changes to your circuit.
- **Motor Direction**: If the robot doesn't move in the correct direction, you may need to swap the motor leads.
- **Voltage Levels**: Be cautious with voltage levels when connecting the Bluetooth module to avoid damaging the Arduino.

## Troubleshooting

- **Robot Not Responding**:
  - Check the Bluetooth connection and ensure the module is properly paired.
  - Verify that the correct COM port and baud rate are set in your terminal app.

- **Motors Not Moving**:
  - Ensure that the motor shield is properly seated on the Arduino.
  - Check that the motors are connected to the correct terminals.

- **Commands Not Working**:
  - Make sure you're sending the correct single-character commands without any additional characters (like newline).

## License

This project is licensed under the [MIT License](./LICENSE).

## Author

**Sai Teja Jarabala**

For any questions or contributions, please visit the [GitHub Repository](https://github.com/jsaiteja2001).

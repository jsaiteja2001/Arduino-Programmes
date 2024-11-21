# GSM-Based Circuit Breaker with Keypad and Password

## Overview
This project implements a GSM-based circuit breaker system controlled by a keypad and password. A randomly generated password is sent to a predefined mobile number via SMS. The user enters the password on the keypad to unlock the circuit breaker.

## Features
- **Random Password Generation**: A 4-digit random password is generated each time the system starts.
- **Password Transmission via SMS**: The password is sent to a predefined mobile number using a GSM module.
- **Keypad Input**: Users can enter the password using a 4x4 keypad.
- **LCD Feedback**: Displays messages and feedback during operation.
- **Relay Control**: Activates a relay upon correct password entry.

## Requirements

### Hardware
- **Arduino Board** (e.g., Uno, Mega)
- **GSM Module** (e.g., SIM800L, SIM900)
- **4x4 Keypad**
- **16x2 LCD** (with or without I2C)
- **Relay Module**
- **Power Supply** for GSM module and relay
- **Jumper Wires**

### Software
- **Arduino IDE**
- Required Libraries:
  - `Password`
  - `Keypad`
  - `LiquidCrystal`
  - `GSMSim`

## Setup and Wiring

### Keypad
- Connect the keypad's row and column pins to the Arduino as defined in the code.

### GSM Module
- **VCC**: Connect to 5V (or external power supply if required).
- **GND**: Connect to Arduino GND.
- **TX**: Connect to RX on Arduino.
- **RX**: Connect to TX on Arduino.

### Relay
- Connect the relay pin to pin `10` on the Arduino.

### LCD
- Connect the LCD pins to the Arduino as per the configuration in the code.

## Usage
1. **Setup the System**:
   - Power on the system.
   - The LCD displays "Design Project" and "Circuit Breaker".

2. **Password Transmission**:
   - A random 4-digit password is generated and sent to the predefined phone number.

3. **Enter the Password**:
   - Use the keypad to enter the password.
   - Press `*` to evaluate the entered password.
   - Press `#` to reset the entered password.

4. **Feedback**:
   - If the password is correct, "Access Granted" is displayed, and the relay is activated.
   - If the password is incorrect, "Access Denied" is displayed.

## Notes
- Replace the placeholder phone number (`+9********`) with the actual recipient's number.
- Ensure proper power supply for the GSM module and relay.

## Troubleshooting
- **GSM Module Not Responding**:
  - Verify connections and power supply.
  - Check the GSM network coverage.
- **No SMS Sent**:
  - Ensure the correct phone number and GSM SIM card balance.

## License
This project is licensed under the [MIT License](./LICENSE).

## Author
**Sai Teja Jarabala**

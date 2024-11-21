# RFID Access Control System

## Overview
This project implements an RFID-based access control system using an Arduino. An RFID reader (MFRC522) scans RFID cards or tags, and based on the UID of the card, access is granted or denied. Visual and audio feedback is provided using LEDs and a buzzer.

## Features
- **RFID Scanning**: Reads the UID of RFID cards or tags.
- **Access Control**: Grants or denies access based on the UID.
- **Visual Feedback**: Green LED for access granted, red LED for access denied.
- **Audio Feedback**: Buzzer sound for access denied.

## Requirements

### Hardware
- **Arduino Board** (e.g., Uno, Mega)
- **MFRC522 RFID Reader**
- **RFID Tags or Cards**
- **Green LED** (for access granted)
- **Red LED** (for access denied)
- **Buzzer**
- **Jumper Wires and Breadboard**

### Software
- **Arduino IDE**
- Required Libraries:
  - `SPI`
  - `MFRC522`

## Setup and Wiring

### RFID Reader
- **SDA (SS)**: Connect to pin `10`
- **SCK**: Connect to pin `13`
- **MOSI**: Connect to pin `11`
- **MISO**: Connect to pin `12`
- **RST**: Connect to pin `9`
- **3.3V**: Connect to 3.3V on Arduino
- **GND**: Connect to GND on Arduino

### LEDs and Buzzer
- **Green LED (LED_G)**: Connect to pin `5`
- **Red LED (LED_R)**: Connect to pin `7`
- **Buzzer**: Connect to pin `6`

### Power
- Ensure the RFID reader is connected to a reliable 3.3V power source.

## Usage
1. **Upload the Code**:
   - Use the Arduino IDE to upload the provided code to your Arduino board.

2. **Replace the UID**:
   - Update the `content.substring(1) == "D0 10 22 25"` line in the code with your RFID tag's UID. The UID can be obtained from the Serial Monitor.

3. **Run the System**:
   - Open the Serial Monitor to observe the scanned UID and access control decisions.
   - Scan RFID cards or tags on the RFID reader.

4. **Feedback**:
   - **Access Granted**: Green LED turns on for 500ms.
   - **Access Denied**: Red LED and buzzer activate for 500ms.

## Troubleshooting
- **No UID Detected**:
  - Check the wiring and ensure the RFID reader is powered correctly.
- **Incorrect Access Decision**:
  - Verify the UID in the code matches the authorized RFID tag's UID.
- **Buzzer Not Working**:
  - Check the connection of the buzzer and ensure the pin is correctly defined.

## Notes
- Replace the default UID in the code with the UID of your RFID tag or card.
- The UID format in the code is hexadecimal and must be in uppercase.

## License
This project is licensed under the [MIT License](./LICENSE).

## Author
**Sai Teja Jarabala**

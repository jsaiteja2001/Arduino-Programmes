# Scrolling Text on Dot Matrix Display (DMD)

## Overview
This project uses a Dot Matrix Display (DMD) to display scrolling text dynamically updated via Serial communication. The text scrolls across the display, providing a visual representation of the received data.

## Features
- **Dynamic Text Update**: Updates the displayed text in real-time based on Serial input.
- **Scrolling Marquee**: Smooth scrolling text across the DMD.
- **Customizable Font**: Supports various fonts for different display aesthetics.

## Requirements

### Hardware
- **Arduino Board** (e.g., Uno, Mega)
- **Dot Matrix Display (DMD) Panel**
- **DMD Controller Shield** (compatible with your DMD)
- **Power Supply** for the DMD
- **Jumper Wires**

### Software
- **Arduino IDE**
- Required Libraries:
  - `DMD`
  - `TimerOne`
  - `SPI`
  - `SystemFont5x7`
  - `Arial_black_16`

## Setup and Wiring

### DMD Connections
- **SDA**: Connect to Arduino SDA pin.
- **SCL**: Connect to Arduino SCL pin.
- **Power Supply**: Ensure the DMD is connected to an external power supply capable of delivering sufficient current.

### Software Setup
1. Install the required libraries in the Arduino IDE.
2. Connect the DMD to your Arduino as per the manufacturer's instructions.

## Usage
1. **Upload the Code**:
   - Use the Arduino IDE to upload the provided code to your Arduino board.

2. **Send Data via Serial**:
   - Open the Serial Monitor.
   - Enter the text you want to display on the DMD and press Enter.

3. **View the Output**:
   - The text will scroll across the DMD in a marquee style.
   - The prefix "Score:" is added before the input data.

## Customization
- **Change Font**:
  - Modify the `#define FONT Arial_Black_16` line to use a different font.
- **Adjust Scrolling Speed**:
  - Change the `timing + 30` value in the code to make the marquee scroll faster or slower.

## Troubleshooting
- **No Text Displayed**:
  - Check the connections between the Arduino and the DMD.
  - Verify the power supply to the DMD.
  - Ensure the correct font and DMD dimensions are set in the code.

- **Text Display Issues**:
  - Verify the Serial Monitor is set to match the baud rate (`115200`).
  - Check the DMD library compatibility with your panel.

## License
This project is licensed under the [MIT License](./LICENSE).

## Author
**Sai Teja Jarabala**

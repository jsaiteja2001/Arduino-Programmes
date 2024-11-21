# RTC Clock with LCD Display

## Overview
This project displays real-time clock (RTC) data, including the current date, time, and day of the week, using a DS3231 RTC module. The data is displayed on a 16x2 LCD and printed to the Serial Monitor.

## Features
- **Real-Time Clock**: Displays accurate date and time using the DS3231 RTC module.
- **LCD Display**: Shows the date, time, and day of the week on a 16x2 I2C LCD.
- **Serial Output**: Prints the current date, time, and day of the week to the Serial Monitor.

## Requirements

### Hardware
- **Arduino Board** (e.g., Uno, Mega)
- **DS3231 RTC Module**
- **16x2 I2C LCD**
- **Jumper Wires**
- **Breadboard**

### Software
- **Arduino IDE**
- Required Libraries:
  - `DS3231`
  - `Wire`
  - `LiquidCrystal_I2C`

## Setup and Wiring

### RTC Module Connections
- **SDA**: Connect to Arduino SDA pin (A4 on Uno, 20 on Mega)
- **SCL**: Connect to Arduino SCL pin (A5 on Uno, 21 on Mega)
- **VCC**: Connect to 5V
- **GND**: Connect to GND

### LCD Connections
- **SDA**: Connect to Arduino SDA pin (A4 on Uno, 20 on Mega)
- **SCL**: Connect to Arduino SCL pin (A5 on Uno, 21 on Mega)
- **VCC**: Connect to 5V
- **GND**: Connect to GND

## Usage
1. **Setup the Code**:
   - Upload the provided code to your Arduino using the Arduino IDE.
   - Uncomment the `rtc.setDOW()`, `rtc.setTime()`, and `rtc.setDate()` lines in the `setup()` function to set the initial date and time.

2. **Run the System**:
   - Open the Serial Monitor to view the current date and time.
   - The LCD will display the date, time, and day of the week.

## Example Output
### LCD Display

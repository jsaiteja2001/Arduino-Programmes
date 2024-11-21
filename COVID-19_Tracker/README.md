# ESP8266 Covid-19 Data Display on LCD

## Overview
This project fetches Covid-19 statistics (confirmed cases, deaths, and recoveries) for a specific country using an ESP8266 module. The data is retrieved from a public API and displayed on a 16x2 LCD screen via I2C.

## Features
- Fetches Covid-19 data for any specified country.
- Displays the data on a 16x2 LCD.
- Automatically updates data every 60 seconds.
- Connects to WiFi for fetching live data.

## Requirements
### Hardware
- ESP8266 Module (e.g., NodeMCU)
- 16x2 LCD with I2C Backpack
- Jumper wires and breadboard
- WiFi network for internet access

### Libraries
- `ESP8266HTTPClient`: For HTTP requests.
- `Wire`: For I2C communication.
- `LiquidCrystal_I2C`: For LCD control via I2C.
- `json_parser.h`: Custom JSON parser for handling API responses.
- `WifiConnect.h`: Custom WiFi connection utility.

### API
- The data is fetched from the [Coronavirus API](http://coronavirus-19-api.herokuapp.com).

## Setup and Usage
1. **Connect the Hardware**:
   - Connect the LCD to the ESP8266 via I2C.
   - Ensure the ESP8266 is powered and connected to your computer.

2. **Install Dependencies**:
   - Add the required libraries to your Arduino IDE:
     - `ESP8266HTTPClient`
     - `Wire`
     - `LiquidCrystal_I2C`

3. **Configure the Code**:
   - Update the `country_code` macro with the desired country name (default: `"India"`).

4. **Upload the Code**:
   - Use the Arduino IDE to upload the code to your ESP8266.

5. **View Data**:
   - Once powered, the LCD will display Covid-19 statistics for the specified country.

## Troubleshooting
- **LCD Not Displaying Data**:
  - Check I2C connections and ensure the correct I2C address (`0x27`) is used.
- **WiFi Not Connecting**:
  - Verify SSID and password in the `WifiConnect.h` utility.
- **API Response Issues**:
  - Check the API endpoint in a browser for availability.

## License
This project is licensed under the [MIT License](./LICENSE).

## Author
**Sai Teja Jarabala**

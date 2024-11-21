/*
 * RTC Clock with LCD Display
 * Author: Sai Teja Jarabala
 *
 * Description:
 * This project displays the real-time clock (RTC) data (date, time, and day of the week)
 * on a 16x2 LCD using the DS3231 RTC module.
 * The current time and date are also printed to the Serial Monitor.
 */

#include <DS3231.h>               // Library for DS3231 RTC module
#include <Wire.h>                 // I2C communication library
#include <LiquidCrystal_I2C.h>    // Library for I2C LCD

// Initialize the LCD (I2C address: 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Initialize the DS3231 RTC module
DS3231 rtc(SDA, SCL);

void setup() {
  // Initialize LCD and turn on backlight
  lcd.init();
  lcd.backlight();

  // Start Serial communication
  Serial.begin(9600);

  // Initialize the RTC
  rtc.begin();

  // Uncomment the following lines to set the initial date and time
  // rtc.setDOW(FRIDAY);        // Set Day-of-Week (e.g., SUNDAY, MONDAY)
  // rtc.setTime(9, 58, 0);     // Set the time (24hr format: HH, MM, SS)
  // rtc.setDate(6, 12, 2019);  // Set the date (DD, MM, YYYY)
}

void loop() {
  // Get and display the current date and time on the Serial Monitor
  Serial.print(rtc.getDOWStr());       // Get day of the week as a string
  Serial.print(" ");
  Serial.print(rtc.getDateStr());      // Get date as a string (DD/MM/YYYY)
  Serial.print(" -- ");
  Serial.println(rtc.getTimeStr());    // Get time as a string (HH:MM:SS)

  // Display the date on the first row of the LCD
  lcd.setCursor(0, 0);
  lcd.print(rtc.getDateStr());

  // Display the time on the second row of the LCD
  lcd.setCursor(0, 1);
  lcd.print(rtc.getTimeStr());

  // Display the day of the week on the second row (starting at column 9)
  lcd.setCursor(9, 1);
  lcd.print(rtc.getDOWStr());

  // Wait for one second before updating the display
  delay(1000);
}

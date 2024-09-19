#include <DS3231.h> // RTC LIBRARY
#include <Wire.h> // WIRE LIBRARY 
#include <LiquidCrystal_I2C.h> //I2C LIBRARY 
LiquidCrystal_I2C lcd(0x27,16,2);
// Init the DS3231 using the hardware interface
DS3231 rtc(SDA, SCL);
void setup()
{
lcd.init(); 
lcd.backlight();
// Setup Serial connection
Serial.begin(9600);
// Initialize the rtc object
rtc.begin();
// The following lines can be uncommented to set the date and time
// rtc.setDOW(FRIDAY); // Set Day-of-Week to SUNDAY
// rtc.setTime(9, 58, 0); // Set the time to 12:00:00 (24hr format)
//rtc.setDate(6, 12, 2019); // Set the date to January 1st, 2014
}
void loop()
{
// Send Day-of-Week
Serial.print(rtc.getDOWStr());
Serial.print(" ");
// Send date
Serial.print(rtc.getDateStr());
Serial.print(" -- ");
// Send time
Serial.println(rtc.getTimeStr());
lcd.setCursor(0,0);
lcd.print(rtc.getDateStr ());
lcd.setCursor(0,1);
lcd.print(rtc.getTimeStr ());
lcd.setCursor(9,1);
lcd.print(rtc.getDOWStr());
// Wait one second before repeating :)
delay (1000);
}

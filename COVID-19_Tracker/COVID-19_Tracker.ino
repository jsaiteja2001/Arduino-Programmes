/*
 * ESP8266 Covid-19 Data Display on LCD
 * Author: Sai Teja Jarabala
 *
 * This project uses an ESP8266 module to fetch Covid-19 statistics for a specific country
 * from a public API and displays the data (confirmed cases, deaths, and recoveries)
 * on a 16x2 LCD screen via I2C.
 */

#include <ESP8266HTTPClient.h>  // HTTP client library for ESP8266
#include <Wire.h>               // I2C library
#include <LiquidCrystal_I2C.h>  // LCD library for I2C communication
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include "json_parser.h"  // Custom JSON parser for handling API responses
#include "WifiConnect.h"  // Custom WiFi connection utility

// Macro to convert seconds to milliseconds
#define s2ms(second) (second * 1000)

// API Configuration
#define country_code "India"  // Country code for fetching Covid-19 data

// Interval Configuration
int interval = s2ms(60);  // Update interval in milliseconds (60 seconds)
unsigned long long PreviousMillis = 0;
unsigned long long CurrentMillis = interval;
bool bFirstKickMillis = false;

// Flag to check if connected to WiFi
extern bool bGotIpFlag;

// Function to build the API URL
static String build_url_from_country(String country) {
  String url = "http://coronavirus-19-api.herokuapp.com/countries/";
  url += country;
  return url;
}

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Covid-19 Watch");
  lcd.setCursor(0, 1);
  lcd.print(" Case In INDIA ");

  #if defined JSON_DEBUG
    Serial.begin(9600);  // Initialize Serial Monitor for debugging
  #endif

  JSON_LOG("Connecting to WiFi...");

  // Connect to WiFi network
  vConnWifiNetworkViaSdk();
}

void loop() {
  // Handle WiFi connection
  if (bGotIpFlag) bGotIp();

  // Update the current time for periodic checks
  if (bFirstKickMillis) CurrentMillis = millis();

  // Fetch new data if connected to WiFi and the interval has elapsed
  if (!bGotIpFlag && CurrentMillis - PreviousMillis >= interval) {
    if (!bFirstKickMillis) CurrentMillis = 0;

    bFirstKickMillis = true;
    PreviousMillis = CurrentMillis;

    HTTPClient http;
    http.begin(build_url_from_country(country_code));  // Initialize HTTP request

    int httpCode = http.GET();  // Send the GET request

    // Check if the request was successful
    if (httpCode > 0) {
      String payload = http.getString();  // Get the API response as a string

      // Allocate memory for the JSON response
      char* JsonArray = (char *)malloc(payload.length() + 1);
      if (!JsonArray) JSON_LOG("Memory allocation failed!");

      payload.toCharArray(JsonArray, payload.length() + 1);  // Convert payload to C-string

      JSON_LOG(JsonArray);  // Debugging output

      // Parse and display the data if valid JSON is received
      if (json_validate(JsonArray)) {
        int confirmed = (int)get_json_value(JsonArray, "cases", INT);
        int deaths = (int)get_json_value(JsonArray, "deaths", INT);
        int recovered = (int)get_json_value(JsonArray, "recovered", INT);

        JSON_LOG(confirmed);
        JSON_LOG(deaths);
        JSON_LOG(recovered);

        // Display the data on the LCD
        lcd.clear();
        lcd.print("Cnfrmd");
        lcd.setCursor(7, 0);
        lcd.print("dths");
        lcd.setCursor(12, 0);
        lcd.print("rcvd");
        lcd.setCursor(0, 1);
        lcd.print(confirmed);
        lcd.setCursor(7, 1);
        lcd.print(deaths);
        lcd.setCursor(13, 1);
        lcd.print(recovered);
      }

      // Free allocated memory
      free(JsonArray);
    }

    http.end();  // Close the HTTP connection
  }
}

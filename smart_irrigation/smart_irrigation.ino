#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// LCD Display Configuration
LiquidCrystal_I2C lcd(0x27, 16, 2);

// DHT Sensor Configuration
#define DHTPIN 2        // DHT sensor data pin connected to D2
#define DHTTYPE DHT11   // DHT11 or DHT22 sensor
DHT dht(DHTPIN, DHTTYPE);

// Pin Definitions
#define SOIL_SENSOR_PIN 3 // Soil moisture sensor pin
#define PUMP_PIN 6        // Water pump control pin
#define WATER_LEVEL_PIN 4 // Water level sensor pin
#define LED_HIGH 5        // LED to indicate sufficient soil moisture
#define LED_LOW 7         // LED to indicate dry soil

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Initialize Sensors and Actuators
  pinMode(SOIL_SENSOR_PIN, INPUT);
  pinMode(WATER_LEVEL_PIN, INPUT);
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(LED_HIGH, OUTPUT);
  pinMode(LED_LOW, OUTPUT);

  // Initialize LCD Display
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Irrigation");
  delay(2000);
  lcd.clear();

  // Initialize DHT Sensor
  dht.begin();
}

void loop() {
  // Read Soil Moisture
  int soilMoisture = digitalRead(SOIL_SENSOR_PIN);

  // Read Water Level
  int waterLevel = digitalRead(WATER_LEVEL_PIN);

  // Read Temperature and Humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Display Environmental Data on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humidity);
  lcd.print("%");

  // Check for Sensor Errors
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.setCursor(0, 0);
    lcd.print("DHT Error");
    delay(2000);
    lcd.clear();
    return;
  }

  // Soil Moisture and Water Level Logic
  if (soilMoisture == HIGH && waterLevel == HIGH) {
    // Dry Soil and Water Available
    digitalWrite(PUMP_PIN, HIGH);  // Turn on the pump
    digitalWrite(LED_LOW, HIGH);  // Indicate dry soil
    digitalWrite(LED_HIGH, LOW);
    Serial.println("Soil is Dry. Pump ON.");
    lcd.setCursor(0, 1);
    lcd.print("Pump ON      ");
  } else if (soilMoisture == LOW) {
    // Soil is Moist
    digitalWrite(PUMP_PIN, LOW);  // Turn off the pump
    digitalWrite(LED_HIGH, HIGH); // Indicate sufficient moisture
    digitalWrite(LED_LOW, LOW);
    Serial.println("Soil is Moist. Pump OFF.");
    lcd.setCursor(0, 1);
    lcd.print("Pump OFF     ");
  } else if (waterLevel == LOW) {
    // Water Tank Empty
    digitalWrite(PUMP_PIN, LOW);  // Turn off the pump
    digitalWrite(LED_LOW, HIGH);  // Indicate low water
    Serial.println("Water Tank Empty.");
    lcd.setCursor(0, 1);
    lcd.print("No Water     ");
  }

  // Delay for Stability
  delay(2000);
}

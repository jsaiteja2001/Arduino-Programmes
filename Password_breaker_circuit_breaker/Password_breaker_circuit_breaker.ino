/*
 * Design Project: Circuit Breaker with GSM and Keypad
 * Author: Sai Teja Jarabala
 *
 * Description:
 * This project implements a GSM-based circuit breaker controlled by a keypad and password.
 * A random password is generated and sent via SMS to a predefined number.
 * The user enters the password using the keypad to unlock the circuit breaker.
 */

#include <Password.h>           // Library for handling passwords
#include <Keypad.h>             // Library for keypad interaction
#include <LiquidCrystal.h>      // Library for LCD interaction
#include <GSMSim.h>             // Library for GSM communication

// LCD Configuration
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// GSM and Password Configuration
GSMSim gsm;
#define BAUD 9600
Password password(1234); // Placeholder, updated with a random number later
long randNumber;          // Randomly generated password
int relay_pin = 10;       // Relay pin for circuit breaker

// Keypad Configuration
const byte ROWS = 4; // 4 rows
const byte COLS = 4; // 4 columns
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};       // Row pins connected to the Arduino
byte colPins[COLS] = {A0, A1, A2, A3};   // Column pins connected to the Arduino
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
    // Initialize relay pin and LCD
    pinMode(relay_pin, OUTPUT);
    lcd.begin(16, 2);
    lcd.print(" Design Project");
    lcd.setCursor(0, 1);
    lcd.print(" Circuit Breaker");
    delay(2000);
    lcd.clear();

    // Start Serial Communication
    Serial.begin(9600);
    Serial.println("Starting GSM Circuit Breaker System...");

    // Generate a random password
    randomSeed(analogRead(0));           // Seed the random generator
    randNumber = random(1000, 9999);     // Generate a 4-digit password
    password = Password(randNumber);     // Set the generated password
    Serial.print("Generated Password: ");
    Serial.println(randNumber);

    // Initialize GSM Module
    gsm.start();                         // Start GSM communication
    gsm.smsTextMode(true);               // Set SMS to text mode

    // Send Password via SMS
    char* number = "+9********";         // Replace with the recipient's phone number
    char message[16];
    snprintf(message, sizeof(message), "%ld", randNumber);
    Serial.println("Sending SMS...");
    if (gsm.smsSend(number, message)) {
        Serial.println("Password sent successfully!");
    } else {
        Serial.println("Failed to send SMS.");
    }

    // Attach Keypad Event Listener
    keypad.addEventListener(keypadEvent);
}

void loop() {
    // Continuously check for keypad input
    keypad.getKey();
}

// Handle Keypad Events
void keypadEvent(KeypadEvent eKey) {
    switch (keypad.getState()) {
        case PRESSED:
            lcd.setCursor(0, 0);
            lcd.print("Pressed: ");
            lcd.print(eKey);

            // Handle special keys
            switch (eKey) {
                case '*': // Evaluate the entered password
                    checkPassword();
                    break;
                case '#': // Reset the entered password
                    password.reset();
                    lcd.setCursor(0, 1);
                    lcd.print("Password Reset");
                    delay(2000);
                    lcd.clear();
                    break;
                default: // Append other keys to the password
                    password.append(eKey);
            }
    }
}

// Check the Entered Password
void checkPassword() {
    lcd.setCursor(0, 1);
    if (password.evaluate()) {
        lcd.print("Access Granted");
        digitalWrite(relay_pin, HIGH); // Activate relay
        delay(5000);                  // Keep the relay active for 5 seconds
        digitalWrite(relay_pin, LOW); // Deactivate relay
        lcd.clear();
    } else {
        lcd.print("Access Denied");
        delay(2000);
        lcd.clear();
    }
}

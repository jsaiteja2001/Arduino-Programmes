/*
 * Password Guessing Game
 * Author: Sai Teja Jarabala
 *
 * Description:
 * This program allows the user to guess a predefined password using the Serial Monitor. 
 * Users can append characters to their guess, reset the input, or evaluate their guess.
 * Feedback is provided on whether the entered password matches the predefined password.
 */

#include <Password.h> // Include the Password library

// Define the correct password
Password password = Password("1234");

// Variable to track the length of the current input
byte currentLength = 0;

void setup() {
  Serial.begin(9600); // Initialize Serial Communication
  
  // Welcome message
  Serial.println("Try to guess the password!");
  Serial.println("Reset with '!' and evaluate with '?'");
  Serial.print("Enter password: ");
}

void loop() {
  // Check if data is available on the serial port
  if (Serial.available()) {
    char input = Serial.read(); // Read the input character
    
    switch (input) {
      case '!': // Reset the entered password
        password.reset(); // Clear the entered password
        currentLength = 0; // Reset the current input length
        Serial.println("\tPassword is reset!");
        break;

      case '?': // Evaluate the entered password
        if (password.evaluate()) { // Check if the entered password matches
          Serial.println("\tYou guessed the correct password!");
        } else {
          Serial.println("\tYou did not guess the correct password!");
        }
        break;

      default: // Append any other input to the guessed password
        password.append(input); // Add the character to the password
        currentLength++; // Increment the input length
        
        // Display feedback
        Serial.print("Enter password: ");
        for (byte i = 0; i < currentLength; i++) {
          Serial.print('*'); // Mask the entered password for security
        }
        Serial.println();
    }
  }
}

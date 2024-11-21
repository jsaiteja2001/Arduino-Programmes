/*
 * Bluetooth Controlled Robot Car
 * Author: Sai Teja Jarabala
 *
 * Description:
 * This program allows controlling a robot car via Bluetooth using serial commands.
 * The robot can move forward, backward, left, and right, or stop based on the received command.
 *
 * Hardware Requirements:
 * - Arduino Board (e.g., Uno, Mega)
 * - Motor Driver Module (e.g., L298N)
 * - 2 DC Motors
 * - Bluetooth Module (e.g., HC-05/HC-06)
 * - Jumper Wires and Breadboard
 */

char val; // Variable to store incoming Bluetooth data

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud
  
  // Define motor control pins as OUTPUT
  pinMode(2, OUTPUT); // Motor A Forward
  pinMode(3, OUTPUT); // Motor A Backward
  pinMode(4, OUTPUT); // Motor B Forward
  pinMode(5, OUTPUT); // Motor B Backward
}

void loop() {
  // Check if data is available on the serial port
  if (Serial.available()) {
    val = Serial.read(); // Read the incoming data
    
    // Control robot movement based on the received command
    if (val == '0') { // Move Forward
      digitalWrite(2, HIGH); // Motor A Forward
      digitalWrite(3, LOW);  // Motor A Stop Backward
      digitalWrite(4, HIGH); // Motor B Forward
      digitalWrite(5, LOW);  // Motor B Stop Backward
    }
    else if (val == '1') { // Turn Left
      digitalWrite(2, LOW);  // Motor A Stop Forward
      digitalWrite(3, HIGH); // Motor A Backward
      digitalWrite(4, HIGH); // Motor B Forward
      digitalWrite(5, LOW);  // Motor B Stop Backward
    }
    else if (val == '2') { // Turn Right
      digitalWrite(2, HIGH); // Motor A Forward
      digitalWrite(3, LOW);  // Motor A Stop Backward
      digitalWrite(4, LOW);  // Motor B Stop Forward
      digitalWrite(5, HIGH); // Motor B Backward
    }
    else if (val == '3') { // Move Backward
      digitalWrite(2, LOW);  // Motor A Stop Forward
      digitalWrite(3, HIGH); // Motor A Backward
      digitalWrite(4, LOW);  // Motor B Stop Forward
      digitalWrite(5, HIGH); // Motor B Backward
    }
    else if (val == '4') { // Stop
      digitalWrite(2, LOW); // Stop Motor A Forward
      digitalWrite(3, LOW); // Stop Motor A Backward
      digitalWrite(4, LOW); // Stop Motor B Forward
      digitalWrite(5, LOW); // Stop Motor B Backward
    }
  }
}

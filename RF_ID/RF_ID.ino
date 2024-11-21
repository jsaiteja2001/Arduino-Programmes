/*
 * RFID Access Control System
 * Author: Sai Teja Jarabala
 *
 * Description:
 * This program uses an RFID reader (MFRC522) to scan RFID tags or cards.
 * Access is granted or denied based on the UID of the scanned card.
 * Green and red LEDs, along with a buzzer, provide feedback for the access decision.
 *
 * Hardware Requirements:
 * - Arduino Board (e.g., Uno, Mega)
 * - MFRC522 RFID Reader
 * - RFID Tags or Cards
 * - LEDs (Green and Red)
 * - Buzzer
 * - Jumper Wires and Breadboard
 */

#include <SPI.h>
#include <MFRC522.h>

// Pin Definitions
#define SS_PIN 10         // RFID SS (Slave Select) pin
#define RST_PIN 9         // RFID RST (Reset) pin
#define LED_G 5           // Green LED pin
#define LED_R 7           // Red LED pin
#define BUZZER 6          // Buzzer pin

// Create MFRC522 instance
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);                 // Initialize serial communication
  while (!Serial);                    // Wait for Serial Monitor to open (for boards like Arduino Leonardo)
  
  SPI.begin();                        // Initialize SPI bus
  mfrc522.PCD_Init();                 // Initialize RFID reader
  mfrc522.PCD_DumpVersionToSerial();  // Print RFID reader details

  Serial.println(F("Scan RFID tag to see UID and grant or deny access."));
  
  // Configure pins as outputs
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  // Check if a new RFID card is present
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return; // Exit loop if no new card is detected
  }

  // Attempt to read the RFID card
  if (!mfrc522.PICC_ReadCardSerial()) {
    return; // Exit loop if card reading fails
  }

  // Display the UID of the card in the Serial Monitor
  Serial.print("UID tag: ");
  String content = ""; // Store the UID as a string
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX); // Print UID in hexadecimal format
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  content.toUpperCase(); // Convert UID to uppercase for comparison

  // Check if the scanned UID matches the authorized UID
  if (content.substring(1) == "D0 10 22 25") { // Replace with your authorized UID
    Serial.println("Access Granted!");
    digitalWrite(LED_G, HIGH); // Turn on Green LED
    digitalWrite(LED_R, LOW);  // Turn off Red LED
    delay(500);
    digitalWrite(LED_G, LOW);  // Turn off Green LED
  } else {
    Serial.println("Access Denied!");
    digitalWrite(LED_R, HIGH);  // Turn on Red LED
    digitalWrite(LED_G, LOW);   // Turn off Green LED
    digitalWrite(BUZZER, HIGH); // Activate buzzer
    delay(500);
    digitalWrite(LED_R, LOW);   // Turn off Red LED
    digitalWrite(BUZZER, LOW);  // Deactivate buzzer
  }
}

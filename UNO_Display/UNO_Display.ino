/*
 * Scrolling Text on Dot Matrix Display (DMD)
 * Author: Sai Teja Jarabala
 *
 * Description:
 * This project uses a DMD (Dot Matrix Display) to display scrolling text sent via Serial communication.
 * The text is updated dynamically based on the input from the Serial Monitor.
 */

#include <Arial14.h>
#include <Arial_Black_16_ISO_8859_1.h>
#include <Arial_black_16.h>
#include <DMD.h>
#include <SystemFont5x7.h>
#include <SPI.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"
#include "Arial_black_16.h"
#include <SoftwareSerial.h>

// SoftwareSerial for additional serial communication (not used here but initialized)
SoftwareSerial am(4, 3); // RX | TX

// Define DMD dimensions
#define ROW 1               // Number of rows of DMD panels
#define COLUMN 1            // Number of columns of DMD panels
#define FONT Arial_Black_16 // Default font for the DMD

// Initialize variables
char cstr1[100];           // Buffer for storing the displayed message
DMD dmd(ROW, COLUMN);      // Create DMD instance
String data = "";          // Variable to store input data from Serial

// Function to scan and refresh the DMD display
void scanDMD() {
  dmd.scanDisplayBySPI();
}

void setup() {
  Serial.begin(115200);           // Start Serial communication
  Timer1.initialize(2000);        // Initialize Timer1 for periodic interrupts
  Timer1.attachInterrupt(scanDMD);// Attach interrupt to scan DMD
  dmd.clearScreen(true);          // Clear the DMD screen
}

void loop() {
  // Check if there is new data available on Serial
  if (Serial.available()) {
    data = Serial.readString(); // Read the incoming string
  }

  Serial.println(data); // Print the received data for debugging

  // Create a message string and convert it to a character array for the DMD
  (String("Score: ") + String(data)).toCharArray(cstr1, 100);

  // Set the font and draw the scrolling marquee
  dmd.selectFont(SystemFont5x7);
  dmd.drawMarquee(cstr1, 100, (32 * ROW), 0);

  long start = millis();
  long timing = start;
  boolean flag = false;

  // Scroll the text across the DMD until it completes
  while (!flag) {
    if ((timing + 30) < millis()) {
      flag = dmd.stepMarquee(-1, 0); // Move the marquee left by one step
      timing = millis();
    }
  }
}

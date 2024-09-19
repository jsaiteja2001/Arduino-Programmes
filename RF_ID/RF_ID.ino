#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
#define LED_G 5 //define green LED pin
#define LED_R 7 //define red LED
#define BUZZER 6 //buzzer pin
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.

void setup() 
{
Serial.begin(9600); // Initialize serial communications with the PC
while (!Serial); // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
SPI.begin(); // Init SPI bus
mfrc522.PCD_Init(); // Init MFRC522
mfrc522.PCD_DumpVersionToSerial(); // Show details of PCD - MFRC522 Card Reader details
Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));

pinMode(LED_G, OUTPUT);
pinMode(LED_R, OUTPUT);
pinMode(BUZZER, OUTPUT);

}
void loop() 
{
// Look for new cards
if ( ! mfrc522.PICC_IsNewCardPresent()) 
{
return;
}
// Select one of the cards
if ( ! mfrc522.PICC_ReadCardSerial()) 
{
return;
}
//Show UID on serial monitor
Serial.print("UID tag :");
String content= "";
byte letter;
for (byte i = 0; i < mfrc522.uid.size; i++) 
{
Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
Serial.print(mfrc522.uid.uidByte[i], HEX);
content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
content.concat(String(mfrc522.uid.uidByte[i], HEX));
}
Serial.println();
Serial.print("Message : ");
content.toUpperCase();

if (content.substring(1) == "D0 10 22 25")
//change here the UID of the card/cards that you want to give access
{
digitalWrite(LED_G, LOW);
digitalWrite(LED_R, HIGH);
delay(500);
digitalWrite(LED_R, LOW);
}
else 
{
digitalWrite(LED_G, HIGH);
digitalWrite(LED_R, LOW);
digitalWrite(BUZZER, HIGH);
delay(500);
digitalWrite(LED_G, LOW);
digitalWrite(BUZZER, LOW);
}
}

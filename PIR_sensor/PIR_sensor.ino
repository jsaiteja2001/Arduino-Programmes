/*
PIR HCSR501 
modified on 5 Feb 2019
by Saeed Hosseini @ ElectroPeak
https://electropeak.com/learn/guides/
*/ 
int pirPin = 2;                 // PIR Out pin 
int pirStat = 0;                   // PIR status
void setup() {
     
 pinMode(pirPin, INPUT);     
 Serial.begin(9600);
}
void loop(){
 pirStat = digitalRead(pirPin); 
 if (pirStat == HIGH) {            // if motion detected
  
   Serial.println("Hey I got you!!!");
 } 
 else {
   Serial.println("Nooooo!!!");
 }
delay(1000);
} 

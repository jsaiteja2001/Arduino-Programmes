//#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
char incomingByte;
int in=0;

//RH_ASK driver;

void setup()
{
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
}

void loop() 
{
 if (digitalRead(2)== LOW)
  {
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    Serial.print("forward");
  }
  else if (digitalRead(3)== LOW)
  {
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    Serial.print("backward");
  }
  else if (digitalRead(4)== LOW)
  {
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    Serial.print("left");  
  }
  else if (digitalRead(5)== LOW)
  {
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    Serial.print("Right");
  }
  delay(1000);
}

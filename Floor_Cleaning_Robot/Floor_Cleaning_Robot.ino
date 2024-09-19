char incomingByte;
#include<AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup()
{
  Serial.begin(9600);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
}
void loop()
{
  while(Serial.available()>0)
  {
    incomingByte = Serial.read();
    if(incomingByte==0x38)
    {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
    }
    else if(incomingByte==0x32)
    {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
 
  }
else if(incomingByte==0x36)
  {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  }
else if(incomingByte==0x34)
  {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  }
  else if(incomingByte==0x35)
  {  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  }
  if(incomingByte==0x31)
  {
    digitalWrite(8,HIGH);
    digitalWrite(10,LOW);
  }
  else if(incomingByte==0x33)
  {
    digitalWrite(8,LOW);
    digitalWrite(10,HIGH);
  }
  else if(incomingByte==0x30)
  {
    digitalWrite(8,LOW);
    digitalWrite(10,LOW);
  }
  if(incomingByte==0x37)
  {
    digitalWrite(11,LOW);
  }
  else if(incomingByte==0x39)
  {
    digitalWrite(11,HIGH);

  }
  }
}

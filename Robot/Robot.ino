#include <Servo.h>
Servo headservo;  //Head servo motor
Servo rsm;  //Right sholder motor
Servo lsm;  //Left sholder motor
Servo ram;  //Right arm motor
Servo lam;  //Left arm motor
int angle = 90;
char incomingByte;
void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(18,OUTPUT);
  headservo.attach(2);
  lsm.attach(3);
  rsm.attach(4);
  lam.attach(5);
  ram.attach(6);
  headservo.write(90);
  lsm.write(165);
  rsm.write(0);
  lam.write(0);
  ram.write(180);
}
void loop()
{
  while (Serial.available()>0)
    {
      //Read the incoming byte
      incomingByte = Serial.read();
    if (incomingByte == 0x38)
    {
      digitalWrite(12,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(8,LOW);
     
    }
    else if (incomingByte == 0x32)
    {
      digitalWrite(12,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(8,HIGH);
     
    }
    else if (incomingByte == 0x34)
    {
      digitalWrite(12,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      digitalWrite(8,HIGH);  
    }
    else if (incomingByte == 0x36)
    {
      digitalWrite(12,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(8,LOW);
    }
    else if (incomingByte == 0x35)
    {
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      digitalWrite(8,LOW);
     
    }
    else if(incomingByte == 0x37)
    {
      angle = angle+15;
      headservo.write(angle);  
    }
    else if(incomingByte == 0x39)
    {
      angle = angle - 15;
      headservo.write(angle);
    }
    else if(incomingByte == 0x31)
    {
      for(unsigned int ang=0;ang<=90;ang++)
      {
        lam.write(ang);
        ram.write(180-ang);
        delay(100);
        ang=ang+14;
      }
     
      for(unsigned int ang1=15;ang1<=75;ang1++)
      {
        lam.write(90-ang1);
        ram.write(90+ang1);
        lsm.write(165-ang1);
        rsm.write(ang1);
        delay(100);
        ang1=ang1+14;
      }
      for(unsigned int ang2=75;ang2>=15;ang2--)
      {
        lam.write(90-ang2);
        ram.write(90+ang2);
        lsm.write(165-ang2);
        rsm.write(ang2);
        delay(100);
        ang2 = ang2-14;
      }
      for(unsigned int ang3=0;ang3<=75;ang3++)
      {
        lam.write(75-ang3);
        ram.write(105+ang3);
        delay(100);
        ang3 = ang3 + 14;
      }
      for(unsigned int ang4=0;ang4<=15;ang4++)
      {
        lsm.write(150+ang4);
        rsm.write(15-ang4);
        delay(100);
        ang4 = ang4 + 5;
      }
      incomingByte=19;
    }
    else if(incomingByte==0x33)
    {
      for(unsigned int ang5=0; ang5<=105; ang5++)
      {
        rsm.write(ang5);
        ram.write(180-ang5);
        delay(100);
        ang5 = ang5 + 14;
      }
      delay(500);
      for(unsigned int ang6=105; ang6>=0;ang6--)
      {
        rsm.write(ang6);
        ram.write(180-ang6);
        delay(100);
        ang6=ang6-14;
      }
      incomingByte=19;
    }
    else if(incomingByte==19)
    {
    digitalWrite(18,HIGH);
    }
  }
}

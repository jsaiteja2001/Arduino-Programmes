#include <Servo.h>
Servo base;  //base servo motor
Servo shl;  //shoulder arm motor 
Servo elbow;  //Elbow Arm motor 2
Servo wrist;  //wrist Arm motor 
Servo wristroll; // wristroll motor
int angle = 90;
char incomingByte;
void setup() 
{
  Serial.begin(9600);
  base.attach(5);
  shl.attach(4);
  elbow.attach(3);
  wrist.attach(6);
  wristroll.attach(7);
  base.write(180);
  shl.write(10);
  elbow.write(10);
  wrist.write(0);
  wristroll.write(0);
}

void loop()
{
      for(unsigned int ang=0;ang<=180;ang++)
      {
        base.write(ang);
        delay(100);
        ang=ang+14;
      }
     for(unsigned int ang1=0;ang1<=45;ang1++)
     {
        shl.write(ang1);
        elbow.write(ang1*2);
        delay(100);
        ang1=ang1+14;
     }
     for(unsigned int ang=0;ang<=180;ang++)
      {
        elbow.write(ang);
        delay(0);
        ang=ang+14;
      }     
     for(unsigned int ang2=0;ang2<=90;ang2++)
     {
        wrist.write(ang2);
        wristroll.write(ang2/4);
        delay(150);
        ang2=ang2+14;
     }
     for(unsigned int ang=180;ang>=2;ang--)
     {
        base.write(ang);
        elbow.write(ang/2);
        delay(150);
        ang=ang-14;
        Serial.print("OK");
     }
}

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
  base.attach(3);
  shl.attach(4);
  elbow.attach(5);
  wrist.attach(6);
  wristroll.attach(7);
  base.write(90);
  shl.write(0);
  elbow.write(0);
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
     for(unsigned int ang1=0;ang1<=90;ang1++)
     {
        shl.write(ang1);
        elbow.write(ang1);
        delay(100);
        ang1=ang1+4;
     }
     for(unsigned int ang2=0;ang2<=45;ang2++)
     {
        wrist.write(ang2);
        wristroll.write(ang2/2);
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

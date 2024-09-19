//ARDUIUNO LINE FOLLOWER//

//Including Libarary
#include <AFMotor.h>

//Defining pins and Variable
#define left A0
#define right A1

//defining motors
AF_DCMotor motor1(1,MOTOR12_1KHZ);
AF_DCMotor motor2(2,MOTOR12_1KHZ);
AF_DCMotor motor3(3,MOTOR12_1KHZ);
AF_DCMotor motor4(4,MOTOR34_1KHZ);

void setup()
{
  Serial.begin(9600);
  motor1.setSpeed(120);
  motor2.setSpeed(120);
  motor3.setSpeed(120);
  motor4.setSpeed(120);
  //delcaring pin types
  pinMode(left,INPUT);
  pinMode(right,INPUT); 
}

void loop()
{
  //print values of sensor in serial monitor
  Serial.println(analogRead(left));
  Serial.println(analogRead(right));
  //line detected by both
  if (analogRead(left)<=400 && analogRead(right)<=400)
  { //stop
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  //LINE DETECTED BY LEFT SENSOR 
  else if (analogRead(left)<=400 && analogRead(right)<=400)
  { //turn left
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  }
  //LINE DETECTED BY RIGHT SENSOR
  else if (analogRead(left)<=400 && analogRead(right)<=400)
  { //turn left
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  //LINE DETECTED BY NONE
  else if (!analogRead(left)<=400 && !analogRead(right)<=400)
  { //stop
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }
}

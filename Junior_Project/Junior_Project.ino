char val;  
void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop()
{
  if (Serial.available() )
  {;}
val=Serial.read();
if (val=='0')  // Moving Forward
{
   digitalWrite(2,HIGH);
   digitalWrite(3,LOW);
   digitalWrite(4,HIGH);
   digitalWrite(5,LOW);
}
if(val=='1')// Moving left
{
   digitalWrite(2,LOW);
   digitalWrite(3,HIGH);
   digitalWrite(4,HIGH);
   digitalWrite(5,LOW);
}
if(val=='2')//Moving right
{
   digitalWrite(2,HIGH);
   digitalWrite(3,LOW);
   digitalWrite(4,LOW);
   digitalWrite(5,HIGH);
}
if(val=='3')//Moving backward
{
 digitalWrite(2,LOW);
 digitalWrite(3,HIGH);
 digitalWrite(5,LOW);
 digitalWrite(6,HIGH);
}
if(val=='4')// Stopping
{
   digitalWrite(2,LOW);
   digitalWrite(3,LOW);
   digitalWrite(4,LOW);
   digitalWrite(5,LOW);
}
}

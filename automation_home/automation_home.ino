void setup() 
{
Serial.begin(9600); // buart rate
pinMode(12,OUTPUT); // RELAY MODULE
pinMode(11,OUTPUT); // LED
digitalWrite(12,HIGH); // relay module high
}
void loop()
{
if(Serial.available()>0)
{ 
char data= Serial.read();
Serial.println(data);
if(data=='a')
{
digitalWrite(12,LOW); // RELAY ON
digitalWrite(13,HIGH); // LED ON
Serial.println("RELAY AND LED ON");
} 
if(data=='b')
{
digitalWrite(12,HIGH); // RELAY OFF
digitalWrite(13,LOW); // LED OFF
Serial.println("RELAY AND LED OFF");
} 
}
}

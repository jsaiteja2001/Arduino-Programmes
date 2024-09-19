float vs, k=0, vin, delta, ton, toff;
void cool()
{
  while(analogRead(A1)==k)
  {
 digitalWrite(9,HIGH);
 delay(ton);
 digitalWrite(9,LOW);
delay(toff);
}
}
void setup() 
{
 pinMode(A1,INPUT); 
pinMode(9,OUTPUT);
Serial.begin(9600);
}

void loop() {
  while(analogRead(A1)>0)
  {
 vin=analogRead(A1);
 vs=map(vin, 0, 1024, 0, 12);
 delta=(1-(vs/24));
 ton=delta*(20);
 toff=(20)-ton;
 Serial.print(ton);
 Serial.print("\n");
 k=vin;
 cool();
}
}

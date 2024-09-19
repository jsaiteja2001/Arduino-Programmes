int LED = 12;
int Rain_sensor = 3;
int Rain_detected;
void setup()
{
Serial.begin(9600);
pinMode(LED, OUTPUT);
pinMode(Rain_sensor, INPUT);
}
void loop()
{
Rain_detected = digitalRead(Rain_sensor);
Serial.println(Rain_detected);
delay(500);
if (Rain_detected == 0)
{
Serial.println("Rain detected...! take action immediately.");
digitalWrite(LED, HIGH);
}
else
{
Serial.println("No Rain detected. stay cool");
digitalWrite(LED, LOW);
}
}

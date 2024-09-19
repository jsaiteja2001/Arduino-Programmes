int LED_RED= 12;
int LED_GREEN= 11;
int BUZZER= 10;
int Rain_sensor = 3;
int Rain_detected;
void setup()
{
Serial.begin(9600);
pinMode(LED_RED, OUTPUT);
pinMode(LED_GREEN, OUTPUT);
pinMode(BUZZER, OUTPUT);
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
digitalWrite(LED_RED, HIGH);
digitalWrite(LED_GREEN, LOW);
digitalWrite(BUZZER, HIGH);
} 
else
{
Serial.println("No Rain detected. stay cool");
digitalWrite(LED_RED, LOW);
digitalWrite(BUZZER, LOW);
digitalWrite(LED_GREEN, HIGH);
}
}

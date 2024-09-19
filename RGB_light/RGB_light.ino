


void setup() {

Serial.begin(9600);

pinMode(8, OUTPUT);

pinMode(9, OUTPUT);

pinMode(10, OUTPUT);

}


void loop() {

digitalWrite(8,HIGH);

delay(500);

digitalWrite(9,HIGH);

delay(500);

digitalWrite(10,HIGH);

delay(500);

}

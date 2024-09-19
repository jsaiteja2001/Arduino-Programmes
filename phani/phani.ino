void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

      digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
      delay(2000);
      
      digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
      delay(1000);

}

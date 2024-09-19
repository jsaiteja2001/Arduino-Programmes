#include <Servo.h>
Servo controlmotor;
void setup() {
  Serial.begin(9600);
  controlmotor.attach(3);
  controlmotor.write(10);
}
void loop(){
controlmotor.write(0);
delay(1000);
controlmotor.write(25); 
delay(1000);

}

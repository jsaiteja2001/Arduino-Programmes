#define joyX A0
#define joyY A1
int xValue, yValue; 
void setup() {
 
  Serial.begin(9600);
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);
 
  //print the values with to plot or view
  Serial.print(xValue);
  delay(1000);
  Serial.print("\t");
  Serial.println(yValue);
  delay(1000);
}

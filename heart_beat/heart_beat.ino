
int output_Pin = A0;                                // initializing the sensor output pin
double alpha = 0.75;

int period = 500;
double change = 0.0;

void setup ( )                           // Code written in it will only run once.
{
  Serial.begin (9600);                                   // setting baud rate at 115200

}

void loop ()
{

    // initializing other variables
    static double oldValue = 0;
    static double oldChange = 0;
    int rawValue = analogRead (output_Pin);                                         // Reading the sensors values
    double value = alpha * oldValue + (1 - alpha) * rawValue;         // calculating values using the formu
    Serial.print (rawValue);              // printing the sensor output value on the screen
    Serial.print (",");                                                                                          
    Serial.println (value);             // printing the heart beat value on the screen
    oldValue = value;
    delay (period);

} 

#include <Password.h>
#include <Keypad.h> 
#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include <GSMSim.h>


#define BAUD 9600

long randNumber;
GSMSim gsm;

Password password = Password( randNumber);
int relay_pin = 10;

const byte ROWS = 4;
const byte COLS = 4; 
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = { 9,8,7,6 };
byte colPins[COLS] = { A0,A1,A2,A3 };


// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
   pinMode(relay_pin, OUTPUT);

  lcd.begin(16,2);

  lcd.print(" Design project");

  lcd.setCursor(0,1);

  lcd.print(" circuit breaker");

  delay(2000);

  lcd.clear();

Serial.begin(9600);

 
  randomSeed(analogRead(0));
  
randNumber = random(1000,9999);

  Serial.println(randNumber);

  
  delay(1000);
  lcd.setCursor(0,1);
  Serial.begin(9600);

  Serial.println("GSMSim Library - SMS Example");
  Serial.println("");
  delay(1000);

  gsm.start(); // baud default 9600
  //gsm.start(BAUD);

  Serial.println("Changing to text mode.");
  gsm.smsTextMode(true);

  char* number = "+9********";
  char* message = randNumber;

  Serial.println("Sending Message --->");
  Serial.println(gsm.smsSend(number, message)); 
  delay(2000);

  
  keypad.addEventListener(keypadEvent); 



  Serial.begin(9600);
  keypad.addEventListener(keypadEvent); 
}

void loop(){
  keypad.getKey();
}
 
//take care of some special events
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
  lcd. print("Pressed: ");
  lcd.println(eKey);
  switch (eKey){
    case '*': checkPassword(); break;
    case '#': password.reset(); break;
    default: password.append(eKey);
     }
  }
}

void checkPassword(){
  if (password.evaluate()){
   lcd.println("Success");
   
  }else{
   lcd.println("Wrong");
    
  }
}

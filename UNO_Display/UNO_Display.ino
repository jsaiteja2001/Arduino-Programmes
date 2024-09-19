#include <Arial14.h>
#include <Arial_Black_16_ISO_8859_1.h>
#include <Arial_black_16.h>
#include <DMD.h>
#include <SystemFont5x7.h>
#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"
#include "Arial_black_16.h"
#include <SoftwareSerial.h>

SoftwareSerial am(4, 3); // RX | TX 

#define ROW 1
#define COLUMN 1
#define FONT Arial_Black_16

char input;
int a = 0, b = 0;
int flag = 0;
char cstr1[100];
DMD dmd(ROW, COLUMN);
String data="";

void scanDMD(){
  dmd.scanDisplayBySPI();
}

void setup(void)

{
  Serial.begin(115200);
  Timer1.initialize(2000);
  Timer1.attachInterrupt(scanDMD);
  dmd.clearScreen( true );
}

void loop(void){

  if (Serial.available()){
    data=Serial.readString();
    }

Serial.println(data);

 (String("Score:")+String(data)).toCharArray(cstr1, 100);

    dmd.selectFont(SystemFont5x7);
    dmd.drawMarquee(cstr1,100, (32 * ROW), 0);
    long start = millis();
    long timming = start;
    boolean flag = false;
    while (!flag){
      if ((timming + 30) < millis()) 
      {
        flag = dmd.stepMarquee(-1, 0);
        timming = millis();
      }
   }
}
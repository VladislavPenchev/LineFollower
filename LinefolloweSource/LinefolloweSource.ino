#include <QTRSensors.h>

//Declaration and initialisation motors
int AIN1 = 2;
int AIN2 = 4;
int PWMA = 3;

int PWMB = 5;
int BIN1 = 6;
int BIN2 = 7;

int STENDBY = 12;

//Declaration and initialisation line pins
int zeroLineSensor_ANALOG = 0;
int firstLineSensor_ANALOG = 1;
int secondLineSensor_ANALOG = 2;
int thirdLineSensor_ANALOG = 3;
int fourthLineSensor_ANALOG = 4;                                                  
int fifthLineSensor_ANALOG = 5;

int eightLineSensor_Digital = 8; 
int ninghLineSensor_Digital = 9;

//array line pins
int arrayOfSensors[8] = {
eightLineSensor_Digital,
zeroLineSensor_ANALOG,
firstLineSensor_ANALOG,
secondLineSensor_ANALOG,
thirdLineSensor_ANALOG,
fourthLineSensor_ANALOG,
fifthLineSensor_ANALOG,
ninghLineSensor_Digital};

int startPoint[8] = {0,0,1024,1024,1024,1024,0,0};
int currentPoint[8];

int coefficient = 1;
int delta = 0;
int vL = 0;
int vR = 0;
//int deltaR = 0;
//int deltaL = 0;


void setup() {
//Set Pins like OUTPUT
//left motor
pinMode(PWMA,OUTPUT);   // WHY OUTPUT ??
pinMode(AIN1,OUTPUT);
pinMode(AIN2,OUTPUT);

//right motor
pinMode(PWMB,OUTPUT);
pinMode(BIN1,OUTPUT);
pinMode(BIN2,OUTPUT);

pinMode(STENDBY,OUTPUT); // WHAT IS STENDBY ?

//set pins of line
pinMode(zeroLineSensor_ANALOG, INPUT); // input ??
pinMode(firstLineSensor_ANALOG, INPUT);
pinMode(secondLineSensor_ANALOG, INPUT);
pinMode(thirdLineSensor_ANALOG, INPUT);
pinMode(fourthLineSensor_ANALOG, INPUT);
pinMode(fifthLineSensor_ANALOG, INPUT);
pinMode(eightLineSensor_Digital, INPUT);
pinMode(ninghLineSensor_Digital, INPUT);
  
Serial.begin(9600); // ??? komunikacionen kanal
}

void loop() {
  
 for (int i = 0; i < 8; i++ ) {

    if(arrayOfSensors[i] == eightLineSensor_Digital || arrayOfSensors[i] == ninghLineSensor_Digital){  
      currentPoint[i] = startPoint[i];//digitalRead(arrayOfSensors[i]); // Read value for two line digital pins
      }  
  
      currentPoint[i] = analogRead(arrayOfSensors[i]); // Read current value of line pins
 }
 delta=0;
    for(int i = 0; i < 8; i++ )
    {
      delta +=(coefficient*(startPoint[i] - currentPoint[i]))/1024;
//      deltaR = (coefficient*(startPoint[i] - currentPoint[i]))/1024;
//      deltaL = (coefficient*(startPoint[i] - currentPoint[i]))/1024;
      
    }
    vL = 150 + delta;
    vR = 150 - delta;

    if(vL < 0){
      vL = 0;
      }
    if(vL > 255){
      vL = 255;
      }

    if(vR < 0){
      vR = 0;
      }

    if(vR > 255){
      vR = 255;
      }
digitalWrite(AIN1,HIGH);
digitalWrite(AIN2,HIGH);
      analogWrite(PWMA,vL);
      digitalWrite(BIN1,HIGH);
digitalWrite(BIN2,HIGH);
      analogWrite(PWMB,vR);

     digitalWrite(STENDBY,HIGH);

  //left motor
//analogWrite(PWMA,150);
//digitalWrite(AIN1,HIGH);
//digitalWrite(AIN2,HIGH);
//
////right motor
//analogWrite(PWMB,150);
//digitalWrite(BIN1,HIGH);
//digitalWrite(BIN2,HIGH);
//
// 
//digitalWrite(STENDBY,HIGH);

}

#include <QTRSensors.h>

//Declaration and initialisation motors
int AIN1 = 2;
int AIN2 = 4;
int PWMA = 3;
int STENDBY = 12;

int PWMB = 5;
int BIN1 = 6;
int BIN2 = 7;

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
zeroLineSensor_ANALOG,
firstLineSensor_ANALOG,
secondLineSensor_ANALOG,
thirdLineSensor_ANALOG,
fourthLineSensor_ANALOG,
fifthLineSensor_ANALOG,
eightLineSensor_Digital,
ninghLineSensor_Digital};

int state[8] = {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH};
int reading[8]; // current reading ???
int previous[8]={LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW};

long time[8] = {0,0,0,0,0,0,0,0};
long debounce = 200;

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
  
Serial.begin(9600); // ???
}

void loop() {
  
 for (int i = 0; i < 8; i++ ) {

    if(arrayOfSensors[i] == eightLineSensor_Digital || arrayOfSensors[i] == ninghLineSensor_Digital){  
      reading[i] = digitalRead(arrayOfSensors[i]); // Read value for two line digital pins
      }  
  
      reading[i] = analogRead(arrayOfSensors[i]); // Read current value of line pins

      //my logic 
      if(arrayOfSensors[i] == eightLineSensor_Digital){
        if(state[i] > 200 && state[i-1] == HIGH && state[i-2] == HIGH){
          //right motor in power
          BIN1 = HIGH;
          BIN2 = 4;
          PWMB = 3;

          //left motor short brake or long PWM
          AIN1 = LOW;
          AIN2 = HIGH;
          PWMA = LOW;
          }
        }
 

  if (reading[i] == HIGH && previous[i] == LOW && millis() - time[i] > debounce) { // ?????
    if (state[i] == HIGH){
      state[i] = LOW;
          }
    else{
      state[i] = HIGH;
    }
    
    time[i] = millis();        
  }
    previous[i] = reading[i];
    //Serial.print(state[i]);
    //Serial.print(",");
    Serial.print(reading[i]);
    Serial.print("   ");
 }
 Serial.println();

  //digitalWrite(outPin, state[i]);

  //left motor
analogWrite(PWMA,155);
digitalWrite(AIN1,HIGH);
digitalWrite(AIN2,HIGH);

//right motor
analogWrite(PWMB,155);
digitalWrite(BIN1,HIGH);
digitalWrite(BIN2,HIGH);

 
digitalWrite(STENDBY,HIGH);

}

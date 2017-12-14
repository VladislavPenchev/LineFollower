#include <QTRSensors.h>

int firstSensorDigital = 7;                                                   
int secondSensor = 5;
int thirdSensor = 4;
int fourthSensor = 3;
int fifthSensor = 2;
int sixthSensor = 1;
int seventhSensor = 0;
int eighthSensorDigital = 8;


int arrayOfSensors[8] = {firstSensorDigital,secondSensor,thirdSensor,fourthSensor,fifthSensor,sixthSensor,seventhSensor,eighthSensorDigital};

int state[8] = {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH};      // the current state of the output pin
int reading[8];           // the current reading from the input pin
int previous[8]={LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW};    // the previous reading from the input pin

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time[8] = {0,0,0,0,0,0,0,0};         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

void setup()
{
  pinMode(firstSensorDigital, INPUT);
  pinMode(secondSensor, INPUT);
  pinMode(thirdSensor, INPUT);
  pinMode(fourthSensor, INPUT);
  pinMode(fifthSensor, INPUT);
  pinMode(sixthSensor, INPUT);
  pinMode(seventhSensor, INPUT);
  pinMode(eighthSensorDigital, INPUT);
  
  Serial.begin(9600);
}

void loop()
{

   for (int i = 0; i < 8; i++ ) {

    if(arrayOfSensors[i] == 7 || arrayOfSensors[i] == 8){
      reading[i] = digitalRead(arrayOfSensors[i]);
      }  
  
      reading[i] = analogRead(arrayOfSensors[i]);
  

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading[i] == HIGH && previous[i] == LOW && millis() - time[i] > debounce) {
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


}


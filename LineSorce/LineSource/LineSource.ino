#include <QTRSensors.h>

int seventhSensor_ANALOG = 0;
int sixthSensor_ANALOG = 1;
int fifthSensor_ANALOG = 2;
int fourthSensor_ANALOG = 3;
int thirdSensor_ANALOG = 4;                                                  
int secondSensor_ANALOG = 5;

int firstSensor_Digital = 8; 
int eighthSensor_Digital = 9;


int arrayOfSensors[8] = {firstSensor_Digital,secondSensor_ANALOG,thirdSensor_ANALOG,fourthSensor_ANALOG,fifthSensor_ANALOG,sixthSensor_ANALOG,seventhSensor_ANALOG,eighthSensor_Digital};

int state[8] = {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH};      // the current state of the output pin
int reading[8];           // the current reading from the input pin
int previous[8]={LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW};    // the previous reading from the input pin

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time[8] = {0,0,0,0,0,0,0,0};         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

void setup()
{
  pinMode(firstSensor_Digital, INPUT);
  pinMode(secondSensor_ANALOG, INPUT);
  pinMode(thirdSensor_ANALOG, INPUT);
  pinMode(fourthSensor_ANALOG, INPUT);
  pinMode(fifthSensor_ANALOG, INPUT);
  pinMode(sixthSensor_ANALOG, INPUT);
  pinMode(seventhSensor_ANALOG, INPUT);
  pinMode(eighthSensor_Digital, INPUT);
  
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


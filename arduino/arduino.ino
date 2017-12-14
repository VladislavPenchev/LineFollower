int ledPin1 = 6;
int brightness = 0;
int fade = 10;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin1, OUTPUT);
  Serial.
}

// the loop function runs over and over again forever
void loop() {
  analogWrite(ledPin1,brightness);
  brightness = brightness + fade;

  if(brightness == 0){
    fade = 0;
     fade =fade + 10;     
    }
    
  if(brightness == 255)
  {
    fade = 0;
    fade = fade - 10;
  }

  delay(10000);
}
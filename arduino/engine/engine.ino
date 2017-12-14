void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);

  digitalWrite(7,HIGH);

}

void loop() {
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  
  analogWrite(3,255);
  delay(10000);

  digitalWrite(2,LOW);
  digitalWrite(4,HIGH);
  delay(1000);
  
}

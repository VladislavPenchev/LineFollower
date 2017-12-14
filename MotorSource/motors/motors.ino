int PWM = 3;
int AIN1 = 2;
int AIN2 = 4;
int STENDBY = 12;

void setup() {
pinMode(PWM,OUTPUT);
pinMode(AIN1,OUTPUT);
pinMode(AIN2,OUTPUT);
pinMode(STENDBY,OUTPUT);

}

void loop() {
//left motor
analogWrite(PWM,254);
digitalWrite(AIN1,HIGH);
digitalWrite(AIN2,HIGH); 
digitalWrite(STENDBY,HIGH);

}

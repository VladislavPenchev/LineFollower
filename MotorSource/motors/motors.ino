//Declaration and iniinitialisation
int AIN1 = 2;
int AIN2 = 4;
int PWMA = 3;
int STENDBY = 12;

int PWMB = 5;
int BIN1 = 6;
int BIN2 = 7;


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

}

void loop() {
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

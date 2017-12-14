int led = 9;
int brightness = 0;
int fade = 5;

void setup() {
pinMode(led,OUTPUT);
}

void loop() {
analogWrite(led,brightness);
brightness = brightness + fade;
if(brightness == 0 || brightness == 255)
{
  fade = -fade;
}
delay(200);
}

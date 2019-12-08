#include <Servo.h>

Servo servo;
float sinal;
int pos;
bool led = HIGH;
void setup() {
  
  Serial.begin(9600);
  servo.attach(5);
  servo.write(0);
}

void loop() {
  if(Serial.read()=='a')
  {
    led = !led;
    digitalWrite(13,led);
  }else
  {
    if(Serial.available())
    {
      sinal = Serial.parseFloat();
      pos = map(sinal, -10.00, 10.00,0,180);
      servo.write(pos);
    }
  }

}

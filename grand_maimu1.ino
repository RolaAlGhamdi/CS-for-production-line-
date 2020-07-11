#include <Servo.h>
Servo moto;
int x = 0;
int d = 0;

void setup()
{
  moto.attach(5);
  pinMode(10, OUTPUT);
  pinMode(9, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(10, LOW);
  delayMicroseconds(2);
  
  digitalWrite(10, HIGH);
  delayMicroseconds(10);
  digitalWrite(10, LOW);
  
  x = pulseIn(9, HIGH);
  d = x*0.034/2;
  Serial.print("Dimension");
  Serial.println(d);
  
  if (d<300 && d>200)
  {
    moto.write(135);
  }
  else if (d<199 && d>100)
  {
    moto.write(90);
  }
  else if (d<99 && d>0)
  {
    moto.write(45);
  }
}
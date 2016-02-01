#include "Motor.h"
#include "Arduino.h"

Motor::Motor(int pin)
{
  _pin = pin;

  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
}

void Motor::activate(int ms)
{
  digitalWrite(_pin, LOW);
  delay(ms);
  digitalWrite(_pin, HIGH);
}

void Motor::reverseActivate(int ms)
{
}


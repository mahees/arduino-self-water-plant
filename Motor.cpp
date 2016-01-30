#include "Motor.h"
#include "Arduino.h"

Motor::Motor(int pin)
{
  _pin = pin;

  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}

void Motor::activate(int ms)
{
  digitalWrite(_pin, HIGH);
  delay(ms);
  digitalWrite(_pin, LOW);
}

void Motor::reverseActivate(int ms)
{
}


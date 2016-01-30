#include "DigitalPin.h"
#include "Arduino.h"

DigitalPin::DigitalPin(int pin)
{
  _pin = pin;

  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}

void DigitalPin::on()
{
  digitalWrite(_pin, HIGH);
}

void DigitalPin::off()
{
  digitalWrite(_pin, LOW);
}

void DigitalPin::toggle(int ms)
{
  DigitalPin::on();
  delay(ms);
  DigitalPin::off();
}



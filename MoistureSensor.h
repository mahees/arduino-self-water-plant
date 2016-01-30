#ifndef MoistureSensor_h
#define MoistureSensor_h

#include "Arduino.h"

class MoistureSensor
{
  public:
    MoistureSensor(int sensorPin, int vccPin);
    int takeReading();
  private:
    int _sensorPin;
    int _vccPin;
};

#endif

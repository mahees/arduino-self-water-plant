#ifndef MoistureSensor_h
#define MoistureSensor_h

#include "Arduino.h"

class MoistureSensor
{
  public:
    //requires a vcc pin so that we dont have it on unnecessarily and damage the sensor due to electrolysis
    MoistureSensor(int sensorPin, int vccPin);
    int takeReading();
  private:
    int _sensorPin;
    int _vccPin;
};

#endif

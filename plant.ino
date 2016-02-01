#include "MoistureSensor.h"
#include "Motor.h"
#include "DigitalPin.h"
#include "Logger.h"

MoistureSensor moistureSensor(A0, 13);
Motor waterPump(2);
DigitalPin buzzor(3);
//Logger logger(9600);

#define msReadSensorDelay 1200000
#define msBuzzorBeforeWateringDelay 100
#define msWateringActiveDelay 2000
#define msRetryAfterWateringDelay 30000
#define moistLevel 600


void setup() {
  Serial.begin(9600);

  waterPump.activate(msWateringActiveDelay);
}

void loop() {
  
  takeAndprocessReading();

  delay(msReadSensorDelay);
}


void takeAndprocessReading() {

  Serial.println("taking reading: ");
  int moistureReading = moistureSensor.takeReading();
  Serial.println(moistureReading);
  if (moistureReading < moistLevel)
  {
    Serial.println("soil moist");
    return;
  }

  Serial.println("soil dry: activating pump");
  buzzor.toggle(msBuzzorBeforeWateringDelay);
  waterPump.activate(msWateringActiveDelay);
  Serial.println("reading in a few secs");
  delay(msRetryAfterWateringDelay);
  takeAndprocessReading();
}

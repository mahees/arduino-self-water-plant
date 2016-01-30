
#include "MoistureSensor.h"
#include "Motor.h"
#include "DigitalPin.h"
#include "Logger.h"

MoistureSensor moistureSensor(A0, 13);
Motor waterPump(2);
DigitalPin buzzor(3);
Logger logger(9600);

//600000
#define msReadSensorDelay 10000
#define msBuzzorBeforeWateringDelay 100
#define msWateringActiveDelay 2000
#define msRetryAfterWateringDelay 15000
#define moistLevel 550


void setup() {

}

void loop() {
  takeAndprocessReading();

  delay(msReadSensorDelay);
}


void takeAndprocessReading() {

  logger.info("taking reading: ");
  int moistureReading = moistureSensor.takeReading();
  logger.info(moistureReading);
  if (moistureReading < moistLevel)
  {
    logger.info("soil moist");
    return;
  }

  logger.info("soil dry: activating pump");
  buzzor.toggle(msBuzzorBeforeWateringDelay);
  waterPump.activate(msWateringActiveDelay);
  logger.info("reading in a few secs");
  delay(msRetryAfterWateringDelay);
  takeAndprocessReading();
}

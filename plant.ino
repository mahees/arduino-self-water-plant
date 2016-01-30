
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

  logger.info("soil dry");
  logger.info("buzzor toggle");
  buzzor.toggle(msBuzzorBeforeWateringDelay);
  logger.info("buzzor toggle");
  logger.info("pump activate");
  waterPump.activate(msWateringActiveDelay);
  logger.info("pump deactivate");
  logger.info("waiting to take reading again");
  delay(msRetryAfterWateringDelay);
  takeAndprocessReading();
}

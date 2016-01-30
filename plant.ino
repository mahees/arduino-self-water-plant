
#include "MoistureSensor.h"
#include "Motor.h"
#include "DigitalPin.h"
#include "Logger.h"

MoistureSensor moistureSensor(A0, 13);
Motor waterPump(2);
DigitalPin buzzor(3);
Logger logger(9600);

void setup() {

}

void loop() {
  takeAndprocessReading();

  delay(10000); //10 seconds
  //delay(600000); //10 min
}


void takeAndprocessReading() {

  logger.info("taking reading: ");
  int moistureReading = moistureSensor.takeReading();
  logger.info(moistureReading);
  if (moistureReading < 550)
  {
    logger.info("soil moist");
    return;
  }

  logger.info("soil dry");
  logger.info("buzzor toggle");
  buzzor.toggle(100);
  logger.info("buzzor toggle");
  logger.info("pump activate");
  waterPump.activate(2000);
  logger.info("pump deactivate");
  logger.info("waiting to take reading again");
  delay(15000); //15 sec
  takeAndprocessReading();
}


#include "MoistureSensor.h"
#include "Motor.h"
#include "DigitalPin.h"

MoistureSensor moistureSensor(A0, 13);
Motor waterPump(2);
DigitalPin buzzor(3);

void setup() {
  Serial.begin(9600);
}

void loop() {
  takeAndprocessReading();

  delay(10000); //10 seconds
  //delay(600000); //10 min
}


void takeAndprocessReading() {

  Serial.print("taking reading: ");
  int moistureReading = moistureSensor.takeReading();
  Serial.println(moistureReading);
  if (moistureReading < 550)
  {
    Serial.println("soil moist");
    return;
  }

  Serial.println("soil dry");
  Serial.println("buzzor toggle");
  buzzor.toggle(100);
  Serial.println("buzzor toggle");
  Serial.println("pump activate");
  waterPump.activate(2000);
  Serial.println("pump deactivate");
  Serial.println("waiting to take reading again");
  delay(15000); //15 sec
  takeAndprocessReading();
}

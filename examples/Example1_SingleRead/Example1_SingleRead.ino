/******************************************************************************
  Reads sensor 0 and prints distance in cm over serial
  
  Original Creation Date: 18.09.2020

  Hardware Connections:
  SonarExtenderI2C over I2C

******************************************************************************/
#include <SonarExtenderI2C.h>

SonarExtenderI2C sonar;

void setup() {
  
  Serial.begin(9600);  
  
  sonar.begin(); // begin SonarExtender with default address
}

void loop() {

  sonar.read(0); // read sensor 0

  int distance = sonar.getMeasurementCm(0); // get distance in cm

  Serial.println(distance);

}

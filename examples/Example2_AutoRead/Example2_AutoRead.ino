/******************************************************************************
  Reads all 4 sensors using the autoreading feature and it's interrupt 
  and prints distance over serial
  
  Original Creation Date: 18.09.2020

  Hardware Connections:
  SonarExtenderI2C over I2C
  Pin 2: Interrupt pin of SonarExtenderI2C

******************************************************************************/
#include <SonarExtenderI2C.h>

#define SONAREXTENDER_INT 2

SonarExtenderI2C sonar;

void setup() {
  
  Serial.begin(9600);  

  // set up interrupt pin
  pinMode(SONAREXTENDER_INT, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SONAREXTENDER_INT), interruptHandler, RISING);
  
  sonar.begin(); // begin SonarExtender with default address
  delay(500); // wait a bit
  sonar.startAutoread(); // start autoreading feature
}

void loop() {

  // Latest sensor values are always available
  Serial.println("Sensorvalues in cm:");
  Serial.println(sonar.getMeasurementCm(0));
  Serial.println(sonar.getMeasurementCm(1));
  Serial.println(sonar.getMeasurementCm(2));
  Serial.println(sonar.getMeasurementCm(3));

}

void interruptHandler()
{
  sonar.autoreadCallback(); // do evaluation of all 4 sensors and restart autoreading feature
}

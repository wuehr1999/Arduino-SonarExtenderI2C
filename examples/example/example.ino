#include "SonarExtenderI2C.h"

SonarExtenderI2C sonar;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(2, INPUT);

  sonar.begin();
  sonar.startAutoread();
}

void loop() {
  // put your main code here, to run repeatedly:
  sonar.read(3);
  Serial.println(sonar.getMeasurementCm(3));
}

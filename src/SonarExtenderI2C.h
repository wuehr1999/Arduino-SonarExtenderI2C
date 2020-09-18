#ifndef SONAREXTENDERI2C_H
#define SONAREXTENDERI2C_H

#include <Arduino.h>

#include "TCA9535.h"

#define SONAREXTENDERI2C_TOCM(X) 100*X/2/30

class SonarExtenderI2C
{
  public:
  
  SonarExtenderI2C();

  /*!
   * @brief Starts communication on default address 0x20 and initializes IOs of SonarExtender
   */
  void begin();

  /*!
   * @brief Starts communication and initializes IOs of SonarExtender
   * @param address, I2C address
   */
  void begin(uint8_t address);
  
   /*!
   * @brief Returns latest raw value of the distance counters
   * @param sensorNumber, number of sensor from 0 - 4
   * @return counterVallue of specific sensor
   */
  uint8_t getMeasurementRaw(uint8_t sensorNumber);

   /*!
   * @brief Returns latest distance value of sensor 
   * @param sensorNumber, number of sensor from 0 - 4
   * @return distance in cm
   */
  uint8_t getMeasurementCm(uint8_t sensorNumber);

  /*!
   * @brief Evaluates all 4 sensors immediately
   */
  void read();

  /*!
   * @brief Evaluates specific sensor immediately
   * @param sensorNumber, number of sensor from 0 - 4
   */
  void read(uint8_t sensorNumber);

  /*!
   * @brief Starts autoread feature
   */
  void startAutoread();

  /*!
   * @brief Pauses autoread feature
   */
  void pauseAutoread();

  /*!
   * @brief Stops autoread feature
   */
  void stopAutoread();

  /*!
   * @brief Callback routine for evaluating all sensors with autoread feature, needs to be called when interrupt pin is rising
   */
  void autoreadCallback();
  
  private:

  TCA9535 tca;

  uint8_t interruptPin;

  uint8_t measurement0, measurement1, measurement2, measurement3;

  void trigger(uint8_t sensorNumber);
  void waitForEcho(uint8_t sensorNumber);
  void decode(uint8_t sensorNumber);
};

#endif

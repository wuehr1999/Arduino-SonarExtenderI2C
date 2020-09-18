#ifndef TCA9535_H
#define TCA9535_H

#include <Wire.h>

#define TCA9535_DEFAULTADDRESS 0x20

#define TCA9535_REGISTER_INPUT0 0b00000000
#define TCA9535_REGISTER_INPUT1 0b00000001
#define TCA9535_REGISTER_OUTPUT0 0b00000010
#define TCA9535_REGISTER_OUTPUT1 0b00000011
#define TCA9535_REGISTER_INVERT0 0b00000100
#define TCA9535_REGISTER_INVERT1 0b00000101
#define TCA9535_REGISTER_CONFIG0 0b00000110
#define TCA9535_REGISTER_CONFIG1 0b00000111


class TCA9535
{
  public:
 
  TCA9535();

  /*!
   * @brief Starts I2C connection with default address 0x20
   */
  void begin();

  /*!
   * @brief Starts I2C connection
   * @param address I2C Address
   */
  void begin(uint8_t address);

  /*!
   * @brief Writes to register
   * @param registerNumber, number of addressed register
   * @param value, Value to be written
   */

  void write(uint8_t registerNumber, uint8_t value);
  /*!
   * @brief Reads from register
   * @param registerNumber, number of addressed register
   * @return value of register
   */
  uint8_t read(uint8_t registerNumber);

  private:

  uint8_t address;
};

#endif

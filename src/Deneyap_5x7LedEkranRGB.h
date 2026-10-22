/**
  ******************************************************************************
  * @file    Deneyap_5x7LedEkranRGB.h
  * @author  cezer-io Team
  * @version V1.1.0
  * @date    21-Oct-2026
  * @brief   This file contains all function prototypes and macros
             for new generation (RGB) Deneyap 5x7 LED Matris
  ******************************************************************************
  */

#ifndef __DENEYAP_5X7LEDEKRAN_RGB_H
#define __DENEYAP_5X7LEDEKRAN_RGB_H

#include <Wire.h>
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#ifndef I2C_SLV_ADDR_DEFAULT
#define I2C_SLV_ADDR_DEFAULT    (uint8_t)0x0A
#endif
#ifndef I2C_SLV_ADDR_ALT1
#define I2C_SLV_ADDR_ALT1       (uint8_t)0x4A
#endif
#define LEDMATRIX_FRAME_HEADER  (uint8_t)0xCC
#define LEDMATRIX_COL_SIZE      5
#define LEDMATRIX_ROW_SIZE      7
#define NO_OF_LEDS              (LEDMATRIX_COL_SIZE * LEDMATRIX_ROW_SIZE)
#define LEDMATRIX_DATA_BUFFER_SIZE (3 * NO_OF_LEDS)                     // in Byte (max data size)
#define LEDMATRIX_FRAME_SIZE    (LEDMATRIX_DATA_BUFFER_SIZE + 4)        // header + command + dataSize + data + crc

typedef struct                                      // Data packet (protocol) created by master
{                                                   // for I2C data exchange process
  uint8_t header;
  uint8_t command;
  uint8_t dataSize;
  uint8_t data[LEDMATRIX_DATA_BUFFER_SIZE];
  uint8_t crc;
} LedMatrix_DataPacket_TypeDef;

enum LedMatrix_packetCommands                       // Commands in data packet (protocol)
{
  LEDMATRIX_DRIVE = (uint8_t)0x00,
  LEDMATRIX_CHANGE_ADDR
};

class RGB5x7LedMatris :public Adafruit_NeoPixel
{
  public:
    /* Constructor */
    RGB5x7LedMatris()
      : Adafruit_NeoPixel(NO_OF_LEDS, -1, NEO_GRB + NEO_KHZ800) {}

    /* Hidden original functions */
    bool show()
    {
      uint8_t *data = getPixels();
      uint8_t len = (uint8_t)numPixels() * 3;

      return driveLeds(data, len);
    }

    bool begin(uint8_t address = I2C_SLV_ADDR_DEFAULT, TwoWire &port = Wire);

    /* Check device status */
    bool isConnected();
    bool setI2Caddress(uint8_t newAddress);

    /* Helper functions (call show() afterwards) */
    bool setPixelXY(uint8_t row, uint8_t col, uint32_t color);                 // row: 1-7, col: 1-5
    void drawBitmap(const uint8_t bitmap[NO_OF_LEDS], uint32_t color);          // bitmap: 35 values (0/1), row by row

  private:
    TwoWire* _i2cPort;                              // Port selection (0 or 1)
    uint8_t _i2cAddress;                            // Device I2C address
    LedMatrix_DataPacket_TypeDef _dataPacket;       // Struct to transfer data over I2C interface

    /* Functions for data manipulation */
    bool driveLeds(const uint8_t *data, uint8_t len);

    /* I2C data transaction functions */
    bool I2C_SendDataPacket(LedMatrix_DataPacket_TypeDef* dataPacket);
    uint8_t I2C_Calculate_CRC(uint8_t crc, const uint8_t *data, uint8_t len);
};


#endif /* __DENEYAP_5X7LEDEKRAN_RGB_H */

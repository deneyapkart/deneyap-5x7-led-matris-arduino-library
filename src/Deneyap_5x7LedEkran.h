/*
*****************************************************************************
@file         Deneyap_5x7LedEkran.h
@mainpage     Deneyap 5X7 LED Matris Arduino library header file
@version      v1.1.0
@date         October 21, 2026
@brief        This file contains all function prototypes and macros
              for Deneyap 5x7 Dot Matrix Arduino library

              DotMatrix --> first generation module (STM8S003, single color)
              RGB5x7LedMatris --> new generation module (RGB), see Deneyap_5x7LedEkranRGB.h
*****************************************************************************
*/

#ifndef __Deneyap_5x7LedEkran_H
#define __Deneyap_5x7LedEkran_H

#include <Wire.h>
#include <Arduino.h>

#ifndef I2C_SLV_ADDR_DEFAULT
#define I2C_SLV_ADDR_DEFAULT (uint8_t)0x0A
#endif
#ifndef I2C_SLV_ADDR_ALT1
#define I2C_SLV_ADDR_ALT1 (uint8_t)0x4A
#endif
#define I2C_SLV_ADDR_ALT2 (uint8_t)(I2C_SLV_ADDR_DEFAULT + 2)
#define I2C_SLV_ADDR_ALT3 (uint8_t)(I2C_SLV_ADDR_DEFAULT + 3)
#define DATA_BUFFER_SIZE 5 // in Byte (max data size)

static const unsigned int COL_SIZE = 5; // Number LEDs in a column
static const unsigned int ROW_SIZE = 7; // Number LEDs in a row

static const unsigned int NUM_LEDS = COL_SIZE * ROW_SIZE;

typedef struct // Data packet (protocol) created by master
{              // for I2C data exchange process
    uint8_t command : 4;
    uint8_t dataSize : 3;
    byte data[DATA_BUFFER_SIZE];
} DotMatrix_DataPacket_TypeDef;

enum DotMatrix_packetCommands { // Commands in data packet (protocol)
    ROW1 = (uint8_t)0x00,
    ROW2,
    ROW3,
    ROW4,
    ROW5,
    ROW6,
    ROW7,
    DOTMATRIX_CHANGE_ADDR,
    DOTMATRIX_REQUEST_FW_VERSION,
};

class DotMatrix {
public:
    /* Check device status */
    bool begin(uint8_t address = I2C_SLV_ADDR_DEFAULT, TwoWire &port = Wire);
    bool isConnected();
    uint16_t getFwVersion();                  // (major << 8) | minor, 0 --> read error
    bool setI2Caddress(uint8_t newAddress);

    /* Functions for data manipulation */
    bool dotrow1(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5);
    bool dotrow2(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5);
    bool dotrow3(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5);
    bool dotrow4(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5);
    bool dotrow5(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5);
    bool dotrow6(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5);
    bool dotrow7(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5);
    void drawLedMatrix(const byte bitmap[NUM_LEDS], int duration = 100); // duration: number of refresh cycles
    bool pixelLed(uint8_t numRows, uint8_t numCols);                       // numRows: 1-7, numCols: 1-5
    void resetDotRows(void);

    /* ESP32 3.x uyumluluk fonksiyonu */
    bool checkI2CHealth(void);               // I2C bağlantı sağlığını kontrol et

    uint8_t i2cData2;                         // Firmware minor version (filled by getFwVersion)
    uint8_t i2cData1;                         // Firmware major version (filled by getFwVersion)

private:
    TwoWire *_i2cPort;                        // Port selection (0 or 1)
    uint8_t _i2cAddress;                      // Device I2C address
    DotMatrix_DataPacket_TypeDef _dataPacket; // Struct to transfer data over I2C interface

    void configureBus(void);
    bool sendRow(uint8_t row, uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5);

    /* I2C data transaction functions */
    bool I2C_SendDataPacket(DotMatrix_DataPacket_TypeDef *dataPacket);
};

#include "Deneyap_5x7LedEkranRGB.h"

#endif /* __Deneyap_5x7LedEkran_H */

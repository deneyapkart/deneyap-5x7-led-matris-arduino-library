/*
*****************************************************************************
@file         Deneyap_5x7LedEkran.h
@mainpage     Deneyap 5X7 LED Matris Arduino library header file
@version      v1.0.2
@date         November 07, 2022
@brief        This file contains all function prototypes and macros
              for Deneyap 5x7 Dot Matrix Arduino library

*****************************************************************************
*/

#ifndef __Deneyap_5x7LedEkran_H
#define __Deneyap_5x7LedEkran_H

#include <Wire.h>
#include <Arduino.h>

#define I2C_SLV_ADDR_DEFAULT (uint8_t)0x0A
#define I2C_SLV_ADDR_ALT1 (uint8_t)0x4A
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
    bool begin(uint8_t address, TwoWire &port = Wire);
    bool isConnected();
    uint16_t getFwVersion();
    bool setI2Caddress(uint8_t newAddress);

    /* Functions for data manipulation */
    bool dotrow1(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5);
    bool dotrow2(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5);
    bool dotrow3(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5);
    bool dotrow4(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5);
    bool dotrow5(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5);
    bool dotrow6(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5);
    bool dotrow7(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5);
    void drawLedMatrix(const byte bitmap[NUM_LEDS], int duration = 100);
    void pixelLed(uint8_t numRows, uint8_t numCols);
    void resetDotRows(void);

    uint8_t i2cData2;
    uint8_t i2cData1;

private:
    TwoWire *_i2cPort;                        // Port selection (0 or 1)
    uint8_t _i2cAddress;                      // Device I2C address
    DotMatrix_DataPacket_TypeDef _dataPacket; // Struct to transfer data over I2C interface

    /* I2C data transaction functions */
    uint8_t I2C_ReadData8bit(DotMatrix_DataPacket_TypeDef *dataPacket);
    uint16_t I2C_ReadData16bit(DotMatrix_DataPacket_TypeDef *dataPacket);
    bool I2C_SendDataPacket(DotMatrix_DataPacket_TypeDef *dataPacket);
    uint16_t I2C_ReadFirmwareData16bit(DotMatrix_DataPacket_TypeDef *dataPacket);
};

#endif /* __Deneyap_5x7LedEkran_H */

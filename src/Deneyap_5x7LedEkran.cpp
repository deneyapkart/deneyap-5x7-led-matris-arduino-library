/*
*****************************************************************************
@file         Deneyap_5x7LedEkran.cpp
@mainpage     Deneyap 5X7 LED Matris Arduino library source file
@maintainer   RFtek Electronics <techsupport@rftek.com.tr>
@version      v1.0.1
@date         June 22, 2022
@brief        Includes functions to control Deneyap 5x7 Dot Matrix 
              Arduino library

Library includes:
--> Configuration functions
--> Data manipulation functions
--> I2C communication functions
*****************************************************************************
*/

#include "Deneyap_5x7LedEkran.h"

/* Device Status Functions ---------------------------------------------------*/

/**
 * @brief  Configures I2C connection with user defined address and port
 * @param  address: I2C address of the device, port: I2C port number (0 or 1)
 * @retval connection status (1 --> connected, 0 --> not connected)
 */
bool DotMatrix::begin(uint8_t address, TwoWire &port) {
    Wire.begin();
#if defined(ARDUINO_DYM)
    Wire.setClock(100000);
#else
    Wire.setClock(50000);
#endif
    _i2cAddress = address;
    _i2cPort = &port;
    _dataPacket = {0};

    return isConnected();
}

/**
 * @brief  Checks whether I2C connection established
 * @param  None
 * @retval connection status (1 --> connected, 0 --> not connected)
 */
bool DotMatrix::isConnected() {
    _i2cPort->beginTransmission(_i2cAddress);

    if (_i2cPort->endTransmission() == 0)
    {
        resetDotRows();
        return true;
    }

    return false;
}

/**
 * @brief  Requests firmware version of the device
 * @param  None
 * @retval Device firmware version
 */
uint16_t DotMatrix::getFwVersion() {
    _dataPacket.command = DOTMATRIX_REQUEST_FW_VERSION;
    _dataPacket.dataSize = 0;
    return I2C_ReadFirmwareData16bit(&_dataPacket);
}

/**
 * @brief  Sets (changes) I2C address of the device
 * @param  address: I2C address to be set
 * @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
 */

bool DotMatrix::setI2Caddress(uint8_t newAddress) {
    _dataPacket.command = DOTMATRIX_CHANGE_ADDR;
    _dataPacket.dataSize = 1;
    _dataPacket.data[0] = newAddress;

    bool status = I2C_SendDataPacket(&_dataPacket);

    if (status == true) {
        _i2cAddress = newAddress;
        return true;
    }
    else {
        return false;
    }
}

/* I2C Data Manipulation Functions -------------------------------------------*/

/**
 * @brief  Sends dot marix  column data  based on data protocol format
 * @param  columnData: 0 to 1
 * @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
 */
bool DotMatrix::dotrow1(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5) {
    _dataPacket.command = (uint8_t)ROW1;
    _dataPacket.dataSize = (uint8_t)0x5;
    _dataPacket.data[0] = col1;
    _dataPacket.data[1] = col2;
    _dataPacket.data[2] = col3;
    _dataPacket.data[3] = col4;
    _dataPacket.data[4] = col5;
    return I2C_SendDataPacket(&_dataPacket);
}

/**
 * @brief
 * @param
 * @retval
 */
bool DotMatrix::dotrow2(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5) {
    _dataPacket.command = (uint8_t)ROW2;
    _dataPacket.dataSize = (uint8_t)0x5;
    _dataPacket.data[0] = col1;
    _dataPacket.data[1] = col2;
    _dataPacket.data[2] = col3;
    _dataPacket.data[3] = col4;
    _dataPacket.data[4] = col5;
    return I2C_SendDataPacket(&_dataPacket);
}

/**
 * @brief
 * @param
 * @retval
 */
bool DotMatrix::dotrow3(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5) {
    _dataPacket.command = (uint8_t)ROW3;
    _dataPacket.dataSize = (uint8_t)0x5;
    _dataPacket.data[0] = col1;
    _dataPacket.data[1] = col2;
    _dataPacket.data[2] = col3;
    _dataPacket.data[3] = col4;
    _dataPacket.data[4] = col5;
    return I2C_SendDataPacket(&_dataPacket);
}

/**
 * @brief
 * @param
 * @retval
 */
bool DotMatrix::dotrow4(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5) {
    _dataPacket.command = (uint8_t)ROW4;
    _dataPacket.dataSize = (uint8_t)0x5;
    _dataPacket.data[0] = col1;
    _dataPacket.data[1] = col2;
    _dataPacket.data[2] = col3;
    _dataPacket.data[3] = col4;
    _dataPacket.data[4] = col5;
    return I2C_SendDataPacket(&_dataPacket);
}

/**
 * @brief
 * @param
 * @retval
 */
bool DotMatrix::dotrow5(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5) {
    _dataPacket.command = (uint8_t)ROW5;
    _dataPacket.dataSize = (uint8_t)0x5;
    _dataPacket.data[0] = col1;
    _dataPacket.data[1] = col2;
    _dataPacket.data[2] = col3;
    _dataPacket.data[3] = col4;
    _dataPacket.data[4] = col5;
    return I2C_SendDataPacket(&_dataPacket);
}

/**
 * @brief
 * @param
 * @retval
 */
bool DotMatrix::dotrow6(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5) {
    _dataPacket.command = (uint8_t)ROW6;
    _dataPacket.dataSize = (uint8_t)0x5;
    _dataPacket.data[0] = col1;
    _dataPacket.data[1] = col2;
    _dataPacket.data[2] = col3;
    _dataPacket.data[3] = col4;
    _dataPacket.data[4] = col5;
    return I2C_SendDataPacket(&_dataPacket);
}

/**
 * @brief
 * @param
 * @retval
 */
bool DotMatrix::dotrow7(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5) {
    _dataPacket.command = (uint8_t)ROW7;
    _dataPacket.dataSize = (uint8_t)0x5;
    _dataPacket.data[0] = col1;
    _dataPacket.data[1] = col2;
    _dataPacket.data[2] = col3;
    _dataPacket.data[3] = col4;
    _dataPacket.data[4] = col5;
    return I2C_SendDataPacket(&_dataPacket);
}

/**
 * @brief
 * @param
 * @retval
 */
void DotMatrix::drawLedMatrix(const byte bitmap[NUM_LEDS]) {
    dotrow1(bitmap[0], bitmap[1], bitmap[2], bitmap[3], bitmap[4]);
    dotrow2(bitmap[5], bitmap[6], bitmap[7], bitmap[8], bitmap[9]);
    dotrow3(bitmap[10], bitmap[11], bitmap[12], bitmap[13], bitmap[14]);
    dotrow4(bitmap[15], bitmap[16], bitmap[17], bitmap[18], bitmap[19]);
    dotrow5(bitmap[20], bitmap[21], bitmap[22], bitmap[23], bitmap[24]);
    dotrow6(bitmap[25], bitmap[26], bitmap[27], bitmap[28], bitmap[29]);
    dotrow7(bitmap[30], bitmap[31], bitmap[32], bitmap[33], bitmap[34]);
}

/**
 * @brief
 * @param
 * @retval
 */
void DotMatrix::pixelLed(uint8_t numRows, uint8_t numCols) {
    switch (numRows) {
    case 1:
        if (numCols == 1)
            dotrow1(1, 0, 0, 0, 0);
        else if (numCols == 2)
            dotrow1(0, 1, 0, 0, 0);
        else if (numCols == 3)
            dotrow1(0, 0, 1, 0, 0);
        else if (numCols == 4)
            dotrow1(0, 0, 0, 1, 0);
        else if (numCols == 5)
            dotrow1(0, 0, 0, 0, 1);
        break;
    case 2:
        if (numCols == 1)
            dotrow2(1, 0, 0, 0, 0);
        else if (numCols == 2)
            dotrow2(0, 1, 0, 0, 0);
        else if (numCols == 3)
            dotrow2(0, 0, 1, 0, 0);
        else if (numCols == 4)
            dotrow2(0, 0, 0, 1, 0);
        else if (numCols == 5)
            dotrow2(0, 0, 0, 0, 1);
        break;
    case 3:
        if (numCols == 1)
            dotrow3(1, 0, 0, 0, 0);
        else if (numCols == 2)
            dotrow3(0, 1, 0, 0, 0);
        else if (numCols == 3)
            dotrow3(0, 0, 1, 0, 0);
        else if (numCols == 4)
            dotrow3(0, 0, 0, 1, 0);
        else if (numCols == 5)
            dotrow3(0, 0, 0, 0, 1);
        break;
    case 4:
        if (numCols == 1)
            dotrow4(1, 0, 0, 0, 0);
        else if (numCols == 2)
            dotrow4(0, 1, 0, 0, 0);
        else if (numCols == 3)
            dotrow4(0, 0, 1, 0, 0);
        else if (numCols == 4)
            dotrow4(0, 0, 0, 1, 0);
        else if (numCols == 5)
            dotrow4(0, 0, 0, 0, 1);
        break;
    case 5:
        if (numCols == 1)
            dotrow5(1, 0, 0, 0, 0);
        else if (numCols == 2)
            dotrow5(0, 1, 0, 0, 0);
        else if (numCols == 3)
            dotrow5(0, 0, 1, 0, 0);
        else if (numCols == 4)
            dotrow5(0, 0, 0, 1, 0);
        else if (numCols == 5)
            dotrow5(0, 0, 0, 0, 1);
        break;
    case 6:
        if (numCols == 1)
            dotrow6(1, 0, 0, 0, 0);
        else if (numCols == 2)
            dotrow6(0, 1, 0, 0, 0);
        else if (numCols == 3)
            dotrow6(0, 0, 1, 0, 0);
        else if (numCols == 4)
            dotrow6(0, 0, 0, 1, 0);
        else if (numCols == 5)
            dotrow6(0, 0, 0, 0, 1);
        break;
    case 7:
        if (numCols == 1)
            dotrow7(1, 0, 0, 0, 0);
        else if (numCols == 2)
            dotrow7(0, 1, 0, 0, 0);
        else if (numCols == 3)
            dotrow7(0, 0, 1, 0, 0);
        else if (numCols == 4)
            dotrow7(0, 0, 0, 1, 0);
        else if (numCols == 5)
            dotrow7(0, 0, 0, 0, 1);
        break;
    }
}

/**
 * @brief
 * @param
 * @retval
 */
void DotMatrix::resetDotRows(void) {
    dotrow1(0, 0, 0, 0, 0);
    dotrow2(0, 0, 0, 0, 0);
    dotrow3(0, 0, 0, 0, 0);
    dotrow4(0, 0, 0, 0, 0);
    dotrow5(0, 0, 0, 0, 0);
    dotrow6(0, 0, 0, 0, 0);
    dotrow7(0, 0, 0, 0, 0);
}

/* I2C Data Transaction Funstions --------------------------------------------*/

/**
 * @brief  Reads 8bit data from I2C interface
 * @param  dataPacket: includes protocol to request data
 * @retval I2C 8bit data
 */
uint8_t DotMatrix::I2C_ReadData8bit(DotMatrix_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->endTransmission();

    if (_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(1)) != 0)
        return _i2cPort->read();
    return 0;
}

/**
 * @brief  Reads 16bit data from I2C interface
 * @param  dataPacket: includes protocol to request data
 * @retval I2C 16bit data
 */
uint16_t DotMatrix::I2C_ReadData16bit(DotMatrix_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->endTransmission();

    if (_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(2)) != 0) {
        uint16_t i2cData = _i2cPort->read();
        i2cData |= (_i2cPort->read() << 8);
        return i2cData;
    }
    return 0;
}

/**
 * @brief  Reads 16bit data from I2C interface
 * @param  dataPacket: includes protocol to request data
 * @retval I2C 16bit data
 */
uint16_t DotMatrix::I2C_ReadFirmwareData16bit(DotMatrix_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->endTransmission();

    if (_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(2)) != 0) {
        i2cData2 = _i2cPort->read();
        i2cData1 = _i2cPort->read();
        Serial.print("v"); Serial.print(i2cData1); Serial.print("."); Serial.print(i2cData2);
    }
    return 0;
}

/**
 * @brief  Sends data packet based on a custom defined protocol
 * @param  dataPacket: includes all related data
 * @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
 */
bool DotMatrix::I2C_SendDataPacket(DotMatrix_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->write(dataPacket->dataSize);

    for (uint8_t i = 0; i < _dataPacket.dataSize; i++)
        _i2cPort->write(_dataPacket.data[i]);

    if (_i2cPort->endTransmission() == 0)
        return true;
    return false;
}

/*
*****************************************************************************
@file         Deneyap_5x7LedEkran.cpp
@mainpage     Deneyap 5X7 LED Matris Arduino library source file
@maintainer   Mehmet Emre Çelebi, RFtek Electronics <techsupport@rftek.com.tr>
@version      v1.1.0
@date         21 Ekim 2026
@brief        Includes functions to control first generation
              Deneyap 5x7 Dot Matrix (STM8S003, single color)

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
    _i2cAddress = address;
    _i2cPort = &port;
    _dataPacket = {0};

    configureBus();

    // ESP32 3.x için daha uzun başlatma gecikmesi
    delay(50);

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
        return true;
    }

    return false;
}

/**
 * @brief  Requests firmware version of the device
 * @param  None
 * @retval Device firmware version ((major << 8) | minor), 0 --> read error
 */
uint16_t DotMatrix::getFwVersion() {
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write((uint8_t)DOTMATRIX_REQUEST_FW_VERSION);
    _i2cPort->endTransmission();

    if (_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(2)) != 2)
        return 0;

    i2cData2 = _i2cPort->read();
    i2cData1 = _i2cPort->read();
    return ((uint16_t)i2cData1 << 8) | i2cData2;
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

/**
 * @brief  ESP32 3.x için I2C bağlantı sağlığını kontrol eder
 * @param  None
 * @retval I2C bağlantı durumu (true --> sağlıklı, false --> sorunlu)
 */
bool DotMatrix::checkI2CHealth(void) {
    // Basit bir ping testi
    if (!isConnected()) {
        // I2C hatası durumunda yeniden başlatma
        configureBus();
        delay(10);
        return false;
    }
    return true;
}

/* I2C Data Manipulation Functions -------------------------------------------*/

/**
 * @brief  Sends dot matrix column data of one row based on data protocol format
 * @param  colX: 0 (off) or 1 (on)
 * @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
 */
bool DotMatrix::dotrow1(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5) {
    return sendRow(ROW1, col1, col2, col3, col4, col5);
}

bool DotMatrix::dotrow2(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5) {
    return sendRow(ROW2, col1, col2, col3, col4, col5);
}

bool DotMatrix::dotrow3(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5) {
    return sendRow(ROW3, col1, col2, col3, col4, col5);
}

bool DotMatrix::dotrow4(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5) {
    return sendRow(ROW4, col1, col2, col3, col4, col5);
}

bool DotMatrix::dotrow5(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5) {
    return sendRow(ROW5, col1, col2, col3, col4, col5);
}

bool DotMatrix::dotrow6(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5) {
    return sendRow(ROW6, col1, col2, col3, col4, col5);
}

bool DotMatrix::dotrow7(uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5) {
    return sendRow(ROW7, col1, col2, col3, col4, col5);
}

/**
 * @brief  Draws a 5x7 bitmap. The module shows one row at a time, so the
 *         whole frame is refreshed "duration" times (blocking).
 * @param  bitmap: 35 values (0/1), row by row
 *         duration: number of refresh cycles (not milliseconds)
 * @retval None
 */
void DotMatrix::drawLedMatrix(const byte bitmap[NUM_LEDS], int duration) {
    for (int i = 0; i < duration; i++) {
        for (uint8_t row = 0; row < ROW_SIZE; row++) {
            const byte *cols = &bitmap[row * COL_SIZE];
            sendRow(ROW1 + row, cols[0], cols[1], cols[2], cols[3], cols[4]);
        }
    }
}

/**
 * @brief  Lights a single LED
 * @param  numRows: row number (1-7), numCols: column number (1-5)
 * @retval Transmission status (1 --> No error, 0 --> Transmission error or invalid position)
 */
bool DotMatrix::pixelLed(uint8_t numRows, uint8_t numCols) {
    if (numRows < 1 || numRows > ROW_SIZE || numCols < 1 || numCols > COL_SIZE)
        return false;

    uint8_t cols[COL_SIZE] = {0};
    cols[numCols - 1] = 1;
    return sendRow(ROW1 + numRows - 1, cols[0], cols[1], cols[2], cols[3], cols[4]);
}

/**
 * @brief  Turns off all LEDs
 * @param  None
 * @retval None
 */
void DotMatrix::resetDotRows(void) {
    for (uint8_t row = 0; row < ROW_SIZE; row++) {
        sendRow(ROW1 + row, 0, 0, 0, 0, 0);
    }
}

/* Private Functions ---------------------------------------------------------*/

/**
 * @brief  Applies board specific I2C bus settings
 * @param  None
 * @retval None
 */
void DotMatrix::configureBus(void) {
    _i2cPort->begin();

#if defined(ARDUINO_DYM)
    _i2cPort->setClock(100000);
#elif defined(ESP32)
    // ESP32 3.x için özel ayarlar
    _i2cPort->setClock(50000);           // Daha düşük clock
    _i2cPort->setTimeout(50);            // Daha kısa timeout
#if defined(WIRE_HAS_BUFFER_SIZE)
    _i2cPort->setBufferSize(128);        // Buffer boyutu (eski core'larda bu fonksiyon yok)
#endif
#else
    _i2cPort->setClock(50000);
#endif
}

/**
 * @brief  Sends column data of a row
 * @param  row: ROW1 to ROW7, colX: 0 (off) or 1 (on)
 * @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
 */
bool DotMatrix::sendRow(uint8_t row, uint8_t col1, uint8_t col2, uint8_t col3, uint8_t col4, uint8_t col5) {
    _dataPacket.command = row;
    _dataPacket.dataSize = (uint8_t)0x5;
    _dataPacket.data[0] = col1;
    _dataPacket.data[1] = col2;
    _dataPacket.data[2] = col3;
    _dataPacket.data[3] = col4;
    _dataPacket.data[4] = col5;
    return I2C_SendDataPacket(&_dataPacket);
}

/* I2C Data Transaction Functions --------------------------------------------*/

/**
 * @brief  Sends data packet based on a custom defined protocol
 * @param  dataPacket: includes all related data
 * @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
 */
bool DotMatrix::I2C_SendDataPacket(DotMatrix_DataPacket_TypeDef *dataPacket) {
    // ESP32 3.x için gelişmiş I2C hata yönetimi
    uint8_t retryCount = 0;
    uint8_t result;

    do {
        // ESP32 3.x'te I2C buffer temizliği
#if defined(ESP32)
        if (retryCount > 0) {
            _i2cPort->flush();  // Buffer'ı temizle
        }
#endif

        _i2cPort->beginTransmission(_i2cAddress);
        _i2cPort->write(dataPacket->command);
        _i2cPort->write(dataPacket->dataSize);

        for (uint8_t i = 0; i < dataPacket->dataSize; i++) {
            _i2cPort->write(dataPacket->data[i]);
        }

        result = _i2cPort->endTransmission();

        if (result != 0) {
            retryCount++;
            if (retryCount < 3) {
                // ESP32 3.x için adaptif gecikme
                delayMicroseconds(100 + (retryCount * 200));
            }
        }

    } while (result != 0 && retryCount < 3);

    // Başarılı I2C işlemi sonrası minimal gecikme
    if (result == 0) {
        delayMicroseconds(20);
    }

    return (result == 0);
}

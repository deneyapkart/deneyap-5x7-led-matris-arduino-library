# Deneyap 5x7 LED Matrix Arduino Library
[FOR TURKISH VERSION](docs/README_tr.md) ![trflag](https://github.com/deneyapkart/deneyapkart-arduino-core/blob/master/docs/tr.png)

***** Add photo ****

Arduino library for Deneyap 5x7 LED Matrix

## :mag_right:Specifications 
- `Product ID` **M34**
- `Module versions` first generation single color module (**mpv1.0**, STM8S003F3) and new generation RGB module
- `Weight` 
- `Module Dimension` 25,4 mm x 50,8 mm
- `I2C address` 0x0A, 0x4A

| Address |  | 
| :---      | :---     |
| 0x0A | default address |
| 0x4A | address when ADR1 pad is shorted |

## :closed_book:Documentation
[Deneyap 5x7 LED Matrix](https://docs.deneyapkart.org/en/content/contentDetail/deneyap-modul-deneyap-5x7-led-matris-m34)

[Deneyap 5x7 LED Matrix Shematic](https://cdn.deneyapkart.org/media/upload/userFormUpload/WK1yhelN3AwpEflznnZfwsBHZ6iLXOWE.pdf)

[Deneyap 5x7 LED Matrix Mechanical Drawing](https://cdn.deneyapkart.org/media/upload/userFormUpload/njN5GWrocMBeOjJ2EcCy0OTVWnrlxiDc.pdf)

[How to install a Arduino Library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap 5x7 LED Matrix 
This Arduino library allows you to use Deneyap 5x7 LED Matrix module with I2C peripheral. You can use this library in your projects with any Arduino compatible board with I2C peripheral.

Both module versions are supported by the same library, choose the class that matches your module:

| Module | Class | Examples |
| :--- | :--- | :--- |
| First generation, single color (STM8S003F3) | `DotMatrix` | `examples/EskiModul` |
| New generation, RGB | `RGB5x7LedMatris` | `examples/YeniModul` |

```cpp
#include <Deneyap_5x7LedEkran.h>

RGB5x7LedMatris LEDMatris;                             // New RGB module
// DotMatrix LEDMatris;                                // First generation module

void setup() {
    LEDMatris.begin(0x0A);
    LEDMatris.setPixelXY(1, 1, LEDMatris.Color(0, 0, 150)); // row 1, column 1, blue
    LEDMatris.show();
}
```

`RGB5x7LedMatris` is derived from [Adafruit NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel), so all of its functions (`setPixelColor`, `fill`, `clear`, `setBrightness`, `ColorHSV`, `gamma32`...) can be used. Pixels are only sent to the module when `show()` is called. Adafruit NeoPixel library is installed automatically by the Library Manager.

`RGB5x7LedMatris` sends a whole frame (109 bytes) in a single I2C transaction, so the board's Wire buffer must be at least 109 bytes (ESP32 based Deneyap boards: 128 bytes). Boards with a 32 byte Wire buffer, such as Arduino Uno, can only use `DotMatrix`.

## :globe_with_meridians:Repository Contents
- `/docs ` README_tr.md and product photos
- `/examples ` Examples with .ino extension sketches
- `/src ` Source files (.cpp .h)
- `keywords.txt ` Keywords from this library that will be highlighted in the Arduino IDE
- `library.properties ` General library properties for the Arduino package manager

## Version History
1.1.0 - added new generation RGB module support (RGB5x7LedMatris class and examples), examples are grouped as EskiModul/YeniModul, getFwVersion() now returns the version, pixelLed() checks its parameters, bug fixes

1.0.3 - ESP32 core 3.x compatibility and I2C stability improvements, checkI2CHealth() function

1.0.2 - updated comment line in examples and function(drawLedMatrix)

1.0.1 - updated library.properties file

1.0.0 - initial release

## :rocket:Hardware Connections
COLx/ROWx pins below belong to the first generation module.

- Deneyap 5x7 LED Matrix and Board can be connected with I2C cable
- or 3V3, GND, SDA and SCL pins can be connected with jumper cables

|5x7 LED Matrix | Function | Board pins | 
|:--- |   :---  | :---|
|3.3V | Power   |3.3V |      
|GND  | Ground  | GND | 
|SDA  | I2C Data  | SDA pin |
|SCL  | I2C Clock | SCL pin |
|SWIM | Debug | no connection |
|RES  | Debug | no connection |
|COL1 | 1.Column | any GPIO pin |
|COL2 | 2.Column | any GPIO pin |
|COL3 | 3.Column | any GPIO pin |
|COL4 | 4.Column | any GPIO pin |
|COL5 | 5.Column | any GPIO pin |
|ROW1 | 1. Row | any GPIO pin |
|ROW2 | 2. Row | any GPIO pin |
|ROW3 | 3. Row | any GPIO pin |
|ROW4 | 4. Row | any GPIO pin |
|ROW5 | 5. Row | any GPIO pin |
|ROW6 | 6. Row | any GPIO pin |
|ROW7 | 7. Row | any GPIO pin |

## :bookmark_tabs:License Information
Please review the [LICENSE](https://github.com/deneyapkart/deneyap-5x7-led-matris-arduino-library/blob/master/LICENSE) file for license information.

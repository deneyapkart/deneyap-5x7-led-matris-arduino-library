# Deneyap 5x7 LED Matrix Arduino Library
[FOR TURKISH VERSION](docs/README_tr.md) ![trflag](https://github.com/deneyapkart/deneyapkart-arduino-core/blob/master/docs/tr.png)

***** Add photo ****

Arduino library for Deneyap 5x7 LED Matrix

## :mag_right:Specifications 
- `Product ID` **M34**, **mpv1.0**
- `MCU` STM8S003F3
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

## :globe_with_meridians:Repository Contents
- `/docs ` README_tr.md and product photos
- `/examples ` Examples with .ino extension sketches
- `/src ` Source files (.cpp .h)
- `keywords.txt ` Keywords from this library that will be highlighted in the Arduino IDE
- `library.properties ` General library properties for the Arduino package manager

## Version History
1.0.2 - updated comment line in examples and function(drawLedMatrix)

1.0.1 - updated library.properties file

1.0.0 - initial release

## :rocket:Hardware Connections
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

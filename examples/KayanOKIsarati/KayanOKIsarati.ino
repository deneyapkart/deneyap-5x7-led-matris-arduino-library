/*
 *   Kayan Ok İşareti örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   5x7 LED ekrandanın ok işareti DENEYAP logosundan aşağıya doğru kaymaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap 5x7 LED Matris için oluşturulmuştur
 *      ------>  www.....com  <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-5x7-led-matris-arduino-library  <------ 
 *
 */

#include <Deneyap_5x7LedEkran.h>                        // Deneyap_5x7LedEkran.h kütüphanesi eklendi

DotMatrix LEDMatris;                                    // DotMatrix için Class tanımlaması

void setup()
{
    Serial.begin(115200);                               // Seri haberleşme başlatıldı
    if (!LEDMatris.begin(0x0A)){                        // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");    // I2C bağlantısı başarısız olursa seri terminale yazdırma
        while (1);
    }
}

void loop() {
    for (int i = 0; i < 10; i++) {
        LEDMatris.dotrow1(0, 0, 1, 0, 0);
        LEDMatris.dotrow2(0, 0, 1, 0, 0);
        LEDMatris.dotrow3(0, 0, 1, 0, 0);
        LEDMatris.dotrow4(0, 0, 1, 0, 0);
        LEDMatris.dotrow5(1, 1, 1, 1, 1);
        LEDMatris.dotrow6(0, 1, 1, 1, 0);
        LEDMatris.dotrow7(0, 0, 1, 0, 0);
    }
    for (int i = 0; i < 10; i++) {
        LEDMatris.dotrow1(0, 0, 0, 0, 0);
        LEDMatris.dotrow2(0, 0, 1, 0, 0);
        LEDMatris.dotrow3(0, 0, 1, 0, 0);
        LEDMatris.dotrow4(0, 0, 1, 0, 0);
        LEDMatris.dotrow5(0, 0, 1, 0, 0);
        LEDMatris.dotrow6(1, 1, 1, 1, 1);
        LEDMatris.dotrow7(0, 1, 1, 1, 0);
    }
    for (int i = 0; i < 10; i++) {
        LEDMatris.dotrow1(0, 0, 0, 0, 0);
        LEDMatris.dotrow2(0, 0, 0, 0, 0);
        LEDMatris.dotrow3(0, 0, 1, 0, 0);
        LEDMatris.dotrow4(0, 0, 1, 0, 0);
        LEDMatris.dotrow5(0, 0, 1, 0, 0);
        LEDMatris.dotrow6(0, 0, 1, 0, 0);
        LEDMatris.dotrow7(1, 1, 1, 1, 1);
    }
    for (int i = 0; i < 10; i++) {
        LEDMatris.dotrow1(0, 0, 1, 0, 0);
        LEDMatris.dotrow2(0, 0, 0, 0, 0);
        LEDMatris.dotrow3(0, 0, 0, 0, 0);
        LEDMatris.dotrow4(0, 0, 1, 0, 0);
        LEDMatris.dotrow5(0, 0, 1, 0, 0);
        LEDMatris.dotrow6(0, 0, 1, 0, 0);
        LEDMatris.dotrow7(0, 0, 1, 0, 0);
    }
    for (int i = 0; i < 10; i++) {
        LEDMatris.dotrow1(0, 1, 1, 1, 0);
        LEDMatris.dotrow2(0, 0, 1, 0, 0);
        LEDMatris.dotrow3(0, 0, 0, 0, 0);
        LEDMatris.dotrow4(0, 0, 0, 0, 0);
        LEDMatris.dotrow5(0, 0, 1, 0, 0);
        LEDMatris.dotrow6(0, 0, 1, 0, 0);
        LEDMatris.dotrow7(0, 0, 1, 0, 0);
    }
    for (int i = 0; i < 10; i++) {
        LEDMatris.dotrow1(1, 1, 1, 1, 1);
        LEDMatris.dotrow2(0, 1, 1, 1, 0);
        LEDMatris.dotrow3(0, 0, 1, 0, 0);
        LEDMatris.dotrow4(0, 0, 0, 0, 0);
        LEDMatris.dotrow5(0, 0, 0, 0, 0);
        LEDMatris.dotrow6(0, 0, 1, 0, 0);
        LEDMatris.dotrow7(0, 0, 1, 0, 0);
    }
    for (int i = 0; i < 10; i++) {
        LEDMatris.dotrow1(0, 0, 1, 0, 0);
        LEDMatris.dotrow2(1, 1, 1, 1, 1);
        LEDMatris.dotrow3(0, 1, 1, 1, 0);
        LEDMatris.dotrow4(0, 0, 1, 0, 0);
        LEDMatris.dotrow5(0, 0, 0, 0, 0);
        LEDMatris.dotrow6(0, 0, 0, 0, 0);
        LEDMatris.dotrow7(0, 0, 1, 0, 0);
    }
    for (int i = 0; i < 10; i++) {
        LEDMatris.dotrow1(0, 0, 1, 0, 0);
        LEDMatris.dotrow2(0, 0, 1, 0, 0);
        LEDMatris.dotrow3(1, 1, 1, 1, 1);
        LEDMatris.dotrow4(0, 1, 1, 1, 0);
        LEDMatris.dotrow5(0, 0, 1, 0, 0);
        LEDMatris.dotrow6(0, 0, 0, 0, 0);
        LEDMatris.dotrow7(0, 0, 0, 0, 0);
    }
    for (int i = 0; i < 10; i++) {
        LEDMatris.dotrow1(0, 0, 1, 0, 0);
        LEDMatris.dotrow2(0, 0, 1, 0, 0);
        LEDMatris.dotrow3(0, 0, 1, 0, 0);
        LEDMatris.dotrow4(1, 1, 1, 1, 1);
        LEDMatris.dotrow5(0, 1, 1, 1, 0);
        LEDMatris.dotrow6(0, 0, 1, 0, 0);
        LEDMatris.dotrow7(0, 0, 0, 0, 0);
    }
}

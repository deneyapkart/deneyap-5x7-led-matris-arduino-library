/*
 *   Kayan Ok İşareti örneği,
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   5x7 LED Matris'de ok işareti Deneyap logosundan 5X7 LED Matris yazısına doğru aşağıya yönde kaymaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap 5x7 LED Matris için oluşturulmuştur
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-5x7-led-matris-m34  <------
 *      ------>  https://github.com/deneyapkart/deneyap-5x7-led-matris-arduino-library  <------ 
*/
#include <Deneyap_5x7LedEkran.h>                        // Deneyap 5x7 LED Matris kütüphanesi eklenmesi

DotMatrix LEDMatris;                                    // DotMatrix için Class tanımlaması

void setup()
{
    Serial.begin(115200);                               // Seri haberleşme başlatılması
    if (!LEDMatris.begin(0x0A)){                        // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");    // I2C bağlantısı başarısız olursa seri port ekranına yazdırılması
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

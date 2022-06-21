/*
 *   Hızlı random Led Yakma örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Random satır ve random sütun sayısı atması yapılmaktadır.
 *   5x7 LED ekranında atanan satır ve sütundaki LED'i yakmaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap 5x7 LED Matris için oluşturulmuştur
 *      ------>  www.....com  <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-5x7-led-matris-arduino-library  <------ 
 *
 */
#include <Deneyap_5x7LedEkran.h>                         // Deneyap_5x7LedEkran.h kütüphanesi eklendi

DotMatrix LEDMatris;                                     // DotMatrix için Class tanımlaması

void setup() {
    Serial.begin(115200);                                // Seri haberleşme başlatıldı
    if (!LEDMatris.begin(0x0A)) {                        // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");     // I2C bağlantısı başarısız olursa seri terminale yazdırma
        while (1);
    }
}

void loop() {
    for (int i; i < 100; ++i) {
        int randNumberRow = random(1, 8);                 // 1'den 7 kadar Random satır sayısı ataması
        int randNumberCol = random(1, 6);                 // 1'den 5 kadar Random sütun sayısı ataması
        LEDMatris.pixelLed(randNumberRow, randNumberCol); // Random atanan satır ve sutun sayısındaki LED yanmaktadır.
    }
}

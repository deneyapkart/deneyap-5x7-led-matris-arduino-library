/*
 *   Random Led Yakma örneği,
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Random satır ve random sütun sayısı atması yapılmaktadır.
 *   5x7 LED Matris'de atanan satır ve sütundaki LED'i yakmaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap 5x7 LED Matris için oluşturulmuştur
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-5x7-led-matris-m34  <------
 *      ------>  https://github.com/deneyapkart/deneyap-5x7-led-matris-arduino-library  <------ 
*/
#include <Deneyap_5x7LedEkran.h>                      // Deneyap 5x7 LED Matris kütüphanesi eklenmesi

DotMatrix LEDMatris;                                  // DotMatrix için Class tanımlaması

int randNumberRow = random(1, 8);                     // 1'den 7 kadar Random satır sayısı ataması
int randNumberCol = random(1, 6);                     // 1'den 5 kadar Random sütun sayısı ataması

void setup() {
    Serial.begin(115200);                             // Seri haberleşme başlatıldı
    if (!LEDMatris.begin(0x0A)) {                     // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");  // I2C bağlantısı başarısız olursa seri port ekranına yazdırma
        while (1);
    }
}

void loop() {
    LEDMatris.pixelLed(randNumberRow, randNumberCol); // Random atanan satır ve sutun sayısındaki LED yanmaktadır.
}

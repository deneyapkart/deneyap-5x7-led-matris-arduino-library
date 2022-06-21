/*
 *   Gülen yüz örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   5x7 LED ekranında gülen yüz yazdırmaktadır. 
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap 5x7 LED Matris için oluşturulmuştur
 *      ------>  www.....com  <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-5x7-led-matris-arduino-library  <------ 
 *
*/
#include <Deneyap_5x7LedEkran.h>                      // Deneyap_5x7LedEkran.h kütüphanesi eklendi

DotMatrix LEDMatris;                                  // DotMatrix için Class tanımlaması

const byte gulenYuz[] = {0, 0, 0, 0, 0,
                         0, 1, 0, 1, 0,
                         0, 0, 0, 0, 0,
                         0, 0, 1, 0, 0,
                         1, 0, 0, 0, 1,
                         0, 1, 1, 1, 0,
                         0, 0, 0, 0, 0};

void setup() {
    Serial.begin(115200);                            // Seri haberleşme başlatıldı
    if (!LEDMatris.begin(0x0A)){                     // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
        delay(3000);
        Serial.println("I2C bağlantısı başarısız");  // I2C bağlantısı başarısız olursa seri terminale yazdırma
        while (1);
    }
}

void loop() {
    LEDMatris.drawLedMatrix(gulenYuz);  
}

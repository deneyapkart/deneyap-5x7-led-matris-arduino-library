/*
 *   Random Led Yakma örneği (yeni RGB modül),
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Random satır, random sütun ve random renk ataması yapılmaktadır.
 *   5x7 LED Matris'de atanan satır ve sütundaki LED'i atanan renkte yakmaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *   Bu örnek yeni (RGB) modül içindir, Adafruit NeoPixel kütüphanesi gereklidir.
 *
 *   Bu örnek Deneyap 5x7 LED Matris için oluşturulmuştur
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-5x7-led-matris-m34  <------
 *      ------>  https://github.com/deneyapkart/deneyap-5x7-led-matris-arduino-library  <------
*/
#include <Deneyap_5x7LedEkran.h>                      // Deneyap 5x7 LED Matris kütüphanesi eklenmesi

RGB5x7LedMatris LEDMatris;                            // Yeni (RGB) modül için Class tanımlaması

void setup() {
    Serial.begin(115200);                             // Seri haberleşme başlatıldı
    if (!LEDMatris.begin(0x0A)) {                     // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");  // I2C bağlantısı başarısız olursa seri port ekranına yazdırma
        while (1);
    }
}

void loop() {
    int randNumberRow = random(1, 8);                 // 1'den 7 kadar Random satır sayısı ataması
    int randNumberCol = random(1, 6);                 // 1'den 5 kadar Random sütun sayısı ataması
    uint32_t renk = LEDMatris.ColorHSV(random(0, 65536), 255, 150); // Random renk ataması

    LEDMatris.clear();                                // Önceki LED'in söndürülmesi
    LEDMatris.setPixelXY(randNumberRow, randNumberCol, renk);
    LEDMatris.show();                                 // Belleğin modüle gönderilmesi
    delay(100);
}

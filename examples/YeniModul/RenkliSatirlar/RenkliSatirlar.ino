/*
 *   Renkli Satırlar örneği (yeni RGB modül),
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   5x7 LED Matris'deki LED'ler sırayla, satırlara göre mavi ve sarı renkte yakılmaktadır.
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

#define BEKLEME_SURESI 100                            // Her LED arasındaki bekleme süresi (ms)

void setup() {
    Serial.begin(115200);                             // Seri haberleşme başlatıldı
    if (!LEDMatris.begin(0x0A)) {                     // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");  // I2C bağlantısı başarısız olursa seri port ekranına yazdırma
        while (1);
    }
    // LEDMatris.setI2Caddress(0x4A);                 // Modülün I2C adresini değiştirmek için
}

void loop() {
    LEDMatris.clear();                                // Tüm LED'lerin söndürülmesi
    LEDMatris.show();
    delay(BEKLEME_SURESI);

    uint32_t mavi = LEDMatris.Color(0, 0, 150);
    uint32_t sari = LEDMatris.Color(150, 150, 0);

    for (uint8_t satir = 1; satir <= 7; satir++) {
        uint32_t renk = (satir % 2 == 1) ? mavi : sari;  // Tek satırlar mavi, çift satırlar sarı
        for (uint8_t sutun = 1; sutun <= 5; sutun++) {
            LEDMatris.setPixelXY(satir, sutun, renk);
            LEDMatris.show();
            delay(BEKLEME_SURESI);
        }
    }
}

/*
 *   T3 VAKFI Yazdırma örneği (yeni RGB modül),
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   5x7 LED Matris'de sırasıyla T 3 V A K F I harfleri farklı renklerde yazdırılmaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *   Bu örnek yeni (RGB) modül içindir, Adafruit NeoPixel kütüphanesi gereklidir.
 *
 *   Bu örnek Deneyap 5x7 LED Matris için oluşturulmuştur
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-5x7-led-matris-m34  <------
 *      ------>  https://github.com/deneyapkart/deneyap-5x7-led-matris-arduino-library  <------
*/
#include <Deneyap_5x7LedEkran.h>                         // Deneyap 5x7 LED Matris kütüphanesi eklenmesi

RGB5x7LedMatris LEDMatris;                               // Yeni (RGB) modül için Class tanımlaması

const byte harfler[][NO_OF_LEDS] = {
    {1, 1, 1, 1, 1,                                      // T
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0,                                      // 3
     1, 0, 0, 0, 1,
     0, 0, 0, 1, 0,
     0, 0, 1, 1, 0,
     0, 0, 0, 1, 0,
     1, 0, 0, 0, 1,
     0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1,                                      // V
     1, 0, 0, 0, 1,
     1, 0, 0, 0, 1,
     0, 1, 0, 1, 0,
     0, 1, 0, 1, 0,
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0,                                      // A
     0, 1, 0, 1, 0,
     1, 0, 0, 0, 1,
     1, 1, 1, 1, 1,
     1, 0, 0, 0, 1,
     1, 0, 0, 0, 1,
     1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1,                                      // K
     1, 0, 0, 1, 0,
     1, 0, 1, 0, 0,
     1, 1, 0, 0, 0,
     1, 0, 1, 0, 0,
     1, 0, 0, 1, 0,
     1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1,                                      // F
     1, 0, 0, 0, 0,
     1, 0, 0, 0, 0,
     1, 1, 1, 1, 0,
     1, 0, 0, 0, 0,
     1, 0, 0, 0, 0,
     1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0,                                      // I
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0},
};

const uint8_t harfSayisi = sizeof(harfler) / sizeof(harfler[0]);

void setup() {
    Serial.begin(115200);                                // Seri haberleşme başlatıldı
    if (!LEDMatris.begin(0x0A)) {                        // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");     // I2C bağlantısı başarısız olursa seri port ekranına yazdırma
        while (1);
    }
}

void loop() {
    for (uint8_t i = 0; i < harfSayisi; i++) {
        uint16_t renkTonu = i * (65536UL / harfSayisi);  // Her harf için renk çemberinde farklı bir ton
        uint32_t renk = LEDMatris.ColorHSV(renkTonu, 255, 150);
        LEDMatris.drawBitmap(harfler[i], renk);          // Harfin belleğe yazılması
        LEDMatris.show();                                // Belleğin modüle gönderilmesi
        delay(700);
    }
}

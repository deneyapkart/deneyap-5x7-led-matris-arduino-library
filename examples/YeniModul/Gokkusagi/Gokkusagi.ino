/*
 *   Gökkuşağı örneği (yeni RGB modül),
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   5x7 LED Matris'de çapraz yönde kayan bir gökkuşağı efekti gösterilmektedir.
 *   Parlaklık setBrightness() fonksiyonu ile ayarlanmaktadır.
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

uint16_t baslangicTonu = 0;                           // Gökkuşağının başlangıç rengi

void setup() {
    Serial.begin(115200);                             // Seri haberleşme başlatıldı
    if (!LEDMatris.begin(0x0A)) {                     // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");  // I2C bağlantısı başarısız olursa seri port ekranına yazdırma
        while (1);
    }
    LEDMatris.setBrightness(60);                      // Parlaklık ayarı (0-255)
}

void loop() {
    for (uint8_t satir = 1; satir <= 7; satir++) {
        for (uint8_t sutun = 1; sutun <= 5; sutun++) {
            uint16_t ton = baslangicTonu + (satir + sutun) * 4096;  // Çapraz yönde renk geçişi
            LEDMatris.setPixelXY(satir, sutun, LEDMatris.gamma32(LEDMatris.ColorHSV(ton)));
        }
    }
    LEDMatris.show();                                 // Belleğin modüle gönderilmesi

    baslangicTonu += 512;                             // Bir sonraki karede renkleri kaydır
    delay(20);
}

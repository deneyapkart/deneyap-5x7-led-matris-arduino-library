/*
 *   Kayan Ok İşareti örneği (yeni RGB modül),
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   5x7 LED Matris'de ok işareti Deneyap logosundan 5X7 LED Matris yazısına doğru aşağıya yönde kaymaktadır.
 *   Ok her adımda renk değiştirmektedir.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *   Bu örnek yeni (RGB) modül içindir, Adafruit NeoPixel kütüphanesi gereklidir.
 *
 *   Bu örnek Deneyap 5x7 LED Matris için oluşturulmuştur
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-5x7-led-matris-m34  <------
 *      ------>  https://github.com/deneyapkart/deneyap-5x7-led-matris-arduino-library  <------
*/
#include <Deneyap_5x7LedEkran.h>                        // Deneyap 5x7 LED Matris kütüphanesi eklenmesi

RGB5x7LedMatris LEDMatris;                              // Yeni (RGB) modül için Class tanımlaması

#define DESEN_SATIR 9                                   // Ok (7 satır) + aradaki boşluk (2 satır)

const byte okDeseni[DESEN_SATIR][5] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
};

void setup() {
    Serial.begin(115200);                               // Seri haberleşme başlatılması
    if (!LEDMatris.begin(0x0A)) {                       // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");    // I2C bağlantısı başarısız olursa seri port ekranına yazdırılması
        while (1);
    }
}

void loop() {
    for (uint8_t adim = 0; adim < DESEN_SATIR; adim++) {
        uint32_t renk = LEDMatris.ColorHSV(adim * (65536UL / DESEN_SATIR), 255, 150);

        for (uint8_t satir = 1; satir <= 7; satir++) {
            uint8_t desenSatiri = (satir - 1 + DESEN_SATIR - adim) % DESEN_SATIR;  // Deseni her adımda bir satır aşağı kaydır
            for (uint8_t sutun = 1; sutun <= 5; sutun++) {
                LEDMatris.setPixelXY(satir, sutun, okDeseni[desenSatiri][sutun - 1] ? renk : 0);
            }
        }
        LEDMatris.show();                               // Belleğin modüle gönderilmesi
        delay(150);
    }
}

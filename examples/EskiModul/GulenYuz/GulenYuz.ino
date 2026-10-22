/*
 *   Gülen yüz örneği,
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Deneyap 5x7 LED Matris'de gülen yüz emojisinin ledleri yanmaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu örnek Deneyap 5x7 LED Matris için oluşturulmuştur
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-5x7-led-matris-m34  <------
 *      ------>  https://github.com/deneyapkart/deneyap-5x7-led-matris-arduino-library  <------ 
*/
#include <Deneyap_5x7LedEkran.h>                     // Deneyap 5x7 LED Matris kütüphanesi eklenmesi

DotMatrix LEDMatris;                                 // DotMatrix için Class tanımlaması

const byte gulenYuz[] = {0, 0, 0, 0, 0,
                         0, 1, 0, 1, 0,
                         0, 0, 0, 0, 0,
                         0, 0, 1, 0, 0,
                         1, 0, 0, 0, 1,
                         0, 1, 1, 1, 0,
                         0, 0, 0, 0, 0};             // Gülen yüz emojisinin yazdırılması 

void setup() {
    Serial.begin(115200);                            // Seri haberleşme başlatılması
    if (!LEDMatris.begin(0x0A)){                     // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
        delay(3000);
        Serial.println("I2C bağlantısı başarısız");  // I2C bağlantısı başarısız olursa seri port ekranına yazdırması
        while (1);
    }
}

void loop() {
    LEDMatris.drawLedMatrix(gulenYuz);               // Gülen yüz emojisinin 5x7 LED Matris'de yazdırılması gösterilmesi, ikinci parametre girerek bekleme süresinin uzatabilirsiniz. varsayılan:(gulenYuz,100)
}

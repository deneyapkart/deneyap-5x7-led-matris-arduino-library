/*
 *   T3 VAKFI Yazdırma örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   5x7 LED ekrandanın sırasıyla T 3 V A K F I yazdırmaktadır.
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
    for (int i = 0; i < 100; i++) {                      // T
        LEDMatris.dotrow1(1, 1, 1, 1, 1);                // 1. satır için sutun verilerini yazdırma
        LEDMatris.dotrow2(0, 0, 1, 0, 0);                // 2. satır için sutun verilerini yazdırma
        LEDMatris.dotrow3(0, 0, 1, 0, 0);                // 3. satır için sutun verilerini yazdırma
        LEDMatris.dotrow4(0, 0, 1, 0, 0);                // 4. satır için sutun verilerini yazdırma
        LEDMatris.dotrow5(0, 0, 1, 0, 0);                // 5. satır için sutun verilerini yazdırma
        LEDMatris.dotrow6(0, 0, 1, 0, 0);                // 6. satır için sutun verilerini yazdırma
        LEDMatris.dotrow7(0, 0, 1, 0, 0);                // 7. satır için sutun verilerini yazdırma
    }

    for (int j = 0; j < 100; j++) {                      // 3
        LEDMatris.dotrow1(0, 1, 1, 1, 0);
        LEDMatris.dotrow2(1, 0, 0, 0, 1);
        LEDMatris.dotrow3(0, 0, 0, 1, 0);
        LEDMatris.dotrow4(0, 0, 1, 1, 0);
        LEDMatris.dotrow5(0, 0, 0, 1, 0);
        LEDMatris.dotrow6(1, 0, 0, 0, 1);
        LEDMatris.dotrow7(0, 1, 1, 1, 0);
    }

    for (int k = 0; k < 100; k++) {                     // V
        LEDMatris.dotrow1(1, 0, 0, 0, 1);
        LEDMatris.dotrow2(1, 0, 0, 0, 1);
        LEDMatris.dotrow3(1, 0, 0, 0, 1);
        LEDMatris.dotrow4(0, 1, 0, 1, 0);
        LEDMatris.dotrow5(0, 1, 0, 1, 0);
        LEDMatris.dotrow6(0, 0, 1, 0, 0);
        LEDMatris.dotrow7(0, 0, 1, 0, 0);
    }

    for (int l = 0; l < 100; l++) {                    // A
        LEDMatris.dotrow1(0, 0, 1, 0, 0);
        LEDMatris.dotrow2(0, 1, 0, 1, 0);
        LEDMatris.dotrow3(1, 0, 0, 0, 1);
        LEDMatris.dotrow4(1, 1, 1, 1, 1);
        LEDMatris.dotrow5(1, 0, 0, 0, 1);
        LEDMatris.dotrow6(1, 0, 0, 0, 1);
        LEDMatris.dotrow7(1, 0, 0, 0, 1);
    } 
    for (int a = 0; a < 100; a++) {                    // K
        LEDMatris.dotrow1(1, 0, 0, 0, 1);
        LEDMatris.dotrow2(1, 0, 0, 1, 0);
        LEDMatris.dotrow3(1, 0, 1, 0, 0);
        LEDMatris.dotrow4(1, 1, 0, 0, 0);
        LEDMatris.dotrow5(1, 0, 1, 0, 0);
        LEDMatris.dotrow6(1, 0, 0, 1, 0);
        LEDMatris.dotrow7(1, 0, 0, 0, 1);
    }
    for (int s = 0; s < 100; s++) {                   // F
        LEDMatris.dotrow1(1, 1, 1, 1, 1);
        LEDMatris.dotrow2(1, 0, 0, 0, 0);
        LEDMatris.dotrow3(1, 0, 0, 0, 0);
        LEDMatris.dotrow4(1, 1, 1, 1, 0);
        LEDMatris.dotrow5(1, 0, 0, 0, 0);
        LEDMatris.dotrow6(1, 0, 0, 0, 0);
        LEDMatris.dotrow7(1, 0, 0, 0, 0);
    }
    for (int b = 0; b < 100; b++) {                   // I
        LEDMatris.dotrow1(0, 0, 1, 0, 0);
        LEDMatris.dotrow2(0, 0, 1, 0, 0);
        LEDMatris.dotrow3(0, 0, 1, 0, 0);
        LEDMatris.dotrow4(0, 0, 1, 0, 0);
        LEDMatris.dotrow5(0, 0, 1, 0, 0);
        LEDMatris.dotrow6(0, 0, 1, 0, 0);
        LEDMatris.dotrow7(0, 0, 1, 0, 0);
    }
}

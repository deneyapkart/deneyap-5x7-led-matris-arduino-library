/*
 *   Kayan Çizgi no I2C örneği,
 *   Bu örnekte satır ve sütun pinleri array olarak tanıtılmaktadır.
 *   5x7 LED Matris'de çizgi kaymaktadır.
 *
 *   Bu örnekte I2C kullanılmamaktadır, LED'ler modülün ROW/COL pinlerine bağlanan kart pinleriyle doğrudan sürülmektedir.
 *   Pin isimleri (D0, D1, ... DAC2) Deneyap Kart içindir, farklı bir kartta kendi pinlerinizi yazmalısınız.
 *   Bu örnek yalnızca eski (tek renkli) modül için geçerlidir.
 *
 *   Bu örnek Deneyap 5x7 LED Matris için oluşturulmuştur
 *      ------>  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-5x7-led-matris-m34  <------
 *      ------>  https://github.com/deneyapkart/deneyap-5x7-led-matris-arduino-library  <------ 
*/
int satir[7] = {D0, D1, D4, D5, D6, D7, D9};
int sutun[5] = {D12, D13, D14, D15, DAC2};

void setup() {
    for (int i = 0; i < 7; ++i) {
        pinMode(satir[i], OUTPUT);
    }
    for (int i = 0; i < 5; ++i) {
        pinMode(sutun[i], OUTPUT);
    }
}

void loop() {
    for (int i = 0; i < 5; ++i) {
        digitalWrite(sutun[i], LOW);
        for (int j = 0; j < 7; ++j) {
            digitalWrite(satir[j], HIGH);
        }
        delay(100);
        for (int j = 0; j < 7; j++) {
            digitalWrite(satir[j], LOW);
        }
        digitalWrite(sutun[i], HIGH);
    }
}

# Deneyap 5x7 LED Matris Arduino Kütüphanesi

***** Fotoğraf eklenecek ****

Deneyap 5x7 LED Matris için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M34**
- `Modül sürümleri` eski tek renkli modül (**mpv1.0**, STM8S003F3) ve yeni nesil RGB modül
- `Ağırlık`
- `Modul Boyutları` 25,4 mm x 50,8 mm
- `I2C Adres` 0x0A, 0x4A

| Adres |  | 
| :--- | :---     |
| 0x0A | varsayılan adres |
| 0x4A | ADR1 kısa devre yapıldığındaki adres |

## :closed_book:Dokümanlar

[Deneyap 5x7 LED Matris](https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-5x7-led-matris-m34)

[Deneyap 5x7 LED Matris Şematik](https://cdn.deneyapkart.org/media/upload/userFormUpload/WK1yhelN3AwpEflznnZfwsBHZ6iLXOWE.pdf)

[Deneyap 5x7 LED Matris Teknik Çizim](https://cdn.deneyapkart.org/media/upload/userFormUpload/njN5GWrocMBeOjJ2EcCy0OTVWnrlxiDc.pdf)

[Arduino Kütüphanesi Nasıl İndirilir](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap 5x7 LED Matris
Bu Arduino kütüphanesi Deneyap 5x7 LED Matrisin I2C çevre birimi ile kullanılmasını sağlar. Arduino ile uyumlu, I2C çevre birimine sahip herhangi bir geliştirme kartı ile bu kütüphaneyi projelerinizde kullanabilirsiniz.

Modülün iki sürümü de aynı kütüphane ile desteklenir, modülünüze uygun sınıfı seçin:

| Modül | Sınıf | Örnekler |
| :--- | :--- | :--- |
| Eski, tek renkli (STM8S003F3) | `DotMatrix` | `examples/EskiModul` |
| Yeni nesil, RGB | `RGB5x7LedMatris` | `examples/YeniModul` |

```cpp
#include <Deneyap_5x7LedEkran.h>

RGB5x7LedMatris LEDMatris;                             // Yeni RGB modül
// DotMatrix LEDMatris;                                // Eski modül

void setup() {
    LEDMatris.begin(0x0A);
    LEDMatris.setPixelXY(1, 1, LEDMatris.Color(0, 0, 150)); // 1. satır, 1. sütun, mavi
    LEDMatris.show();
}
```

`RGB5x7LedMatris` sınıfı [Adafruit NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) kütüphanesinden türetilmiştir, bu yüzden onun tüm fonksiyonları (`setPixelColor`, `fill`, `clear`, `setBrightness`, `ColorHSV`, `gamma32`...) kullanılabilir. Pikseller yalnızca `show()` çağrıldığında modüle gönderilir. Adafruit NeoPixel kütüphanesi Kütüphane Yöneticisi tarafından otomatik kurulur.

`RGB5x7LedMatris` bir kareyi (109 bayt) tek bir I2C işleminde gönderir, bu yüzden kartın Wire tamponu en az 109 bayt olmalıdır (ESP32 tabanlı Deneyap kartlarda 128 bayt). Arduino Uno gibi 32 baytlık Wire tamponuna sahip kartlarda yalnızca `DotMatrix` kullanılabilir.

## :globe_with_meridians:Repo İçeriği
- `/docs` README_tr.md ve ürün fotoğrafları
- `/examples` .ino uzantılı örnek uygulamalar
- `/src` kütüphane için .cpp ve .h uzantılı dosyalar
- `keywords.txt` Arduino IDE'de vurgulanacak anahtar kelimeler
- `library.properties` Arduino yöneticisi için genel kütüphane özellikleri

## Sürüm Geçmişi
1.1.0 - yeni nesil RGB modül desteği eklendi (RGB5x7LedMatris sınıfı ve örnekleri), örnekler EskiModul/YeniModul olarak gruplandı, getFwVersion() artık sürümü döndürüyor, pixelLed() parametre kontrolü yapıyor, hata düzeltmeleri

1.0.3 - ESP32 core 3.x uyumluluğu ve I2C kararlılık iyileştirmeleri, checkI2CHealth() fonksiyonu

1.0.2 - örneklerdeki yorum satırı ve fonksiyon(drawLedMatrix) güncellendi

1.0.1 - library.properties dosyasının güncellendi

1.0.0 - ilk sürüm

## :rocket:Donanım Bağlantıları
Aşağıdaki COLx/ROWx pinleri eski modüle aittir.

- Deneyap 5x7 LED Matris ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir. 

| 5x7 LED Matris | Fonksiyon| Kart pinleri |
| :---     | :---   |   :---  |
| 3.3V     |3.3V Besleme Gerilimi| 3.3V    |
| GND      | Toprak |GND      |
| SDA      |Çift Yönlü Veri Hattı| SDA pini |
| SCL      |Veri Hattı Zaman Senkronizasyon İşareti| SCL pini|
|SWIM | Debug | bağlantı yok |
|RES  | Debug | bağlantı yok |
|COL1 | 1. sütun | herhangi bir GPIO pini |
|COL2 | 2. sütun | herhangi bir GPIO pini |
|COL3 | 3. sütun | herhangi bir GPIO pini |
|COL4 | 4. sütun | herhangi bir GPIO pini |
|COL5 | 5. sütun | herhangi bir GPIO pini |
|ROW1 | 1. satır | herhangi bir GPIO pini |
|ROW2 | 2. satır | herhangi bir GPIO pini |
|ROW3 | 3. satır | herhangi bir GPIO pini |
|ROW4 | 4. satır | herhangi bir GPIO pini |
|ROW5 | 5. satır | herhangi bir GPIO pini |
|ROW6 | 6. satır | herhangi bir GPIO pini |
|ROW7 | 7. satır | herhangi bir GPIO pini |

## :bookmark_tabs:Lisans Bilgisi 
Lisans bilgileri için [LICENSE](https://github.com/deneyapkart/deneyap-5x7-led-matris-arduino-library/blob/master/LICENSE) dosyasını inceleyin.

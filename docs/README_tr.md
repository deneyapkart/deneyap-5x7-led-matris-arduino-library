# Deneyap 5x7 LED Matris Arduino Kütüphanesi

***** Fotoğraf eklenecek ****

Deneyap 5x7 LED Matris Modülü için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M34**, **mpv1.0**
- `MCU` STM8S003F3
- `Ağırlık`
- `Modul Boyutları` 
- `I2C Adres` 0x0A, 0x4A

| Adres |  | 
| :--- | :---     |
| 0x0A | varsayılan adres |
| 0x4A | ADR1 kısa devre yapıldığındaki adres |

## :closed_book:Dokümanlar
Deneyap 5x7 LED Matris Modülü

Arduino Kütüphanesi Nasıl İndirilir

## :pushpin:Deneyap 5x7 LED Matris
Bu Arduino kütüphanesi Deneyap 5x7 LED Matris modülünün I2C çevre birimi ile kullanılmasını sağlar. Arduino ile uyumlu, I2C çevre birimine sahip herhangi bir geliştirme kartı ile bu kütüphaneyi projelerinizde kullanabilirsiniz.

## :globe_with_meridians:Repo İçeriği
- `/docs` README_tr.md ve ürün fotoğrafları
- `/examples` .ino uzantılı örnek uygulamalar
- `/src` kütüphane için .cpp ve .h uzantılı dosyalar
- `keywords.txt` Arduino IDE'de vurgulanacak anahtar kelimeler
- `library.properties` Arduino yöneticisi için genel kütüphane özellikleri

## Sürüm Geçmişi
1.0.0 - ilk sürüm

1.0.1 - library.properties dosyasının güncellenmesi

## :rocket:Donanım Bağlantıları
- Deneyap 5x7 LED Matris ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir. 

| 5x7 LED Matris | Fonksiyon| Kart pinleri |
| :---     | :---   |   :---  |
| 3.3V     | Güç    | 3.3V    |
| GND      | Toprak |GND      |
| SDA      | I2C Data  | SDA pini |
| SCL      | I2C Clock | SCL pini|
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

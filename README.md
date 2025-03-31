# Programming Dersi Uygulamaları ve Dönem Sonu Projesi
Bu repo, **Programming** dersi için yaptığım ders içi uygulamalar ve dönem sonu projesini içermektedir.

## Uygulamalar
- **Uygulama 1:** C stilinde stringlerle girilen cümlede büyük harfleri çoğaltma, boşlukları düzenleme, kelime başlarını büyütme ve cümleyi ters çevirme işlemleri yapılır.
- **Uygulama 2:** Pointer kullanılarak N x N matrisin elemanları sıfırlanır, kenarları 1 yapılır ve başka bir matrise iki katı atanır.
- **Uygulama 3:** Struct ile öğrenci bilgileri alınır, numaraya göre sıralanır ve en düşük/yüksek ortalamalı öğrenciler bulunur.
- **Uygulama 4:** 2x2 matris dosyadan okunur, tersi hesaplanıp başka bir dosyaya yazılır veya ters yoksa uyarı verilir.

## Dönem Sonu Projesi
- **Proje Adı:** Hafıza Oyunu
- **Amaç:** Oyuncunun koordinatlarla kartları eşleştirmesi ve puan kazanması; oyun ilerleyişini kaydetme/yükleme özelliğiyle kesintisiz oynanış sağlanır.
- **Oynanış:** Kullanıcı minimum 4 ve çift sayı olacak şekilde boyut girer (ör. 4, 6); kartlar A-Z aralığında rastgele dağıtılır, her harften iki tane bulunur.
- **Menü:** "Yeni Oyun", "Kayıtlı Oyundan Devam Et" ve "Çıkış" seçenekleri sunulur; oyun sırasında harf girilerek (cin.fail tetiklenir) kayıt yapılıp ana menüye dönülür.
- **Puanlama:** Doğru eşleşme +3 puan kazandırır, yanlış eşleşme -1 puan düşer; puan sürekli ekranda görünür.
- **Kayıt/Yükleme:** Oyun durumu (puan ve tablo) save.txt dosyasına kaydedilir; "Kayıtlı Oyundan Devam Et" seçildiğinde dosya okunur, yoksa yeni oyun başlar.
- **Kontrol:** Açık kartlar (boşlukla gösterilen) tekrar seçilemez, geçersiz koordinatlar (boyuttan büyük/küçük) için uyarı verilir ve yeniden giriş istenir.
- **Görsel:** Her hamlede ekran temizlenir, açılan kartlar 2 saniye görünür ve ardından güncel tablo bastırılır; tüm kartlar açılana kadar oyun devam eder.

## Notlar
- Hafıza oyunu iki dönem boyunca, derslerde öğrenilen konularla üzerinde koyularak geliştirilmiştir. Sabit 6x6 matristen başlayarak, kullanıcıdan dinamik boyut alma ve oyun durumunu dosyaya kaydedip yükleme özellikleriyle zenginleştirilmiştir. Burada en son versiyonunu paylaşıyorum.

#include <stdio.h>
#include <string.h>
#include "./fonksiyonlar.h"  // Kendi başlık dosyanızı dahil edin.
#include <locale.h>

#define MAX_CALISAN_SAYISI 100



int calisanSayisi = 0; // ileride calisan sayisina göre ekleyeceğimiz çalışanın id'sini belirleyeceğiz




int enBuyukID() {
    FILE *dosya = fopen("calisanlar.txt", "r"); // dosyayı okumak için dosya değişkenine atar
    if (dosya == NULL) {
        return 0; // Dosya yoksa veya okuma  hatası varsa, 0 olarak döner.
    }

    int enBuyukID = 0;
    char satir[100]; // okuma yaparken kullanacapğımız satırı bir satırda max kaç karakter olacağını burada belirtiyoruz
    while (fgets(satir, sizeof(satir), dosya) != NULL) {
        int id; // id değişkeni oluşturur ve bu id değişkeninin bulunduğu satırdan alır
        sscanf(satir, "id:%d", &id);

        if (id > enBuyukID) { // eğer id değeri en büyük id değerinden büyükse en büyük id  artık bu id olur ve bu döngü tamamlanana kadar tekrar eder
            enBuyukID = id;
        }

    }

    fclose(dosya);
    return enBuyukID; // en büyük id'yi döner
}

int maashesapla(int saatlikucret,int calismasaati ){
    return calismasaati * saatlikucret; // saatlik ücreti ve çalışma saatini çarparak maaşı hesaplar
}

void calisanEkle(char *isim,int yas,int saatlikucret,int calismasaati){


        ++calisanSayisi; // çalışan sayısını 1 artırarak çalışanın id'sini (sırasını) belirler

        // parametrelerden aldıgımız degerleri dogru index'teki değişkene atar
        calisanlar[calisanSayisi].id = calisanSayisi;


        snprintf(calisanlar[calisanSayisi].isim, sizeof(calisanlar[calisanSayisi].isim), "%s", isim);

        calisanlar[calisanSayisi].yas = yas;
        calisanlar[calisanSayisi].saatlikucret = saatlikucret;

        calisanlar[calisanSayisi].calismasaati = calismasaati;

        calisanlar[calisanSayisi].maas = maashesapla(saatlikucret , calismasaati);
        // Çalışan özelliklerini gir ve çalısan sayısını bir artır

}



int main() {
    setlocale(LC_ALL, "Turkish");
    int a = 1;
    calisanSayisi = enBuyukID(); // kod başında en büyük id'yi belirler bu sayede bir sonraki ekleyeceğimiz çalışanın id'sini belirleriz
    while (a) {
        printf("-------------------------------");
        printf("\nNe yapmak istiyorunuz\n");
        printf("Çalışan girmek istiyorsanız 1 yazınız\n");
        printf("Çalışanların tamamını görmek istiyorsanız 2 yazınız\n");
        printf("çıkış yapmak için 3 yazınız \n");
        char soru;
        scanf("%d", &soru);
        getchar(); // Enter karakterinini temizledik

        if (soru == 1) { // çalışan girmek istediğimizi belirttik


            if (calisanSayisi <
                MAX_CALISAN_SAYISI) {  // çalışan sayımızın max çalışan sayımızdan kücük oldugunu kontrol ediyoruz
                // oluşturacagımız Calisan icin değerlerimizi kullanıcıdan alıyoruz
                char isim[30];
                int yas;
                int saatlikucret;
                int calismasaati;

                printf("Çalısanın ismi nedir : ");
                fgets(isim, sizeof(isim), stdin);
                isim[strcspn(isim, "\n")] = '\0'; // Satır sonu karakterini kaldırır


                printf("Çalısanın yaşı nedir : ");
                int okunan = scanf("%d", &yas);
                if (okunan == 0) {
                    printf("hatalı giriş\n");
                    continue;

                }


                printf("Çalısanın Saatlik ücreti nedir : ");
                int ucretsorgu = scanf("%d", &saatlikucret);

                if (ucretsorgu == 0) {
                    printf("hatalı giriş\n");
                    continue;
                }

                printf("Çalısanın Çalışma saati nedir : ");
                int saatsorgu = scanf("%d", &calismasaati);
                if (saatsorgu == 0) {
                    printf("hatalı giriş\n");
                    continue;
                }

                // kullanıcıdan aldığımız değerlerden bir Çalışan oluşturmak icin calisanEkle() fonksiyonumuzu çalıştırıp

                calisanEkle(isim, yas, saatlikucret, calismasaati);
                a = 0;
            } else {
                printf("Maksimum çalışan sayısına ulaşıldı.\n");
            }

            //calisanalriDosyayaYaz fonksiyonuna calisanSayisini , dolayısıyla ekleyeceğimiz çalışanın Id'sini parametre olarak veriyoruz
            calisanlariDosyayaYaz(calisanSayisi);
            printf("-----Çalışan eklendi-----");
            a = 1;


        } else if (soru == 2) {
            calisanlariOku(calisanlar);


        } else if (soru == 3) {
            printf("programdan çıkış yapılıyor...");
            return 1;
        } else {
            printf("geçerli bir sayı giriniz");
        }
    }

        return 0;


}




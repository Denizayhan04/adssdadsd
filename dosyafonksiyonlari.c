#include <stdio.h>
#include "fonksiyonlar.h"
#define MAX_CALISAN_SAYISI 100


int dosyaVarMi() {
    // dosyanın var olup olmadığını kontrol etmek için dosyayı bir değişkene atayıp değerine bakıyoruz
    FILE *dosya = fopen("calisanlar.txt", "r");
    if (dosya == NULL) {
        return 0; // Dosya yok
    } else {
        fclose(dosya);
        return 1; // Dosya var
    }
}

void calisanlariOku(struct Calisan calisanlar[MAX_CALISAN_SAYISI]) {
    // dosyayı okuma modunda bir değişkene atıyoruz.
    FILE *filep = fopen("calisanlar.txt", "r");
    if (filep == NULL) {
        printf("Dosya açılamadı\n");
        return;
    }else{


    int index = 0; // hangi satırda olduğumuzu buradan belirliyoruz
    char satir[100]; // okuma yaparken kullanacapğımız satırı bir satırda max kaç karakter olacağını burada belirtiyoruz
    while (fgets(satir, sizeof(satir), filep) != NULL) {
        // okunan satır boş olana kadar tek tek satırları okur ve sscanf ile satırdan okunan değişkenleri calisanlar dizisinin index sırasındaki değerine atar
        sscanf(satir, "id:%d , isim:%99[^,] , yaş:%d , Saatlik ücret:%d , Çalışma saati:%d , Maaş:%d\n",
               &calisanlar[index].id, calisanlar[index].isim, &calisanlar[index].yas,
               &calisanlar[index].saatlikucret, &calisanlar[index].calismasaati, &calisanlar[index].maas);

        // calisanlar dizisinin index sırasındaki değerini ekrana basar
        printf("ID: %d, ", calisanlar[index].id);
        printf("İsim: %s, ", calisanlar[index].isim);
        printf("Yaş: %d, ", calisanlar[index].yas);
        printf("Saatlik Ücret: %d, ", calisanlar[index].saatlikucret);
        printf("Çalışma Saati: %d, ", calisanlar[index].calismasaati);
        printf("Maaş: %d\n", calisanlar[index].maas);

        index++; // indexi (satırı bir artırır)
        if (index >= MAX_CALISAN_SAYISI) {
            printf("Maksimum çalışan sayısına ulaşıldı.\n");
            break;
        }
    }

    fclose(filep); // dosyayı kapar
    }
}




void calisanlariDosyayaYaz(int id){ //calisan id'si bizim için yeni ekleyecegimiz çalısanın id'sini belirlemek için önemli
    if(dosyaVarMi()==0){ // eğer bir dosya yoksa "w" parametresi ile yeni dosya olusturur, eğer sayfa varsa "a" parametresi ile yeni calisan ekler
        FILE *filep = fopen("calisanlar.txt", "w"); // calisanlar adinda bir dosya olusturur
        if (filep == NULL) {
            printf("Dosya oluşturulamadı\n");
        }else{

        // aldıgımız id değerindeki calısanın özelliklerini dosyaya yazıyoruz
        fprintf(filep, "id:%d, isim:%s, yaş:%d, Saatlik ücret:%d, Çalışma saati:%d, Maaş:%d\n",
                calisanlar[id].id, calisanlar[id].isim, calisanlar[id].yas,
                calisanlar[id].saatlikucret, calisanlar[id].calismasaati, calisanlar[id].maas);


        fclose(filep); // dosyayi kapatır
        }
    }else if(dosyaVarMi()==1){ // halihazırda bir calisanlar.txt dosyamız varsa buraya yönlendiriliriz

        FILE *filep = fopen("calisanlar.txt", "a"); // ekleme yapmak için dosya değişkenini filep olarak al
        if (filep == NULL) {
            printf("Dosya oluşturulamadı\n");
        }else{

            // aldıgımız id değerindeki calısanın özelliklerini dosyaya yazıyoruz
            fprintf(filep, "id:%d, isim:%s, yaş:%d, Saatlik ücret:%d, Çalışma saati:%d, Maaş:%d\n",
                calisanlar[id].id, calisanlar[id].isim, calisanlar[id].yas,
                calisanlar[id].saatlikucret, calisanlar[id].calismasaati, calisanlar[id].maas);


        fclose(filep); // dosyayi kapar
        }
    }


}

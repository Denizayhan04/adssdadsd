
#ifndef FONKSIYONLAR_H
#define FONKSIYONLAR_H
#define MAX_CALISAN_SAYISI 100
struct Calisan {
    int id;
    char isim[30];
    int yas;
    int saatlikucret;
    int calismasaati;
    int maas;
};
struct Calisan calisanlar[MAX_CALISAN_SAYISI];


void calisanlariOku(struct Calisan calisanlar[MAX_CALISAN_SAYISI]);
void calisanlariDosyayaYaz(int id);




#endif //DONEM_SONU_PROJESI_FONKSIYONLAR_H

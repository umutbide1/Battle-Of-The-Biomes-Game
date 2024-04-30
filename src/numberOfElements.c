#include "numberOfElements.h"
#include <stdio.h>
#include "live.h"
int dosyadakiElemanSayisiniHesapla(const char *dosyaAdi) {
    FILE *dosya;
    dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya açma hatasi");
        return -1;
    }

    int sayiAdedi = 0;
    int sayi;
    while (fscanf(dosya, "%d", &sayi) != EOF) {
        sayiAdedi++;
    }

    fclose(dosya);
    return sayiAdedi;
}
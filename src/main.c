#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "herb.h"
#include "flea.h"
#include "habitat.h"
#include "housefly.h"
#include "insect.h"
#include "live.h"
#include "numberOfElements.h"
#include "numberOfElementsInRow.h"

int ilk_satirdaki_eleman_sayisi(const char *dosya_adi) {
    FILE *dosya = fopen(dosya_adi, "r");
    if (dosya == NULL) {
        perror("Dosya acma hatasi");
        return -1;
    }

    // İlk satırı oku
    char *satir = NULL;
    size_t satir_uzunlugu = 0;
    ssize_t okunan = getline(&satir, &satir_uzunlugu, dosya);
    if (okunan == -1) {
        perror("Satir okuma hatasi");
        fclose(dosya);
        free(satir);
        return -1;
    }

    // Okunan satırı elemanlara ayır ve eleman sayısını bul
    char *eleman = strtok(satir, " \t\n");
    int eleman_sayisi = 0;
    while (eleman != NULL) {
        eleman_sayisi++;
        eleman = strtok(NULL, " \t\n");
    }

    // Bellekten ayrılan yerleri serbest bırak
    free(satir);
    fclose(dosya);

    return eleman_sayisi;
}


int main() {
    Canli **nesneler = NULL;
    int index = 0;
    veriOku("veriler.txt", &nesneler, &index);
    // for (int i = 0; i < index; ++i) {
    //     nesneler[i]->gorunum(nesneler[i]);
    // }
    const char *dosyaAdi = "veriler.txt";
    int elemanSayisi = dosyadakiElemanSayisiniHesapla(dosyaAdi); 
    char *sembollerDizisi = (char *)malloc(elemanSayisi * sizeof(char)); // Dizinin sembollerinin tutulacağı dizi
    if (sembollerDizisi == NULL) {
        printf("Semboller icin bellek ayirma hatasi!");
        return 1;
    }

    int *degerlerDizisi = (int *)malloc(elemanSayisi * sizeof(int)); // dizideki sembollerin karşılıkları olan degerleri tutulacağı dizi
    if (degerlerDizisi==NULL){
        printf("Sembollere karsilik gelen degerler icin bellek ayirma hatasi");
    }
    // SatirElemanlari sonuc = satirlariOkuVeElemanSayilariniBul(dosyaAdi);
    // int *satirdakiELemenlarinSayisiDizisi = (int *)malloc(sonuc.satirSayisi * sizeof(int)); // Satirdaki elemanlarin sayilarinin yazılacaği dizi
    // for (int i = 0; i < sonuc.satirSayisi; i++) {
    //     satirdakiELemenlarinSayisiDizisi[i]=sonuc.elemanSayilari[i];
    //     //printf("%d",satirdakiELemenlarinSayisiDizisi[i]);
    // }
    
    //printf("\n");
    for (int i = 0; i < elemanSayisi; ++i) {
        sembollerDizisi[i]=nesneler[i]->sembol;
        //printf("%c",sembollerDizisi[i]);
        //printf("  ");
        
    }
    //printf("\n");
    for (int i = 0; i < elemanSayisi; ++i) {
        degerlerDizisi[i]=nesneler[i]->veri;
        //printf("%d",degerlerDizisi[i]);
        //printf(" ");
    }
    


    for (int i = 0; i < index; ++i) {
        free(nesneler[i]);
    }
    
    free(nesneler);
    //free(sonuc.elemanSayilari);
    //free(satirdakiELemenlarinSayisiDizisi);  
    return 0;
}


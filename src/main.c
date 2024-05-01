#include <stdio.h>
#include <stdlib.h>
#include "herb.h"
#include "flea.h"
#include "habitat.h"
#include "housefly.h"
#include "insect.h"
#include "live.h"
#include "numberOfElements.h"
#include "numberOfElementsInRow.h"



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
    int *degerlerDizisi = (int *)malloc(elemanSayisi * sizeof(int)); // dizideki sembollerin karşılıkları olan degerleri tutulacağı dizi
    
    if (sembollerDizisi == NULL) {
        printf("Semboller icin bellek ayirma hatasi!");
        return 1;
    }
    if (degerlerDizisi==NULL){
        printf("Sembollere karsilik gelen degerler icin bellek ayirma hatasi");
    }
    SatirElemanlari sonuc = satirlariOkuVeElemanSayilariniBul(dosyaAdi);
    int *satirdakiELemenlarinSayisiDizisi = (int *)malloc(sonuc.satirSayisi * sizeof(int)); // Satirdaki elemanlarin sayilarinin yazılacaği dizi
    for (int i = 0; i < sonuc.satirSayisi; i++) {
        satirdakiELemenlarinSayisiDizisi[i]= sonuc.elemanSayilari[i];
        
    }
    printf("\n");
    for (int i = 0; i < elemanSayisi; ++i) {
        sembollerDizisi[i]=nesneler[i]->sembol;
        printf("%c",sembollerDizisi[i]);
        printf("  ");
        
    }
    printf("\n");
    for (int i = 0; i < elemanSayisi; ++i) {
        degerlerDizisi[i]=nesneler[i]->veri;
        printf("%d",degerlerDizisi[i]);
        printf(" ");
    }
    for (int i = 0; i < sonuc.elemanSayilari; i++)
    {
        printf(degerlerDizisi[i]);
        printf(" ");
    }
    printf("\n");





    for (int i = 0; i < index; ++i) {
        free(nesneler[i]);
    }
    free(degerlerDizisi);
    free(nesneler);
    free(sonuc.elemanSayilari);
    free(satirdakiELemenlarinSayisiDizisi);  
    return 0;
}

//Son durum Savaş fonksiyonunda kaldım bugunlük bu kadar yeter :)
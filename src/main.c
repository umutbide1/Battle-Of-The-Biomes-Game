#include <stdio.h>
#include <stdlib.h>
#include "herb.h"
#include "flea.h"
#include "habitat.h"
#include "housefly.h"
#include "insect.h"
#include "live.h"
#include "numberOfElements.h"


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

    
    for (int i = 0; i < elemanSayisi; ++i) {
        sembollerDizisi[i]=nesneler[i]->sembol;
        printf("%c",sembollerDizisi[i]);
        printf("  ");
        
    }
    printf("\n");
    for (int i = 0; i < elemanSayisi; ++i) {
        sembollerDizisi[i]=nesneler[i]->sembol;
        printf("%d",nesneler[i]->veri);
        printf(" ");
    }






    for (int i = 0; i < index; ++i) {
        free(nesneler[i]);
    }
    free(nesneler);
    
    return 0;
}

//Son durum Savaş fonksiyonunda kaldım bugunlük bu kadar yeter :)
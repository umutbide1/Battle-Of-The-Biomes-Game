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
void savas(char *semboller, int *degerler, int n) {
    for (int i = 0; i < n; i++) {
        if (semboller[i] == 'X') continue;  // Bu canlı ölmüş ise atla
        for (int j = i + 1; j < n; j++) {
            if (semboller[j] == 'X') continue;  // Bu canlı ölmüş ise atla
            
            char first = semboller[i], second = semboller[j];
            int winner = -1;  // -1 durumunda kimse kazanamaz
            if ((first == 'C' && (second == 'B' || second == 'P')) ||
                (first == 'B' && (second == 'P' || second == 'S')) ||
                (first == 'S' && (second == 'P' || second == 'C'))) {
                winner = i;
            } else if ((second == 'C' && (first == 'B' || first == 'P')) ||
                       (second == 'B' && (first == 'P' || first == 'S')) ||
                       (second == 'S' && (first == 'P' || first == 'C'))) {
                winner = j;
            }

            if (winner == -1) { // Eğer türler aynı ise veya kimse doğal olarak kazanamıyorsa
                if (degerler[i] > degerler[j]) winner = i;
                else if (degerler[j] > degerler[i]) winner = j;
            }

            if (winner == i) semboller[j] = 'X';
            else if (winner == j) semboller[i] = 'X';
        }

        // Her savaş sonrası dizinin durumunu yazdır
        printf("Durum: ");
        for (int k = 0; k < n; k++) {
            printf("%c ", semboller[k]);
        }
        printf("\n");
    }
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
    int satirdakiElemanSayisi=ilk_satirdaki_eleman_sayisi("veriler.txt");
    printf("%d",satirdakiElemanSayisi);

        
    savas(sembollerDizisi, degerlerDizisi, 16);





    for (int i = 0; i < index; ++i) {
        free(nesneler[i]);
    }
    
    free(nesneler);
    //free(sonuc.elemanSayilari);
    //free(satirdakiELemenlarinSayisiDizisi);  
    return 0;
}


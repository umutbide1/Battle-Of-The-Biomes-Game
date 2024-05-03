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
#include <stdio.h>
#include <stdlib.h>

void savas(char *semboller, int *degerler, int n, int satirdakiElemanSayisi) {
    int i = 0;
    while (i < n - 1) {
        if (semboller[i] == 'X') {
            i++;
            continue;  // Bu canlı ölmüş ise bir sonrakine geç
        }

        int j = i + 1;
        while (j < n && semboller[j] == 'X') {
            j++;  // Ölü bir canlıyı atla ve savaşacak bir sonraki canlıyı bul
        }
        if (j == n) break;  // Eğer sağ kalan başka canlı yoksa döngüyü kır

        char first = semboller[i], second = semboller[j];
        int winner = -1;
        if ((first == 'C' && (second == 'B' || second == 'P')) ||
            (first == 'B' && (second == 'P' || second == 'S')) ||
            (first == 'S' && (second == 'P' || second == 'C'))) {
            winner = i;
        } else if ((second == 'C' && (first == 'B' || first == 'P')) ||
                   (second == 'B' && (first == 'P' || first == 'S')) ||
                   (second == 'S' && (first == 'P' || first == 'C'))) {
            winner = j;
        }

        if (winner == -1 && degerler[i] == degerler[j]) {  // Değerler eşit ve kazanan yoksa
            winner = (n - i < n - j) ? j : i;  // Dizinin sonuna daha yakın olan kaybeder
        } else if (winner == -1) { // Değerler farklı ama doğal kazanan yoksa
            winner = (degerler[i] > degerler[j]) ? i : j;
        }

        if (winner == i) {
            semboller[j] = 'X';  // i canlısı j'yi yedi
        } else {
            semboller[i] = 'X';  // j canlısı i'yi yedi, ve j canlısı devam edecek
            i = j;  // j sıradaki savaşçı olarak devam eder
        }

        // Her savaş sonrası dizinin durumunu yazdır
        printf("Durum:\n");
        for (int k = 0; k < n; k++) {
            printf("%c ", semboller[k]);
            if ((k + 1) % satirdakiElemanSayisi == 0) {
                printf("\n");  // Her satirdakiElemanSayisi eleman sonrası yeni satıra geç
            }
        }
        if (n % satirdakiElemanSayisi != 0) {
            printf("\n");
        }
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
    //printf("%d",satirdakiElemanSayisi);

        
    savas(sembollerDizisi, degerlerDizisi, elemanSayisi,satirdakiElemanSayisi);





    for (int i = 0; i < index; ++i) {
        free(nesneler[i]);
    }
    
    free(nesneler);
    //free(sonuc.elemanSayilari);
    //free(satirdakiELemenlarinSayisiDizisi);  
    return 0;
}


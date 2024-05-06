#include "habitat.h"
#include <stdio.h>
#include <stdlib.h>
#include "live.h"
#include "numberOfElements.h"
#include "numberOfElementsInRow.h"
void veriOku(const char *dosyaAdi, Canli ***nesneler, int *index) {
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        exit(1);
    }
    int sayac=0;
    int sayi;
    while (fscanf(dosya, "%d", &sayi) != EOF) {
        sayac++;
        if (sayi >= 1 && sayi <= 9) { // Bitki
            *nesneler = (Canli**)realloc(*nesneler, (*index + 1) * sizeof(Canli*));
            (*nesneler)[*index] = (Canli*)bitkiOlustur(sayi);
            (*index)++;
        } else if (sayi >= 10 && sayi <= 20) { // Bocek
            *nesneler = (Canli**)realloc(*nesneler, (*index + 1) * sizeof(Canli*));
            (*nesneler)[*index] = (Canli*)bocekOlustur(sayi);
            (*index)++;
        } else if (sayi >= 21 && sayi <= 50) { // Sinek
            *nesneler = (Canli**)realloc(*nesneler, (*index + 1) * sizeof(Canli*));
            (*nesneler)[*index] = (Canli*)sinekOlustur(sayi);
            (*index)++;
        } else { // Pire
            *nesneler = (Canli**)realloc(*nesneler, (*index + 1) * sizeof(Canli*));
            (*nesneler)[*index] = (Canli*)pireOlustur(sayi);
            (*index)++;
        }
        
    }

    
    fclose(dosya); // Dosyayı kapat
}
void savas(SavasDurumu *durum) {
    char *semboller = durum->semboller;
    int *degerler = durum->degerler;
    int n = durum->elemanSayisi;
    int satirdakiElemanSayisi = durum->satirdakiElemanSayisi;
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
        system("cls");
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
int hazirlaVeriler(const char *dosyaAdi, SavasDurumu *durum) {
    Canli **nesneler = NULL;
    int index = 0;
    veriOku(dosyaAdi, &nesneler, &index);

    durum->elemanSayisi = dosyadakiElemanSayisiniHesapla(dosyaAdi);
    durum->semboller = (char *)malloc(durum->elemanSayisi * sizeof(char));
    if (durum->semboller == NULL) {
        return -1;  // Hata durumunda -1 dön
    }

    durum->degerler = (int *)malloc(durum->elemanSayisi * sizeof(int));
    if (durum->degerler == NULL) {
        free(durum->semboller);  // Önceki ayrılmış belleği serbest bırak
        return -2;  // Hata durumunda -2 dön
    }

    for (int i = 0; i < durum->elemanSayisi; ++i) {
        durum->semboller[i] = nesneler[i]->sembol;
        durum->degerler[i] = nesneler[i]->veri;
    }

    durum->satirdakiElemanSayisi = ilk_satirdaki_eleman_sayisi(dosyaAdi);

    for (int i = 0; i < index; ++i) {
        free(nesneler[i]);
    }
    free(nesneler);

    return 0;  // Başarı durumunda 0 dön
}
#ifndef HABITAT_HPP
#define HABITAT_HPP

#include "live.h"
#include "flea.h" // Pire sınıfından oluşturulan ve nesneler dizisinde yer alacak pire -
#include "herb.h"  // için alan açılma işlemi burada o yüzden bu kütüphane burada olmalı diğer 
#include "housefly.h" // kütüphane eklemeleri de aynı şekilde 

void veriOku(const char *dosyaAdi, Canli ***nesneler, int *index); // Fonksiyonun imzası

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

        if (winner == -1) { // Eğer türler aynı ise veya kimse doğal olarak kazanamıyorsa
            if (degerler[i] > degerler[j]) winner = i;
            else if (degerler[j] > degerler[i]) winner = j;
        }

        if (winner == i) {
            semboller[j] = 'X';  // i canlısı j'yi yedi
        } else {
            semboller[i] = 'X';  // j canlısı i'yi yedi, ve j canlısı devam edecek
            i = j;  // j sıradaki savaşçı olarak devam eder
        }

        // Her savaş sonrası dizinin durumunu yazdır
        printf("Durum: ");
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







#endif
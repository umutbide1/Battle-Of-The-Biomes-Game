#include "habitat.h"
#include <stdio.h>
#include <stdlib.h>
#include "live.h"
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
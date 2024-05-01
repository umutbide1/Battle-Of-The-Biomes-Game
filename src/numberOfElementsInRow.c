#ifndef NUMBEROFELEMENTSINROW_HPP_
#define NUMBEROFELEMENTSINROW_HPP_
#include "numberOfElementsInRow.h"
#include <stdio.h>
#include <stdlib.h>
#include "numberOfElements.h"
#include <string.h>  

// SatirElemanlari satirlariOkuVeElemanSayilariniBul(const char* dosyaAdi) {
//     FILE *file = fopen(dosyaAdi, "r");
//     if (!file) {
//         fprintf(stderr, "Dosya acilamadi.\n");
//         exit(EXIT_FAILURE);
//     }

//     char line[1024];
//     int* elemanSayilari = NULL;
//     int satirSayisi = 0;
//     int elemanSayisi;
//     char *token;
    
//     while (fgets(line, sizeof(line), file)) {
//         elemanSayisi = 0;
//         token = strtok(line, " \t\n");
//         while (token != NULL) {
//             elemanSayisi++;
//             token = strtok(NULL, " \t\n");
//         }
//         elemanSayilari = realloc(elemanSayilari, (satirSayisi + 1) * sizeof(int));
//         elemanSayilari[satirSayisi++] = elemanSayisi;
//     }

//     fclose(file);

//     SatirElemanlari result;
//     result.elemanSayilari = elemanSayilari;
//     result.satirSayisi = satirSayisi;
//     return result;
// }
int ilk_satirdaki_eleman_sayisi(const char *dosya_adi) {
    FILE *dosya = fopen(dosya_adi, "r");
    if (dosya == NULL) {
        perror("Dosya acma hatasi");
        return -1;
    }

    char *satir = NULL;
    size_t satir_uzunlugu = 0;
    int okunan = getline(&satir, &satir_uzunlugu, dosya);
    if (okunan == -1) {
        perror("Satir okuma hatasi");
        fclose(dosya);
        free(satir);
        return -1;
    }

    char *eleman = strtok(satir, " \t\n");
    int eleman_sayisi = 0;
    while (eleman != NULL) {
        eleman_sayisi++;
        eleman = strtok(NULL, " \t\n");
    }

    free(satir);
    fclose(dosya);

    return eleman_sayisi;
}



#endif
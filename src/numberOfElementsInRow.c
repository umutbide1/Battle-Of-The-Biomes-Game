#ifndef NUMBEROFELEMENTSINROW_HPP_
#define NUMBEROFELEMENTSINROW_HPP_
#include "numberOfElementsInRow.h"
#include <stdio.h>
#include <stdlib.h>
#include "numberOfElements.h"
#include <string.h>  

SatirElemanlari satirlariOkuVeElemanSayilariniBul(const char* dosyaAdi) {
    FILE *file = fopen(dosyaAdi, "r");
    if (!file) {
        fprintf(stderr, "Dosya acilamadi.\n");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    int* elemanSayilari = NULL;
    int satirSayisi = 0;
    int elemanSayisi;
    char *token;
    
    while (fgets(line, sizeof(line), file)) {
        elemanSayisi = 0;
        token = strtok(line, " \t\n");
        while (token != NULL) {
            elemanSayisi++;
            token = strtok(NULL, " \t\n");
        }
        elemanSayilari = realloc(elemanSayilari, (satirSayisi + 1) * sizeof(int));
        elemanSayilari[satirSayisi++] = elemanSayisi;
    }

    fclose(file);

    SatirElemanlari result;
    result.elemanSayilari = elemanSayilari;
    result.satirSayisi = satirSayisi;
    return result;
}



#endif
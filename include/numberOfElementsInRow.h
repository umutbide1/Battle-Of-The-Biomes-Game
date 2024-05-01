#include <stdio.h>
#include <stdlib.h>
#include "numberOfElements.h"
typedef struct {
    int* elemanSayilari;
    int satirSayisi;
} SatirElemanlari;

SatirElemanlari satirlariOkuVeElemanSayilariniBul(const char* dosyaAdi);
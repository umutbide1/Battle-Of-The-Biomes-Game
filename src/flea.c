#include "flea.h"
#include <stdio.h>
#include <stdlib.h>
#include "insect.h"
#include "live.h"
Pire* pireOlustur(int veri) {
    Pire *pire = (Pire*)malloc(sizeof(Pire));
    pire->super.super.veri = veri;
    pire->super.super.sembol = 'P';
    pire->super.super.gorunum = gorunumYazdir;
    return pire;
    
}
void gorunumYazdirPire(struct Pire *pire) {
    printf("%c ", pire->super.super.sembol);
}

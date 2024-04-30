#include "flea.h"
#include <stdio.h>
#include <stdlib.h>

Pire* pireOlustur(int veri) {
    Pire *pire = (Pire*)malloc(sizeof(Pire));
    pire->super.super.veri = veri;
    pire->super.super.sembol = 'P';
    pire->super.super.gorunum = gorunumYazdir;
    return pire;
    
}

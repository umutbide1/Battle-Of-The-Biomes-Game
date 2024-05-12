#include "housefly.h"
#include <stdio.h>
#include <stdlib.h>
Sinek* sinekOlustur(int veri) {
    Sinek *sinek = (Sinek*)malloc(sizeof(Sinek));
    sinek->super.super.veri = veri;
    sinek->super.super.sembol = 'S';
    sinek->super.super.gorunum = gorunumYazdir;
    return sinek;
}
void gorunumYazdirSinek(Sinek *canli) {
    printf("%c ", canli->super.super.sembol);
}

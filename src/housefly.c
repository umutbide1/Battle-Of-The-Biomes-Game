#include "housefly.h"
#include <stdio.h>
#include <stdlib.h>
#include "insect.h"
#include "live.h"
Sinek* sinekOlustur(int veri) {
    Sinek *sinek = (Sinek*)malloc(sizeof(Sinek));
    sinek->super.super.veri = veri;
    sinek->super.super.sembol = 'S';
    sinek->super.super.gorunum = gorunumYazdir;
    return sinek;
}
void gorunumYazdirSinek(struct Sinek *sinek) {
    printf("%c ", sinek->super.super.sembol);
}

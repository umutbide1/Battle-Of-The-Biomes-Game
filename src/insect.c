#include "insect.h"
#include <stdio.h>
#include <stdlib.h>

Bocek* bocekOlustur(int veri) {
    Bocek *bocek = (Bocek*)malloc(sizeof(Bocek));
    bocek->super.veri = veri;
    bocek->super.sembol = 'C';
    bocek->super.gorunum = gorunumYazdir;
    return bocek;
}

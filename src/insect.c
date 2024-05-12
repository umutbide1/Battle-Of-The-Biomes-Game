#include "insect.h"
#include <stdio.h>
#include <stdlib.h>
#include "live.h"
Bocek* bocekOlustur(int veri) {
    Bocek *bocek = (Bocek*)malloc(sizeof(Bocek));
    bocek->super.veri = veri;
    bocek->super.sembol = 'C';
    bocek->super.gorunum = gorunumYazdir;
    return bocek;
}
void gorunumYazdirBocek(struct Bocek *bocek) {
    printf("%c ", bocek->super.sembol);
}

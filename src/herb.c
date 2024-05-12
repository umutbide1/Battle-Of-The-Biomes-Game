#include "herb.h"
#include <stdio.h>
#include <stdlib.h>
#include "live.h"
Bitki* bitkiOlustur(int veri) {
    Bitki *bitki = (Bitki*)malloc(sizeof(Bitki));
    bitki->super.veri = veri;
    bitki->super.sembol = 'B';
    bitki->super.gorunum = gorunumYazdir;
    return bitki;
    
}
void gorunumYazdirBitki(struct Bitki *bitki) {
    printf("%c ", bitki->super.sembol);
}

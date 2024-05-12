#include "herb.h"
#include <stdio.h>
#include <stdlib.h>
Bitki* bitkiOlustur(int veri) {
    Bitki *bitki = (Bitki*)malloc(sizeof(Bitki));
    bitki->super.veri = veri;
    bitki->super.sembol = 'B';
    bitki->super.gorunum = gorunumYazdir;
    return bitki;
    
}
void gorunumYazdirBitki(Bitki *canli) {
    printf("%c ", canli->super.sembol);
}

#include <stdio.h>
#include <stdlib.h>


typedef struct Canli {
    int veri;    
    char sembol; 
    void (*gorunum)(struct Canli *); 
} Canli;


typedef struct {
    Canli canli; 
} Bitki;


typedef struct {
    Canli canli; 
} Bocek;


typedef struct {
    Bocek bocek; 
} Pire;


typedef struct {
    Bocek bocek; 
} Sinek;


void bitkiOlustur(Bitki *);


void bocekOlustur(Bocek *);


void pireOlustur(Pire *);

void sinekOlustur(Sinek *);

void gorunumYazdir(Canli *);

void veriOku(const char *dosyaAdi);



void bitkiOlustur(Bitki *bitki) {
    bitki->canli.sembol = 'B';
    bitki->canli.gorunum = gorunumYazdir;
}

void bocekOlustur(Bocek *bocek) {
    bocek->canli.sembol = 'C';
    bocek->canli.gorunum = gorunumYazdir;
}

void pireOlustur(Pire *pire) {
    pire->bocek.canli.sembol = 'P';
    pire->bocek.canli.gorunum = gorunumYazdir;
}

void sinekOlustur(Sinek *sinek) {
    sinek->bocek.canli.sembol = 'S';
    sinek->bocek.canli.gorunum = gorunumYazdir;
}

void gorunumYazdir(Canli *canli) {
    printf("%c(%d) ", canli->sembol, canli->veri);
}

void veriOku(const char *dosyaAdi) {
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        exit(1);
    }

    int sayi;
    while (fscanf(dosya, "%d", &sayi) != EOF) {
        if (sayi >= 1 && sayi <= 9) {
            Bitki bitki;
            bitkiOlustur(&bitki);
            bitki.canli.veri = sayi;
            bitki.canli.gorunum(&bitki.canli);
        } else if (sayi >= 10 && sayi <= 20) { 
            Bocek bocek;
            bocekOlustur(&bocek);
            bocek.canli.veri = sayi;
            bocek.canli.gorunum(&bocek.canli);
        } else if (sayi >= 21 && sayi <= 50) { 
            Sinek sinek;
            sinekOlustur(&sinek);
            sinek.bocek.canli.veri = sayi;
            sinek.bocek.canli.gorunum(&sinek.bocek.canli);
        } else { // Pire
            Pire pire;
            pireOlustur(&pire);
            pire.bocek.canli.veri = sayi;
            pire.bocek.canli.gorunum(&pire.bocek.canli);
        }
    }

    fclose(dosya); 
}
int main() {
    veriOku("veriler.txt");
    return 0;
}
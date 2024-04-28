#include <stdio.h>
#include <stdlib.h>

// Canli sınıfı
typedef struct Canli {
    int veri;    // Veri
    char sembol; // Canlinin sembolu
    void (*gorunum)(struct Canli *); // Canlinin görünümünü yazdıracak fonksiyon işaretçisi
} Canli;

// Bitki sınıfı, Canli sınıfından kalıtım alır
typedef struct {
    Canli canli; // Canli sınıfı
} Bitki;

// Bocek sınıfı, Canli sınıfından kalıtım alır
typedef struct {
    Canli canli; // Canli sınıfı
} Bocek;

// Pire sınıfı, Bocek sınıfından dolaylı olarak Canli sınıfından kalıtım alır
typedef struct {
    Bocek bocek; // Bocek sınıfı
} Pire;

// Sinek sınıfı, Bocek sınıfından dolaylı olarak Canli sınıfından kalıtım alır
typedef struct {
    Bocek bocek; // Bocek sınıfı
} Sinek;

// Bitki nesnesi oluşturacak fonksiyon
void bitkiOlustur(Bitki *);

// Bocek nesnesi oluşturacak fonksiyon
void bocekOlustur(Bocek *);

// Pire nesnesi oluşturacak fonksiyon
void pireOlustur(Pire *);

// Sinek nesnesi oluşturacak fonksiyon
void sinekOlustur(Sinek *);

// Canlinin görünümünü ekrana yazdıracak fonksiyon
void gorunumYazdir(Canli *);

// Verileri okuyup uygun sınıf nesnelerini oluşturacak fonksiyon
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
        if (sayi >= 1 && sayi <= 9) { // Bitki
            Bitki bitki;
            bitkiOlustur(&bitki);
            bitki.canli.veri = sayi;
            bitki.canli.gorunum(&bitki.canli);
        } else if (sayi >= 10 && sayi <= 20) { // Bocek
            Bocek bocek;
            bocekOlustur(&bocek);
            bocek.canli.veri = sayi;
            bocek.canli.gorunum(&bocek.canli);
        } else if (sayi >= 21 && sayi <= 50) { // Sinek
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

    fclose(dosya); // Dosyayı kapat
}
int main() {
    veriOku("veriler.txt");
    return 0;
}
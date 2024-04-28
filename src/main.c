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
Bitki* bitkiOlustur(int veri);

// Bocek nesnesi oluşturacak fonksiyon
Bocek* bocekOlustur(int veri);

// Pire nesnesi oluşturacak fonksiyon
Pire* pireOlustur(int veri);

// Sinek nesnesi oluşturacak fonksiyon
Sinek* sinekOlustur(int veri);

// Canlinin görünümünü ekrana yazdıracak fonksiyon
void gorunumYazdir(Canli *);

// Verileri okuyup uygun sınıf nesnelerini oluşturacak fonksiyon
void veriOku(const char *dosyaAdi, Canli ***nesneler, int *index);


Bitki* bitkiOlustur(int veri) {
    Bitki *bitki = (Bitki*)malloc(sizeof(Bitki));
    bitki->canli.veri = veri;
    bitki->canli.sembol = 'B';
    bitki->canli.gorunum = gorunumYazdir;
    return bitki;
}

Bocek* bocekOlustur(int veri) {
    Bocek *bocek = (Bocek*)malloc(sizeof(Bocek));
    bocek->canli.veri = veri;
    bocek->canli.sembol = 'C';
    bocek->canli.gorunum = gorunumYazdir;
    return bocek;
}

Pire* pireOlustur(int veri) {
    Pire *pire = (Pire*)malloc(sizeof(Pire));
    pire->bocek.canli.veri = veri;
    pire->bocek.canli.sembol = 'P';
    pire->bocek.canli.gorunum = gorunumYazdir;
    return pire;
}

Sinek* sinekOlustur(int veri) {
    Sinek *sinek = (Sinek*)malloc(sizeof(Sinek));
    sinek->bocek.canli.veri = veri;
    sinek->bocek.canli.sembol = 'S';
    sinek->bocek.canli.gorunum = gorunumYazdir;
    return sinek;
}

void gorunumYazdir(Canli *canli) {
    printf("%c ", canli->sembol);
}

void veriOku(const char *dosyaAdi, Canli ***nesneler, int *index) {
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        exit(1);
    }

    int sayi;
    while (fscanf(dosya, "%d", &sayi) != EOF) {
        if (sayi >= 1 && sayi <= 9) { // Bitki
            *nesneler = (Canli**)realloc(*nesneler, (*index + 1) * sizeof(Canli*));
            (*nesneler)[*index] = (Canli*)bitkiOlustur(sayi);
            (*index)++;
        } else if (sayi >= 10 && sayi <= 20) { // Bocek
            *nesneler = (Canli**)realloc(*nesneler, (*index + 1) * sizeof(Canli*));
            (*nesneler)[*index] = (Canli*)bocekOlustur(sayi);
            (*index)++;
        } else if (sayi >= 21 && sayi <= 50) { // Sinek
            *nesneler = (Canli**)realloc(*nesneler, (*index + 1) * sizeof(Canli*));
            (*nesneler)[*index] = (Canli*)sinekOlustur(sayi);
            (*index)++;
        } else { // Pire
            *nesneler = (Canli**)realloc(*nesneler, (*index + 1) * sizeof(Canli*));
            (*nesneler)[*index] = (Canli*)pireOlustur(sayi);
            (*index)++;
        }
    }

    fclose(dosya); // Dosyayı kapat
}
int main() {
    Canli **nesneler = NULL;
    int index = 0;
    veriOku("veriler.txt", &nesneler, &index);

    // Oluşturulan nesneleri ekrana yazdır
    for (int i = 0; i < index; ++i) {
        nesneler[i]->gorunum(nesneler[i]);
    }
    
    // Oluşturulan nesnelerin belleklerini serbest bırak
    for (int i = 0; i < index; ++i) {
        free(nesneler[i]);
    }
    free(nesneler);
    
    return 0;
}

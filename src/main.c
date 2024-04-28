#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int veri;    
    char sembol; 
} Canli;

// Bitki sınıfı, Canli sınıfından kalıtım alır
typedef struct {
    Canli canli; 
} Bitki;

// Bocek sınıfı, Canli sınıfından kalıtım alır
typedef struct {
    Canli canli; 
} Bocek;

// Pire sınıfı Bocek sınıfından dolaylı olarak Canli sınıfından kalıtım alır
typedef struct {
    Bocek bocek; 
} Pire;

// Sinek sınıfı, Bocek sınıfından dolaylı olarak Canli sınıfından kalıtım alır
typedef struct {
    Bocek bocek; 
} Sinek;


void veriOku(const char *dosyaAdi);

int main() {
    veriOku("veriler.txt");
    return 0;
}

void veriOku(const char *dosyaAdi) {
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        exit(1);
    }

    char semboller[] = {'B', 'C', 'S', 'P'}; 
    int sayi;
    while (fscanf(dosya, "%d", &sayi) != EOF) {
        Canli *canli; // Canli sınıfı işaretçisi
        if (sayi >= 1 && sayi <= 9) { 
            Bitki *bitki = (Bitki *)malloc(sizeof(Bitki));
            bitki->canli.sembol = semboller[0];
            bitki->canli.veri = sayi; 
            canli = (Canli *)bitki;
        } else if (sayi >= 10 && sayi <= 20) { // Bocek
            Bocek *bocek = (Bocek *)malloc(sizeof(Bocek));
            bocek->canli.sembol = semboller[1];
            bocek->canli.veri = sayi; // Veriyi ayarla
            canli = (Canli *)bocek;
        } else if (sayi >= 21 && sayi <= 50) { // Sinek
            Sinek *sinek = (Sinek *)malloc(sizeof(Sinek));
            sinek->bocek.canli.sembol = semboller[2];
            sinek->bocek.canli.veri = sayi; // Veriyi ayarla
            canli = (Canli *)sinek;
        } else { // Pire
            Pire *pire = (Pire *)malloc(sizeof(Pire));
            pire->bocek.canli.sembol = semboller[3];
            pire->bocek.canli.veri = sayi; // Veriyi ayarla
            canli = (Canli *)pire;
        }

        
        printf("%c(%d) ", canli->sembol, canli->veri);

        free(canli); // Bellek temizleme
    }

    fclose(dosya);
}

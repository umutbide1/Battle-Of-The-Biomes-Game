#include <stdio.h>
#include <stdlib.h>

// Bitki için gösterim fonksiyonu
char bitki_gorunum() {
    return 'B';
}

// Böcek için gösterim fonksiyonu
char bocek_gorunum() {
    return 'C';
}

// Sinek için gösterim fonksiyonu
char sinek_gorunum() {
    return 'S';
}

// Pire için gösterim fonksiyonu
char pire_gorunum() {
    return 'P';
}

int main() {
    FILE *dosya;
    dosya = fopen("Veri.txt", "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi!");
        return 1;
    }
    
    int deger;
    // Dosyanın sonuna kadar işlem yap
    while (fscanf(dosya, "%d", &deger) == 1) {
        if (deger >= 1 && deger <= 9) {
            printf("%c ", bitki_gorunum());
        } else if (deger >= 10 && deger <= 20) {
            printf("%c ", bocek_gorunum());
        } else if (deger >= 21 && deger <= 50) {
            printf("%c ", sinek_gorunum());
        } else if (deger >= 51 && deger <= 99) {
            printf("%c ", pire_gorunum());
        } else {
            printf("H ");
        }   
        
        // Satır sonuna geldiğinde bir satır atla
        char c;
        fscanf(dosya, "%c", &c);
        if (c == '\n') {
            printf("\n");
        }
    }

    fclose(dosya);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "herb.h"
#include "flea.h"
#include "habitat.h"
#include "housefly.h"
#include "insect.h"
#include "live.h"
#include "numberOfElements.h"


int main() {
    Canli **nesneler = NULL;
    int index = 0;
    veriOku("veriler.txt", &nesneler, &index);
    // for (int i = 0; i < index; ++i) {
    //     nesneler[i]->gorunum(nesneler[i]);
    // }
    const char *dosyaAdi = "veriler.txt";
    int elemanSayisi = dosyadakiElemanSayisiniHesapla(dosyaAdi); 
    
    char *dizi = (char *)malloc(elemanSayisi * sizeof(char));
    if (dizi == NULL) {
        printf("Bellek ayirma hatasi!");
        return 1;
    }
    for (int i = 0; i < elemanSayisi; ++i) {
        dizi[i]=nesneler[i]->sembol;
        printf("%c",dizi[i]);
    }
    for (int i = 0; i < index; ++i) {
        free(nesneler[i]);
    }
    free(nesneler);
    
    return 0;
}

//
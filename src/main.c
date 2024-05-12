#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "herb.h"
#include "flea.h"
#include "habitat.h"
#include "housefly.h"
#include "insect.h"
#include "live.h"
#include "numberOfElements.h"
#include "numberOfElementsInRow.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    const char *dosyaAdi = "veriler.txt";
    SavasDurumu durum;
    if (hazirlaVeriler(dosyaAdi, &durum) != 0) {
        fprintf(stderr, "Bellek ayirma hatasi veya dosya okuma hatasi!");
        return EXIT_FAILURE;
    }

    savas(&durum);
    // odev sonu 
    free(durum.semboller);
    free(durum.degerler);
    return EXIT_SUCCESS;
}



#ifndef CANLI_HPP
#define CANLI_HPP

#include "herb.h"
#include "flea.h"
#include "habitat.h"
#include "housefly.h"
#include "insect.h"


typedef struct Canli {
    int veri;    // Veri
    char sembol; // Canlinin sembolu
    void (*gorunum)(struct Canli *); // Canlinin görünümünü yazdıracak fonksiyon işaretçisi
} Canli;

#endif
#ifndef PIRE_HPP
#define PIRE_HPP

#include "insect.h"
typedef struct Pire { // Pire structi
    Bocek super; 
} Pire;

Pire* pireOlustur(int veri); // Pire oluşturmak üzere çalışacak fonksiyon
void gorunumYazdirPire(Pire *);




#endif
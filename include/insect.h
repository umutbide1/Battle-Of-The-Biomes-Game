#ifndef BOCEK_HPP
#define BOCEK_HPP

#include "live.h"
typedef struct Bocek {
    Canli super; // Canli sınıfı
} Bocek;

// Bocek nesnesi oluşturacak fonksiyon
Bocek* bocekOlustur(int veri);
void gorunumYazdirBocek(Bocek *);




#endif
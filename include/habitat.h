#ifndef HABITAT_HPP
#define HABITAT_HPP

#include "live.h"
#include "flea.h" // Pire sınıfından oluşturulan ve nesneler dizisinde yer alacak pire -
#include "herb.h"  // için alan açılma işlemi burada o yüzden bu kütüphane burada olmalı diğer 
#include "housefly.h" // kütüphane eklemeleri de aynı şekilde 

void veriOku(const char *dosyaAdi, Canli ***nesneler, int *index); // Fonksiyonun imzası


typedef struct {
    char *semboller;
    int *degerler;
    int elemanSayisi;
    int satirdakiElemanSayisi;
} SavasDurumu;

void savas(SavasDurumu *durum);

int hazirlaVeriler(const char *dosyaAdi, SavasDurumu *durum) ;

#endif
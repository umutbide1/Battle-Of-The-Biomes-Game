
typedef struct Canli {
    int veri;    // Veri
    char sembol; // Canlinin sembolu
    void (*gorunum)(struct Canli *); // Canlinin görünümünü yazdıracak fonksiyon işaretçisi
} Canli;


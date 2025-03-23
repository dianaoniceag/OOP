#ifndef CHELTUIALA_H
#define CHELTUIALA_H

#define MAX_CHELTUIELI 10000

typedef struct {
    int nr_ap;
    float suma;
    char tip[15];
}Cheltuiala;

Cheltuiala* creeaza(int nr_ap, float suma, char tip[15]);

#endif //CHELTUIALA_H
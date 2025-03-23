#include "Cheltuiala.h"

#include <stdio.h>
#include <stdlib.h>
#include<string.h>


Cheltuiala* creeaza(int nr_ap, float suma, char tip[15]) {
    /*Creeaza o cheltuiala
    param nr_ap: numarul apartamentului de tip int
    param suma: suma cheltuielii de tip float
    param tip: tipul cheltuielii (apa/incalzire/canal/gaz) de tip *char
    return: none
    */
    Cheltuiala* cheltuiala = (Cheltuiala*)malloc(sizeof(Cheltuiala));
    if (cheltuiala == NULL) {
        printf("Eroare la alocarea cheltuielii!\n");
        exit(1);
    }
    cheltuiala->nr_ap = nr_ap;
    cheltuiala->suma = suma;
    strcpy(cheltuiala->tip, tip);

    return cheltuiala;

}

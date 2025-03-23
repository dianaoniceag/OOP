#ifndef SERVICE_H
#define SERVICE_H

#include "Cheltuiala.h"

typedef struct {
    Cheltuiala** lista;
    int nr_cheltuieli;
    int capacitate;
}RepoCheltuieli;
typedef int(*FunctieComparare)(void* c1, void*c2);

void init_repo(RepoCheltuieli* repo);

void adaugare(RepoCheltuieli* repo, int numar_apartament, float suma, char tip[15]);

void test_adaugare();

int cautare(RepoCheltuieli* repo, int numar_apartament, float suma, char tip[15]);

void test_cautare();

int stergere(RepoCheltuieli* repo, int nr_ap, float suma, char tip[15]);

void test_stergere();

int modificare(RepoCheltuieli* repo, int numar_apartament, float suma, char tip[15], float new_suma, char new_tip[15]);

void test_modificare();

int filtrare_prop(RepoCheltuieli* repo, int prop, float equal, int rez[MAX_CHELTUIELI]);

void test_filtrare_prop();

void filtrare_sortata(RepoCheltuieli* repo,int tip,int cresc,int rez[MAX_CHELTUIELI]);

void test_filtrare_sortata();


int cmp_tip_cresc(void *c1, void *c2);
int cmp_tip_desc(void *c1, void *c2);
int cmp_suma_cresc(void *c1, void *c2);
int cmp_suma_desc(void *c1, void *c2);
void test_cmp();
void sortare(RepoCheltuieli* repo,int ord[MAX_CHELTUIELI],FunctieComparare functie);
void test_sortare();
#endif

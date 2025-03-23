#include "Controller.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

void adaugare(RepoCheltuieli* repo, int nr_ap, float suma, char tip[15]) {
    /*Adauga o cheltuiala la lista cheltuielilor
    param nr_ap: numarul apartamentului de tip int
    param suma: suma cheltuielii de tip float
    param tip: tipul cheltuielii (apa/incalzire/canal/gaz) de tip char*
    return: None
    */
    if (repo->nr_cheltuieli==repo->capacitate) {
        repo->capacitate*=2;
        repo->lista=(Cheltuiala**)realloc(repo->lista,repo->capacitate*sizeof(Cheltuiala*));
    }
    repo->lista[repo->nr_cheltuieli++]=creeaza(nr_ap,suma,tip);
}

void test_adaugare() {
    RepoCheltuieli repo;
    repo.nr_cheltuieli = 0;
    repo.capacitate = 2;
    repo.lista = (Cheltuiala**)malloc(repo.capacitate * sizeof(Cheltuiala*));
    char apa[15]="apa",incalzire[15]="incalzire",gaz[15]="gaz";
    adaugare(&repo, 1, 100.5f, apa);
    assert(repo.nr_cheltuieli == 1);
    assert(repo.lista[0]->nr_ap == 1);
    assert(repo.lista[0]->suma == 100.5f);
    assert(strcmp(repo.lista[0]->tip, apa) == 0);
    adaugare(&repo, 2, 200.0f, gaz);
    assert(repo.nr_cheltuieli == 2);
    adaugare(&repo, 3, 150.75f, incalzire);
    assert(repo.nr_cheltuieli == 3);
    assert(repo.capacitate == 4);
    printf("Toate testele pentru adaugare au trecut cu succes!\n");
    for (int i = 0; i < repo.nr_cheltuieli; i++) {
        free(repo.lista[i]);
    }
    free(repo.lista);
}


int cautare(RepoCheltuieli* repo, int numar_apartament, float suma, char tip[15]) {
    /*Cauta o cheltuiala in lista cheltuielilor
    param numar_apartament: numar apartamentului de tip int
    param suma: suma cheltuielii de tip float
    param tip: tipul cheltuielii (apa/incalzire/canal/gaz)
    return: indexul cheltuielii in lista cheltuielilor daca este gasita, -1 altfel
    */
    for (int i=0; i <repo->nr_cheltuieli; i++) {
        if (repo->lista[i]->nr_ap == numar_apartament && repo->lista[i]->suma == suma && strcmp(repo->lista[i]->tip,tip)==0) {
            return i;
        }
    }
    return -1;
}

void test_cautare() {
    RepoCheltuieli repo;
    repo.nr_cheltuieli = 0;
    repo.capacitate=3;
    repo.lista=(Cheltuiala**)malloc(repo.capacitate*sizeof(Cheltuiala*));
    repo.lista[0] = (Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[0]) = (Cheltuiala){1, 100.5f, "apa"};
    repo.lista[1] = (Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[1]) = (Cheltuiala){2, 200.0f, "gaz"};
    repo.lista[2] = (Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[2]) = (Cheltuiala){3, 150.75f, "incalzire"};
    repo.nr_cheltuieli = 3;
    int rez;
    char apa[15]="apa",incalzire[15]="incalzire",gaz[15]="gaz",curent[15]="curent";
    rez = cautare(&repo, 1, 100.5f, apa);
    assert(rez == 0);
    rez = cautare(&repo, 3, 150.75f, incalzire);
    assert(rez == 2);
    rez = cautare(&repo, 4, 50.0f, curent);
    assert(rez == -1);
    rez = cautare(&repo, 2, 100.0f, gaz);
    assert(rez == -1);
    rez = cautare(&repo, 1, 100.5f, gaz);
    assert(rez == -1);
    printf("Toate testele pentru cautare_cheltuiala au trecut cu succes!\n");
    for (int i = 0; i < repo.nr_cheltuieli; i++) {
        free(repo.lista[i]);
    }
    free(repo.lista);
}

int modificare(RepoCheltuieli* repo, int numar_apartament, float suma, char tip[15],float new_suma, char new_tip[15]) {
    /*Modifica suma si tipul unei cheltuieli
    param numar_apartament: numar apartamentului de tip int
    param suma: vechea suma a cheltuielii de tip float
    param tip: vechiul tip al cheltuielii de tip char[]
    param new_suma: noua suma a cheltuielii de tip float
    param new_tip: noul tip al cheltuielii de tip char[]
    return: 1 daca modificarea a fost efectuata cu succes, 0 altfel
    */
    int ind=cautare(repo,numar_apartament,suma,tip);
    if (ind==-1) {
        return 0;
    }
    strcpy(repo->lista[ind]->tip,new_tip);
    repo->lista[ind]->suma=new_suma;
    return 1;
}

void test_modificare() {
    RepoCheltuieli repo;
    repo.nr_cheltuieli = 0;
    repo.capacitate=3;
    repo.lista=(Cheltuiala**)malloc(repo.capacitate*sizeof(Cheltuiala*));
    int rez;
    char apa[15]="apa",incalzire[15]="incalzire",gaz[15]="gaz",curent[15]="curent",canal[15]="canal";
    repo.lista[0]=(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[0]) = (Cheltuiala){1, 100.5f, "apa"};
    repo.lista[1]=(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[1]) = (Cheltuiala){2, 200.0f, "gaz"};
    repo.lista[2]=(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[2]) = (Cheltuiala){3, 150.75f, "incalzire"};
    repo.nr_cheltuieli = 3;
    rez=modificare(&repo, 1, 100.5f, apa, 120.0f, canal);
    assert(rez==1);
    assert(repo.lista[0]->suma == 120.0);
    assert(strcmp(repo.lista[0]->tip, canal) == 0);
    rez=modificare(&repo, 4, 50.0f, curent, 60.0f, gaz);
    assert(repo.nr_cheltuieli == 3); // repo nu ar trebui să se schimbe
    assert(rez==0);
    rez=modificare(&repo, 2, 200.0f, gaz, 250.0f, gaz);
    assert(repo.lista[1]->suma == 250.0);
    assert(strcmp(repo.lista[1]->tip, gaz) == 0);
    assert(rez==1);
    rez=modificare(&repo, 3, 150.75f, incalzire, 150.75f, curent);
    assert(strcmp(repo.lista[2]->tip, "curent") == 0);
    assert(rez==1);
    printf("Toate testele pentru modificare au trecut cu succes!\n");
    for (int i = 0; i < repo.nr_cheltuieli; i++) {
        free(repo.lista[i]);
    }
    free(repo.lista);
}

int stergere(RepoCheltuieli* repo, int nr_ap,float suma, char tip[15]) {
    /*Sterge o cheltuiala din lista cheltuielilor
    param nr_ap: numarul apartamentului de tip int
    param suma: suma cheltuielii de tip float
    param tip: tipul cheltuielii (apa/incalzire/canal/gaz)
    return: 1 daca cheltuiala a fost stearsa cu succes, 0 altfel
    */
    int ind=cautare(repo,nr_ap,suma,tip);
    if (ind==-1) {
        return 0;
    }
    if (repo->nr_cheltuieli==1) {
        free(repo->lista[ind]);
        repo->nr_cheltuieli--;
        return 1;
    }
    free(repo->lista[ind]);
    repo->lista[ind]=repo->lista[repo->nr_cheltuieli-1];
    repo->nr_cheltuieli--;
    return 1;
}

void test_stergere() {
    RepoCheltuieli repo;
    repo.nr_cheltuieli = 0;
    repo.capacitate=3;
    repo.lista=(Cheltuiala**)malloc(repo.capacitate*sizeof(Cheltuiala));
    int rez;
    char apa[15]="apa",incalzire[15]="incalzire",gaz[15]="gaz",curent[15]="curent";
    repo.lista[0] = (Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[0])=(Cheltuiala){1, 100.5f, "apa"};
    repo.lista[1] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[1])=(Cheltuiala){2, 200.0f, "gaz"};
    repo.lista[2] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[2])=(Cheltuiala){3, 150.75f, "incalzire"};
    repo.nr_cheltuieli = 3;
    rez=stergere(&repo, 2, 200.0f, gaz);
    assert(repo.nr_cheltuieli == 2);
    assert(cautare(&repo, 2, 200.0, gaz) == -1);
    assert(rez==1);
    rez=stergere(&repo, 4, 50.0f, curent);
    assert(repo.nr_cheltuieli == 2); // Numărul de cheltuieli nu se schimbă
    assert(rez==0);
    rez=stergere(&repo, 1, 100.5f, apa);
    assert(repo.nr_cheltuieli == 1);
    assert(rez==1);
    rez=stergere(&repo, 3, 150.75f, incalzire);
    assert(repo.nr_cheltuieli == 0);
    assert(rez==1);
    rez=stergere(&repo, 1, 100.5f, apa);
    assert(repo.nr_cheltuieli == 0);
    assert(rez==0);
    printf("Toate testele pentru stergere au trecut cu succes!\n");
    free(repo.lista);
}

int filtrare_prop(RepoCheltuieli* repo, int prop, float equal, int rez[MAX_CHELTUIELI]) {
    /*Filtreaza cheltuielile dupa suma sau dupa suma, tip sau numar apartament
    param prop: proprietatea dupa care va fi filtrata lista cheltuielilor
                1 pentru suma
                2 pentru tip
                3 pentru numar apartament
    param equal: valoarea cu care trebuie sa fie egala proprietatea daca filtrarea se face dupa suma sau dupa numarul apartamentului
                daca filtrarea se face dupa tip, 1 pentru apa, 2 pentru canal, 3 pentru incalzire, 4 pentru gaz
    param rez[]: de tip int[] in care vor fi pozitiile din lista cheltuielilor ale cheltuielilor corespunzatoare filtrarii
    return: numarul elementelor vectorului rez
    */
    int k=-1;
    if (prop==1) {
        for (int i=0;i<repo->nr_cheltuieli;i++) {
            if (repo->lista[i]->suma==equal) {
                rez[++k]=i;
            }
        }
    }
    else if (prop==2) {
        char tip[15];
        if (equal==1) {
            strcpy(tip,"apa");
        }
        else if (equal==2) {
            strcpy(tip,"canal");
        }
        else if (equal==3) {
            strcpy(tip,"incalzire");
        }
        else if (equal==4) {
            strcpy(tip,"gaz");
        }
        for (int i=0;i<repo->nr_cheltuieli;i++) {
            if (strcmp(repo->lista[i]->tip,tip)==0) {
                rez[++k]=i;
            }
        }
    }
    else if (prop==3) {
        equal=(int)equal;
        for (int i=0;i<repo->nr_cheltuieli;i++) {
            if (repo->lista[i]->nr_ap==equal) {
                rez[++k]=i;
            }
        }
    }
    return k;
}

void test_filtrare_prop() {
    RepoCheltuieli repo;
    repo.nr_cheltuieli = 0;
    repo.capacitate=5;
    repo.lista=(Cheltuiala**)malloc(repo.capacitate*sizeof(Cheltuiala));
    int rez[MAX_CHELTUIELI];
    repo.lista[0] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[0])=(Cheltuiala){1, 100.5f, "apa"};
    repo.lista[1] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[1])=(Cheltuiala){2, 200.0f, "gaz"};
    repo.lista[2] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[2])=(Cheltuiala){3, 150.75f, "incalzire"};
    repo.lista[3] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[3])=(Cheltuiala){1, 100.5f, "canal"};
    repo.lista[4] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[4])=(Cheltuiala){1, 300.0f, "gaz"};
    repo.nr_cheltuieli = 5;
    int count = filtrare_prop(&repo, 1, 100.5f, rez);
    assert(count == 1);
    assert(rez[0] == 0);
    count = filtrare_prop(&repo, 1, 500.0f, rez);
    assert(count == -1);
    count = filtrare_prop(&repo, 2, 4, rez);
    assert(count == 1);
    assert(rez[0] == 1);
    count=filtrare_prop(&repo, 2, 1, rez);
    assert(count == 0);
    assert(rez[0] == 0);
    count=filtrare_prop(&repo,2,2,rez);
    assert(count==0);
    assert(rez[0]==3);
    count=filtrare_prop(&repo,2,3,rez);
    assert(count==0);
    assert(rez[0]==2);
    count = filtrare_prop(&repo, 3, 1, rez);
    assert(count == 2);
    assert(rez[0] == 0 && rez[1] == 3);
    count = filtrare_prop(&repo, 3, 10, rez);
    assert(count == -1);
    printf("Toate testele pentru filtrare au trecut cu succes!\n");
    for (int i = 0; i < repo.nr_cheltuieli; i++) {
        free(repo.lista[i]);
    }
    free(repo.lista);
}



int cmp_tip_cresc(void *c1, void *c2) {
    if (strcmp(((Cheltuiala*)c1)->tip, ((Cheltuiala*)c2)->tip)<0)
        return -1;
    else if (strcmp(((Cheltuiala*)c1)->tip, ((Cheltuiala*)c2)->tip)==0) {
        return 0;
    }
    else {
        return 1;
    }
}
int cmp_tip_desc(void *c1, void *c2) {
    if (strcmp(((Cheltuiala*)c1)->tip, ((Cheltuiala*)c2)->tip)<0)
        return 1;
    else if (strcmp(((Cheltuiala*)c1)->tip, ((Cheltuiala*)c2)->tip)==0) {
        return 0;
    }
    else {
        return -1;
    }
}
int cmp_suma_cresc(void *c1, void *c2) {
    if (((Cheltuiala*)c1)->suma<((Cheltuiala*)c2)->suma) {
        return -1;
    }
    else if ((((Cheltuiala*)c1)->suma)==(((Cheltuiala*)c2)->suma)) {
        return 0;
    }
    else {
        return 1;
    }
}
int cmp_suma_desc(void *c1, void *c2) {
    if (((Cheltuiala*)c1)->suma<((Cheltuiala*)c2)->suma) {
        return 1;
    }
    else if ((((Cheltuiala*)c1)->suma)==(((Cheltuiala*)c2)->suma)) {
        return 0;
    }
    else {
        return -1;
    }
}

void sortare(RepoCheltuieli* repo,int ord[MAX_CHELTUIELI],FunctieComparare functie) {
    int r;
    for (int i=0;i<repo->nr_cheltuieli;i++) {
        ord[i]=i;
    }
    for (int i=0;i<repo->nr_cheltuieli-1;i++) {
        for (int j=i+1;j<repo->nr_cheltuieli;j++) {
            if (functie(repo->lista[ord[j]],repo->lista[ord[i]])<=0) {
                r=ord[j];
                ord[j]=ord[i];
                ord[i]=r;
            }
        }
    }
}

void filtrare_sortata(RepoCheltuieli* repo,int tip,int cresc,int ord[MAX_CHELTUIELI]) {
    /*Sorteaza cheltuielile dupa suma sau dupa tip, crescator sau descrescator
    param tip: 1 daca sortarea se face dupa 2, 2 daca sortarea se face dupa tip
    param cresc: 1 daca sortarea se face in ordine crescatoare, 2 daca sortarea se face in ordine descrescatoare
    param ord[]: de tip int[] ce contine lista pozitiilor tuturor cheltuielilor ordonate corespunzator
    return: None
    */
    int r;
    for (int i=0;i<repo->nr_cheltuieli;i++) {
        ord[i]=i;
    }
    if (tip==1) {
        if (cresc==1) {
            for (int i=0;i<repo->nr_cheltuieli-1;i++) {
                for (int j=i+1;j<repo->nr_cheltuieli;j++) {
                    if (repo->lista[ord[j]]->suma<repo->lista[ord[i]]->suma) {
                        r=ord[i];
                        ord[i]=ord[j];
                        ord[j]=r;
                    }
                }
            }
        }
        else {
            for (int i=0;i<repo->nr_cheltuieli-1;i++) {
                for (int j=i+1;j<repo->nr_cheltuieli;j++) {
                    if (repo->lista[ord[j]]->suma>repo->lista[ord[i]]->suma) {
                        r=ord[i];
                        ord[i]=ord[j];
                        ord[j]=r;
                    }
                }
            }
        }
    }
    else {
        if (cresc==1) {
            for (int i=0;i<repo->nr_cheltuieli-1;i++) {
                for (int j=i+1;j<repo->nr_cheltuieli;j++) {
                    if (strcmp(repo->lista[ord[j]]->tip,repo->lista[ord[i]]->tip)<0) {
                        r=ord[i];
                        ord[i]=ord[j];
                        ord[j]=r;
                    }
                }
            }
        }
        else {
            for (int i=0;i<repo->nr_cheltuieli-1;i++) {
                for (int j=i+1;j<repo->nr_cheltuieli;j++) {
                    if (strcmp(repo->lista[ord[j]]->tip,repo->lista[ord[i]]->tip)>0) {
                        r=ord[i];
                        ord[i]=ord[j];
                        ord[j]=r;
                    }
                }
            }
        }
    }
}

void test_filtrare_sortata() {
    RepoCheltuieli repo;
    repo.nr_cheltuieli = 0;
    repo.capacitate=4;
    repo.lista=(Cheltuiala**)malloc(repo.capacitate*sizeof(Cheltuiala*));
    int ord[MAX_CHELTUIELI];
    repo.lista[0] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[0])=(Cheltuiala){1, 150.0, "gaz"};
    repo.lista[1] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[1])=(Cheltuiala){2, 100.5, "apa"};
    repo.lista[2] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[2])=(Cheltuiala){3, 200.75, "incalzire"};
    repo.lista[3] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[3])=(Cheltuiala){4, 75.3, "canal"};
    repo.nr_cheltuieli = 4;
    filtrare_sortata(&repo, 1, 1, ord);
    assert(ord[0] == 3);
    assert(ord[1] == 1);
    assert(ord[2] == 0);
    assert(ord[3] == 2);
    filtrare_sortata(&repo, 1, 2, ord);
    assert(ord[0] == 2);
    assert(ord[1] == 0);
    assert(ord[2] == 1);
    assert(ord[3] == 3);
    filtrare_sortata(&repo, 2, 1, ord);
    assert(ord[0] == 1);
    assert(ord[1] == 3);
    assert(ord[2] == 0);
    assert(ord[3] == 2);
    filtrare_sortata(&repo, 2, 2, ord);
    assert(ord[0] == 2);
    assert(ord[1] == 0);
    assert(ord[2] == 3);
    assert(ord[3] == 1);
    repo.nr_cheltuieli = 1;
    filtrare_sortata(&repo, 1, 1, ord);
    assert(ord[0] == 0);
    repo.nr_cheltuieli = 0;
    filtrare_sortata(&repo, 1, 1, ord);
    assert(ord[0] == 0);
    printf("Toate testele pentru sortare au trecut cu succes!\n");
    for (int i = 0; i < repo.nr_cheltuieli; i++) {
        free(repo.lista[i]);
    }
    free(repo.lista);
}

void test_sortare() {
    RepoCheltuieli repo;
    repo.nr_cheltuieli = 0;
    repo.capacitate=4;
    repo.lista=(Cheltuiala**)malloc(repo.capacitate*sizeof(Cheltuiala*));
    int ord[MAX_CHELTUIELI];
    repo.lista[0] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[0])=(Cheltuiala){1, 150.0f, "gaz"};
    repo.lista[1] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[1])=(Cheltuiala){2, 100.5f, "apa"};
    repo.lista[2] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[2])=(Cheltuiala){3, 200.75f, "incalzire"};
    repo.lista[3] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[3])=(Cheltuiala){4, 75.3f, "canal"};
    repo.nr_cheltuieli = 4;
    sortare(&repo, ord, cmp_suma_cresc);
    assert(ord[0] == 3);
    assert(ord[1] == 1);
    assert(ord[2] == 0);
    assert(ord[3] == 2);
    sortare(&repo, ord, cmp_suma_desc);
    assert(ord[0] == 2);
    assert(ord[1] == 0);
    assert(ord[2] == 1);
    assert(ord[3] == 3);
    sortare(&repo, ord, cmp_tip_cresc);
    assert(ord[0] == 1);
    assert(ord[1] == 3);
    assert(ord[2] == 0);
    assert(ord[3] == 2);
    sortare(&repo, ord, cmp_tip_desc);
    assert(ord[0] == 2);
    assert(ord[1] == 0);
    assert(ord[2] == 3);
    assert(ord[3] == 1);
    repo.nr_cheltuieli = 1;
    filtrare_sortata(&repo, 1, 1, ord);
    assert(ord[0] == 0);
    printf("Toate testele pentru sortare au trecut cu succes!\n");
    for (int i = 0; i < repo.nr_cheltuieli; i++) {
        free(repo.lista[i]);
    }
    free(repo.lista);
}

void test_cmp() {
    RepoCheltuieli repo;
    repo.nr_cheltuieli = 0;
    repo.capacitate=4;
    repo.lista=(Cheltuiala**)malloc(repo.capacitate*sizeof(Cheltuiala*));
    int ord[MAX_CHELTUIELI];
    repo.lista[0] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[0])=(Cheltuiala){1, 150.0f, "gaz"};
    repo.lista[1] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[1])=(Cheltuiala){2, 100.5f, "apa"};
    repo.lista[2] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[2])=(Cheltuiala){3, 200.75f, "incalzire"};
    repo.lista[3] =(Cheltuiala*)malloc(sizeof(Cheltuiala));
    *(repo.lista[3])=(Cheltuiala){4, 150.0f, "canal"};
    repo.nr_cheltuieli = 4;
    assert(cmp_suma_cresc(repo.lista[0],repo.lista[1])==1);
    assert(cmp_suma_cresc(repo.lista[0],repo.lista[3])==0);
    assert(cmp_suma_cresc(repo.lista[0],repo.lista[2])==-1);
    printf("BUN");
}
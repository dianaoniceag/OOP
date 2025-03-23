#include "UI.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

RepoCheltuieli* creeaza_repo() {
    RepoCheltuieli* repo = (RepoCheltuieli*)malloc(sizeof(RepoCheltuieli));
    if (!repo) {
        printf("Eroare la alocarea repo-ului!\n");
        exit(1);
    }
    repo->capacitate = 2;
    repo->nr_cheltuieli = 0;
    repo->lista = (Cheltuiala**)malloc(repo->capacitate * sizeof(Cheltuiala*));
    if (!repo->lista) {
        printf("Eroare la alocarea listei!\n");
        exit(1);
    }
    return repo;
}

void elibereaza_repo(RepoCheltuieli* repo) {
    for (int i = 0; i < repo->nr_cheltuieli; i++) {
        free(repo->lista[i]);
    }
    free(repo->lista);
    free(repo);
}

void adaugare_UI(RepoCheltuieli *repo) {
    /*Adauga o cheltuiala la lista cheltuielilor
    return: None
    */
    int nr_ap;
    float suma;
    char tip[15];
    printf("Introduceti numarul apartamentului: ");
    scanf("%d", &nr_ap);
    printf("Introduceti suma cheltuielii: ");
    scanf("%f", &suma);
    printf("Introduceti tipul cheltuielii (apa/canal/incalzire/gaz): ");
    scanf("%s", tip);
    if (strcmp(tip,"apa")!=0 && strcmp(tip,"canal")!=0 && strcmp(tip,"incalzire")!=0 && strcmp(tip,"gaz")!=0) {
        printf("Nu ati introdus un tip valid");
        return;
    }
    adaugare(repo,nr_ap,suma,tip);
    printf("Cheltuiala a fost adaugata cu succes");
}

void modificare_UI(RepoCheltuieli *repo) {
    /*Modifica suma si tipul unei cheltuieli
    return: None
    */
    int nr_ap,rez;
    float suma, new_suma;
    char tip[15], new_tip[15];
    printf("Introduceti numarul apartamentului: ");
    scanf("%d", &nr_ap);
    printf("Introduceti vechea suma a cheltuielii: ");
    scanf("%f", &suma);
    printf("Introduceti vechiul tip al cheltuielii: ");
    scanf("%s", tip);
    if (strcmp(tip,"apa")==0 && strcmp(tip,"canal")==0 && strcmp(tip,"incalzire")==0 && strcmp(tip,"gaz")==0) {
        printf("Nu ati introdus un tip valid");
        return;
    }
    printf("Introduceti noua suma a cheltuielii: ");
    scanf("%f", &new_suma);
    printf("Introduceti noul tip al cheltuielii: ");
    scanf("%s", new_tip);
    if (strcmp(new_tip,"apa")==0 && strcmp(new_tip,"canal")==0 && strcmp(new_tip,"incalzire")==0 && strcmp(new_tip,"gaz")==0) {
        printf("Nu ati introdus un tip valid");
        return;
    }
    rez=modificare(repo,nr_ap,suma,tip,new_suma,new_tip);
    if (rez==0) {
        printf("Nu exista aceasta cheltuiala");
    }
    else {
        printf("Cheltuiala a fost modificata cu succes");
    }
}

void stergere_UI(RepoCheltuieli *repo) {
    /*Sterge o cheltuiala din lista cheltuielilor
    return: None
    */
    int nr_ap,rez;
    float suma;
    char tip[15];
    printf("Introduceti numarul apartamentului: ");
    scanf("%d", &nr_ap);
    printf("Introduceti suma cheltuielii: ");
    scanf("%f", &suma);
    printf("Introduceti tipul cheltuielii: ");
    scanf("%s", tip);
    if (strcmp(tip,"apa")==0 && strcmp(tip,"canal")==0 && strcmp(tip,"incalzire")==0 && strcmp(tip,"gaz")==0) {
        printf("Nu ati introdus un tip valid");
        return;
    }
    rez=stergere(repo,nr_ap,suma,tip);
    if (rez==1) {
        printf("Cheltuiala a fost stearsa cu succes");
    }
    else {
        printf("Stergerea nu a fost efectuata");
    }
}

void afisare(RepoCheltuieli* repo) {
    /*Afiseaza lista cheltuielilor
    return: None
    */
    if (repo->nr_cheltuieli ==0) {
        printf("Nu exista cheltuieli inregistrate\n");
        return;
    }
    printf("\nLista cheltuielilor:\n");
    for (int i = 0; i < repo->nr_cheltuieli; i++) {
        printf("Apartament: %d, Suma: %.2f, Tip: %s\n",
               repo->lista[i]->nr_ap, repo->lista[i]->suma, repo->lista[i]->tip);
    }
}

void filtrare_prop_UI(RepoCheltuieli* repo) {
    /*Filtreaza cheltuielile dupa suma, tip sau numarul apartamentului
    return: None
    */
    int prop,rez[MAX_CHELTUIELI],k;
    char citire[15];
    float equal;
    printf("Introduceti proprietatea pentru filtrare (suma/tip/apartament): ");
    scanf("%s", citire);
    if (strcmp(citire,"suma")==0){
        prop=1;
        printf("Introduceti suma: ");
        scanf("%f", &equal);
        k=filtrare_prop(repo,prop,equal,rez);
    }
    else if (strcmp(citire,"tip")==0) {
        prop=2;
        printf("Introduceti tipul: ");
        scanf("%s", citire);
        if (strcmp(citire,"apa")==0) {
            equal=1;
        }
        else if (strcmp(citire,"canal")==0) {
            equal=2;
        }
        else if (strcmp(citire,"incalzire")==0) {
            equal=3;
        }
        else if (strcmp(citire,"gaz")==0) {
            equal=4;
        }
        k=filtrare_prop(repo,prop,equal,rez);
    }
    else if (strcmp(citire,"apartament")==0) {
        prop=3;
        printf("Introduceti apartamentul: ");
        scanf("%f", &equal);
        k=filtrare_prop(repo,prop,equal,rez);
    }
    else {
        printf("Nu ati introdus o proprietate valida");
    }
    if (k==-1) {
        printf("Nu exista cheltuieli cu aceasta proprietate");
    }
    else {
        for (int i=0;i<=k;i++) {
            printf("Apartament: %d, Suma: %.2f, Tip: %s\n",repo->lista[rez[i]]->nr_ap,repo->lista[rez[i]]->suma,repo->lista[rez[i]]->tip);
        }
    }
}

void filtrare_sortata_UI(RepoCheltuieli* repo) {
    /*Ordoneaza lista cheltuielilor dupa suma sau tip, in ordine crescatoare sau descrescatoare
    return: None
    */
    char citire[15];
    int tip,ord[MAX_CHELTUIELI];
    if (repo->nr_cheltuieli==0) {
        printf("Nu exista cheltuieli inregistrate\n");
        return;
    }
    printf("Introduceti criteriul de filtrare (suma/tip): ");
    scanf("%s",citire);
    if (strcmp(citire,"suma")==0) {
        tip=1;
    }
    else if (strcmp(citire,"tip")==0) {
        tip=2;
    }
    else {
        printf("Nu ati introdus un criteriu valid");
        return;
    }
    printf("Introduceti ordinea sortarii (crescator/descrescator): ");
    scanf("%s",citire);
    // if (strcmp(citire,"crescator")==0) {
    //     ord=1;
    // }
    // else if (strcmp(citire,"descrescator")==0) {
    //     ord=2;
    // }
    // else {
    //     printf("Nu ati introdus o ordine valida");
    //     return;
    // }
    //filtrare_sortata(repo,tip,ord,rez);
    if (tip==1) {
        if (strcmp(citire,"crescator")==0) {
            sortare(repo,ord,cmp_suma_cresc);
        }
        else if (strcmp(citire,"descrescator")==0){
            sortare(repo,ord,cmp_suma_desc);
        }
        else {
            printf("Nu ati introdus o ordine valida");
        }
    }
    else {
        if (strcmp(citire,"crescator")==0) {
            sortare(repo,ord,cmp_tip_cresc);
        }
        else if (strcmp(citire,"descrescator")==0){
            sortare(repo,ord,cmp_tip_desc);
        }
        else {
            printf("Nu ati introdus o ordine valida");
        }
    }
    for (int i=0;i<repo->nr_cheltuieli;i++) {
        printf("Apartament: %d, Suma: %.2f, Tip: %s\n",repo->lista[ord[i]]->nr_ap,repo->lista[ord[i]]->suma,repo->lista[ord[i]]->tip);
    }
}

void run_tests() {
    test_adaugare();
    test_cautare();
    test_modificare();
    test_stergere();
    test_filtrare_prop();
    test_filtrare_sortata();
    test_sortare();
    //test_cmp();
}

void run() {
    RepoCheltuieli* repo=creeaza_repo();
    int optiune;
    adaugare(repo,1,100,"apa");
    adaugare(repo,2,200,"gaz");
    adaugare(repo,3,120,"gaz");
    adaugare(repo,4,150,"gaz");
    do {
        printf("\nMeniu:\n");
        printf("1. Adauga cheltuiala\n");
        printf("2. Modifica chetuiala\n");
        printf("3. Sterge cheltuiala\n");
        printf("4. Vizualizeaza lista de cheltuieli filtrata dupa o proprietate (suma/tip/apartament)\n");
        printf("5. Vizualizeaza lista cheltuielilor ordonata dupa suma sau tip (crescator/descrescator)\n");
        printf("6. Afiseaza toate cheltuielile\n");
        printf("7. Iesire\n");
        printf("Introduceti optiunea: ");
        scanf("%d", &optiune);

        if (optiune == 1){
            adaugare_UI(repo);
        }
        else if (optiune==2) {
            modificare_UI(repo);
        }
        else if (optiune==3) {
            stergere_UI(repo);
        }
        else if (optiune==4) {
            filtrare_prop_UI(repo);
        }
        else if (optiune==5) {
            filtrare_sortata_UI(repo);
        }
        else if (optiune == 6) {
            afisare(repo);
        } 
        else if (optiune == 7) {
            printf("Iesire...\n");
            elibereaza_repo(repo);
        } 
        else {
            printf("Nu ati introdus o optiune valida\n");
        }
    } while (optiune != 7);
}
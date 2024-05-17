#include <stdio.h>
#include <string.h>

struct towar{
    char NazwaTowaru[30];
    int LiczbaSztuk;
    int Cena1Sztuki;
};

void wyzerujTabliceTowarow(struct towar* TablicaTowarow){
    for(int i = 0; i < 50; i++){
        strcpy(TablicaTowarow[i].NazwaTowaru, "");
        TablicaTowarow[i].LiczbaSztuk = 0;
        TablicaTowarow[i].Cena1Sztuki = 0;
    }
}

void wypiszTabliceTowarow(struct towar TablicaTowarow[]){
    printf("indeks\t\tNazwaTowaru\tLiczbaSztuk\tCena1Sztuki\n");

    for(int i = 0; i < 50; i++){
        if(strcmp(TablicaTowarow[i].NazwaTowaru, ""))
        {
            printf("%d\t\t%s\t\t%d\t\t%d\n", i, TablicaTowarow[i].NazwaTowaru, TablicaTowarow[i].LiczbaSztuk, TablicaTowarow[i].Cena1Sztuki);
        }
    }
    printf("\n");
}

void zmienTowar(struct towar* TablicaTowarow, int pozycja){
    strcpy(TablicaTowarow[pozycja].NazwaTowaru, "elo makrelo");
    TablicaTowarow[pozycja].LiczbaSztuk = 124;
    TablicaTowarow[pozycja].Cena1Sztuki = 6366;
}

int main()
{
    struct towar TablicaTowarow[50];

    char action = 'q';

    wyzerujTabliceTowarow(TablicaTowarow);

    while(1)
    {
        printf("----------------------------------------------------------------------\naction> ");
        scanf(" %c", &action);

        printf("chosen action: %c\n\n", action);

        if(action == 'q' || action == 'Q'){
            break;
        }

        if(action == 'w' || action == 'W'){
            wypiszTabliceTowarow(TablicaTowarow);
        }

        if(action == 'n' || action == 'N'){
            zmienTowar(TablicaTowarow, 1);
        }
    }

    return 0;
}
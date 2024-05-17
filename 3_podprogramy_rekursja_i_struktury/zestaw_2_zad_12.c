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
}

int main()
{
    struct towar TablicaTowarow[50];

    char action = 'q';

    wyzerujTabliceTowarow(TablicaTowarow);
    wypiszTabliceTowarow(TablicaTowarow);

    while(1)
    {
        printf("action> ");
        scanf(" %c", &action);

        printf("chosen action: %c\n\n", action);



        if(action == 'q' || action == 'Q'){
            break;
        }
    }

    return 0;
}
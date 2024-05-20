#include <stdio.h>
#include <string.h>

struct towar
{
    char NazwaTowaru[30];
    int LiczbaSztuk;
    double Cena1Sztuki;
};

void wyzerujTabliceTowarow(struct towar *TablicaTowarow)
{
    for (int i = 0; i < 50; i++)
    {
        strcpy(TablicaTowarow[i].NazwaTowaru, "");
        TablicaTowarow[i].LiczbaSztuk = 0;
        TablicaTowarow[i].Cena1Sztuki = 0.0;
    }
}

void wypiszTabliceTowarow(struct towar TablicaTowarow[])
{
    printf("indeks\t\tNazwaTowaru\tLiczbaSztuk\tCena1Sztuki\n");

    for (int i = 0; i < 50; i++)
    {
        if (strcmp(TablicaTowarow[i].NazwaTowaru, ""))
        {
            printf("%d\t\t%s\t\t%d\t\t%.2f\n", i, TablicaTowarow[i].NazwaTowaru, TablicaTowarow[i].LiczbaSztuk, TablicaTowarow[i].Cena1Sztuki);
        }
    }
    printf("\n");
}

void zmienTowar(struct towar *TablicaTowarow, int pozycja)
{
    char nazwa[30];
    printf("podaj nazwe: ");
    if (fgets(nazwa, 30, stdin) != NULL)
    {
        size_t len = strlen(nazwa);
        if (len > 0 && nazwa[len - 1] == '\n')
        {
            nazwa[len - 1] = '\0';
        }
    }

    strcpy(TablicaTowarow[pozycja].NazwaTowaru, nazwa);

    printf("podaj liczbe sztuk: ");
    int liczba;
    scanf(" %d", &liczba);
    // fflush(stdin);

    TablicaTowarow[pozycja].LiczbaSztuk = liczba;

    printf("podaj cene jednej sztuki: ");
    double cena;
    scanf(" %lf", &cena);
    // fflush(stdin);

    TablicaTowarow[pozycja].Cena1Sztuki = cena;
}

int sumaTowarow(struct towar *TablicaTowarow){
    
}

int main()
{
    struct towar TablicaTowarow[50];

    char action = 'q';

    wyzerujTabliceTowarow(TablicaTowarow);
    int indeks_pustego = 0;

    while (1)
    {
        printf("----------------------------------------------------------------------\naction> ");
        scanf(" %c", &action);
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        printf("chosen action: %c\n\n", action);

        if (action == 'q' || action == 'Q')
        {
            break;
        }

        if (action == 'w' || action == 'W')
        {
            wypiszTabliceTowarow(TablicaTowarow);
        }

        if (action == 'n' || action == 'N')
        {
            if (indeks_pustego < 30){
                zmienTowar(TablicaTowarow, indeks_pustego);
                indeks_pustego++;
            }
            else printf("Tablica towarów jest już pełna.\n");
        }

        if (action == 'r' || action == 'R')
        {
            // break;
        }
    }

    return 0;
}
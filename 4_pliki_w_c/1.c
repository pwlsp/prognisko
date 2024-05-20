#include <stdio.h>

int main()
{
    printf("podaj liczony znak: ");
    char znak, c;
    znak = getchar();
    int licznik = 0;

    printf("podany znak = \'%c\'\n", znak);

    FILE *plik;
    plik = fopen("plik.txt", "r");

    while (1)
    {
        c = getc(plik);

        if (c == EOF)
            break;

        // printf("z pliku: %c\n", znak);
        if (c == znak)
        {
            licznik++;
        }
    }

    printf("liczba wystapien = %d\n", licznik);

    fclose(plik);

    return 0;
}
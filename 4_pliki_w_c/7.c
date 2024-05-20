#include <stdio.h>

int main()
{
    int format = 1;
    printf("wybierz format wyjściowy (1-2): ");
    scanf("%d", &format);
    if (format != 1 && format != 2)
    {
        printf("Niepoprawny format. Wybieram format 1.");
        format = 1;
    }

    int ile_naglowkow[15];
    for (int i = 0; i < 15; i++)
    {
        ile_naglowkow[i] = 0;
    }

    FILE *plik;
    plik = fopen("plik.txt", "r");

    char linia[200];

    while (fgets(linia, 200, plik))
    {
        int i = 0;
        while (linia[i] == '*')
        {
            i++;
        }
        i++;
        while(i<200){
            printf("%c", linia[i]);
            i++;
        }
    }

    fclose(plik);

    return 0;
}
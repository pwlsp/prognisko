#include <stdio.h>
#include <stdlib.h>

double srednia(double pomiary[4])
{
    double suma = 0;
    for (int i = 0; i < 4; i++)
    {
        suma += pomiary[i];
    }
    return suma / 4;
}
double najwieksza(double pomiary[4])
{
    double maxi = pomiary[0];
    for (int i = 0; i < 4; i++)
    {
        if (pomiary[i] > maxi)
            maxi = pomiary[i];
    }
    return maxi;
}
double najmniejsza(double pomiary[4])
{
    double mini = pomiary[0];
    for (int i = 0; i < 4; i++)
    {
        if (pomiary[i] < mini)
            mini = pomiary[i];
    }
    return mini;
}
int main()
{
    FILE *wej, *wyj;
    wej = fopen("dane.txt", "r");
    wyj = fopen("wyjscie.txt", "w");
    int nazwa_serii, kod;
    double t[4];
    double (*funkcje[3])(double t[4]) = {srednia, najwieksza, najmniejsza};

    if (wej == NULL || wyj == NULL)
    {
        printf("blad");
        exit(1);
    }

    while (!feof(wej))
    {
        fscanf(wej, "%d", &nazwa_serii);
        for (int i = 0; i < 4; i++)
        {
            fscanf(wej, "%lf", &t[i]);
        }
        fscanf(wej, "%d", &kod);

        fprintf(wyj, "%d ", nazwa_serii);
        fprintf(wyj, "%.15g ", funkcje[kod](t));
        fprintf(wyj, "%d\n", kod);
    }
    printf("Wyniki w pliku wyjscie.txt\n");

    fclose(wej);
    fclose(wyj);
}
#include <stdio.h>

int main()
{
    int n = 2;
    int m = 1;
    double iloczyn = 1.0;
    double suma = 0.0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            iloczyn = iloczyn * ((i*i) + (j*j) - 1) / (2*i + 3*j + 4);
        }
        suma = suma + iloczyn;
        iloczyn = 1.0;
    }

    printf("%lf", suma);

    return 0;
}
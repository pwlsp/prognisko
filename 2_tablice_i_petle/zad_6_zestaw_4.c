#include <stdio.h>

int suma_dzielnikow(int n)
{
    int suma = 0;

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            suma = suma + i;
        }
    }

    return suma;
}

int main()
{
    int a = 4000;

    for (int i = 1; i <= a; i++)
    {
        int aisa = suma_dzielnikow(i);
        if(aisa > i && aisa < a && suma_dzielnikow(aisa) == i){
            printf("%d and %d\n", i, suma_dzielnikow(i));
        }
    }

    // printf("%d", suma_dzielnikow(10));

    return 0;
}
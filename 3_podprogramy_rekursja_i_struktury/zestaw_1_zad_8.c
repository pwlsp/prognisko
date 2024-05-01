#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, len, dzielnik, potega, koncowka;

    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    printf("\na = %d\nb = %d\n", a, b);

    for (int i = a; i <= b; i++)
    {
        len = (i < 1) ? 1 : log10(i) + 1;
        // printf("%d\n", len);
        potega = pow(i, 2);
        dzielnik = pow(10, len);
        koncowka = potega % dzielnik;
        if (i == koncowka)
        {
            printf("%d\n",i);
        }
    }

    return 0;
}
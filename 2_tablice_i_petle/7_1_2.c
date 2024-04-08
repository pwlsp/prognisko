#include <stdio.h>

int main()
{
    int n = 10;
    for (int i = 1; i <= n; i++)
    {
        if(i != 1){
            printf("\n");
        }
        for (int j = 1; j <= i; j++){
            
            printf("O");
        }
    }

    return 0;
}
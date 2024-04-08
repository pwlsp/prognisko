#include <stdio.h>

int main()
{
    int n = 10;
    for (int i = 1; i <= n; i++)
    {
        if(i != 1){
            printf("\n");
        }
        for(int l = 1; l <= n-i+1; l++){
            printf(" ");
        }
        for(int s = 1; s <= 2*i-1; s++){
            printf("X");
        }
    }   

    return 0;
}
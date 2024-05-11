#include <stdio.h>
#include <math.h>

int decimal_digits_sum(int number, int current_sum){
    if(number < 0){
        number = number * -1;
    }
    if(number / 10 >= 1){
        current_sum += number % 10;
        number = number / 10;

        return decimal_digits_sum(number, current_sum);
    }
    else{
        return (current_sum + number);
    }
    return 0;
}

int main()
{
    int number;
    printf("Program - Sum of the decimal digits a number.\n\nnumber: ");
    scanf("%d", &number);
    printf("\nresult = %d\n", decimal_digits_sum(number, 0));

    return 0;
}
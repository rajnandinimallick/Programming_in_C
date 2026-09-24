// This program take two numbers from user and tests if first number can be evenly divisible by the second number
#include <stdio.h>

int main(void)
{
    int number1, number2;
    printf("Enter 1st number: ");
    scanf("%i", &number1);
    printf("Enter 2nd number: ");
    scanf("%i", &number2);
    if (number1 % number2 == 0)
    {
        printf("1st number is evenly divisible by 2nd number.");
    }
    else
    {
        printf("1st number is NOT evenly divisible by 2nd number.");
    }

    return 0;
}
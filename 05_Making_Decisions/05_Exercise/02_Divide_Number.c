// Take two integer value from user and print 3 decimal value after dividing 1st number by the second number
#include <stdio.h>

int main(void)
{
    int number1, number2;
    printf("Enter 1st number: ");
    scanf("%i", &number1);
    printf("Enter 2nd number: ");
    scanf("%i", &number2);
    if (number2 == 0)
    {
        printf("Cannot divide by zero(0)!");
    }
    else
    {
        printf("%.3f", ((float)number1 / (float)number2));
    }

    return 0;
}
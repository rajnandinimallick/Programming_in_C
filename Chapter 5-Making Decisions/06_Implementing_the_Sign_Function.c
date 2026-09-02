#include <stdio.h>
int main(void)
{
    int number, sign;
    printf("Please type in your number.\n");
    scanf("%i", &number);
    if (number > 0)
        sign = 1;
    else if (number < 0)
        sign = -1;
    else
        sign = 0;

    printf("The sign of the number is: %i\n", sign);

    return 0;
}
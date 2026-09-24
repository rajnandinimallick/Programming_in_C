#include <stdio.h>

int main(void)
{
    int number;
    printf("Enter your number: ");
    scanf("%i", &number);

    if (number < 0)
    {
        number = -number;
    }

    if (number == 0)
    {
        printf("0 = 0\n");
        return 0;
    }

    int temp = number;
    int reversed = 0;
    int digit_count = 0;

    while (temp > 0)
    {
        reversed = (reversed * 10) + (temp % 10);
        temp /= 10;
        digit_count++;
    }

    int sum = 0;
    while (digit_count > 0)
    {
        int digit = reversed % 10;
        sum += digit;

        printf("%i", digit);

        if (digit_count > 1)
        {
            printf(" + ");
        }

        reversed /= 10;
        digit_count--;
    }

    printf(" = %i\n", sum);

    return 0;
}

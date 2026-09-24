// In the example of 08, if we put a negative number eg. -87, it will output -7-8, so
#include <stdio.h>

int main(void)
{
    int n;
    int reversed_num;

    printf("Enter your number: ");
    scanf("%d", &n);
    if (n == 0)
    {
        n = 0;
    }
    else if (n < 0)
    {
        n = -n;
        while (n != 0)
        {
            int reversed_num;
            reversed_num = n % 10;
            printf("%i", reversed_num);
            n /= 10;
        }
        printf("-");
    }
    else if (n > 0)
    {
        while (n != 0)
        {
            int reversed_num;
            reversed_num = n % 10;
            printf("%i", reversed_num);
            n /= 10;
        }
    }

    printf("\n");

    return 0;
}
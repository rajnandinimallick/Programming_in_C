/*
🧩 Skip Multiples of 3 Topics : Continue, Loop
Problem : Print numbers from 1 to 20,
but skip multiples of 3
Hint : -if (i % 3 == 0) continue;
*/
#include <stdio.h>

int main(void)
{
    int number_1;
    int number_2;
    int status_1;
    int status_2;
    printf("We will skip the numbers that are multiplication of 3\n");

    while (1)
    {
        printf("Enter the starting number: ");
        status_1 = scanf("%d", &number_1);
        if (status_1 != 1)
        {
            printf("Invalid input, try with a valid number!\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            continue;
        }

        while (1)
        {
            printf("Enter the ending number: ");
            status_2 = scanf("%d", &number_2);

            if (status_2 != 1 || number_2 < number_1)
            {
                printf("Invalid input, try with a valid number that is greater than starting number!\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
                continue;
            }
            else
            {
                break;
            }
        }
        break;
    }
    for (int i = number_1; i <= number_2; i++)
    {
        if (i % 3 == 0)
        {
            continue;
        }
        else
        {
            printf("%d\t", i);
        }
    }
    return 0;
}
/*
🧩 Fibonacci Generator
Topics: Loop
Problem:
Print first N Fibonacci numbers
Hint:
- track previous two values
*/
#include <stdio.h>

int main(void)
{
    int how_many;
    int status_of_how_many;
    int first_digit = 0;
    int second_digit = 1;
    int next_digit;
    while (1)
    {
        printf("How many fibonacci numbers do you want: ");
        status_of_how_many = scanf("%d", &how_many);
        if (status_of_how_many != 1 || how_many <= 0)
        {
            printf("Please enter a valid positive integer.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
        else
        {
            break;
        }
    }
    printf("Fibonacci series: ");

    for (int i = 0; i < how_many; i++)
    {
        if (i <= 1)
        {
            next_digit = i;
        }
        else
        {
            next_digit = first_digit + second_digit;
            first_digit = second_digit;
            second_digit = next_digit;
        }
        printf("%d\t", next_digit);
    }
    printf("\n");
    return 0;
}
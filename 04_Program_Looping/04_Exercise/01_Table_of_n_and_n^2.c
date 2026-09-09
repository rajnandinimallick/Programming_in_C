// Write a program to generate and display a table of n and n^1, for integer values of n ranging from 1 to 10. Be certain to print appropriate column headings.
#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter an integer number for your table: \n");
    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("\nGenerated your table\n");
    printf("-------------------------\n");
    printf("%5s    %10s\n", "n", "n^2");
    printf("%5s    %10s\n", "-----", "----------");

    for (int i = 1; i <= n; i++)
    {
        printf("%5d    %10lld\n", i, (long long)i * i);
    }

    return 0;
}

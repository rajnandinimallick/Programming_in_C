// Program for first 10 factorials (n!)
#include <stdio.h>

int main(void)
{
    int n = 10;
    unsigned long long factorial = 1;

    printf("  n       n!\n");
    printf("----- ---------\n");

    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
        printf(" %2d= %8llu\n", i, factorial);
    }

    return 0;
}

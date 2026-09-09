#include <stdio.h>
int main(void)
{
    int Fibonacci[15], i;
    Fibonacci[0] = 0; // by definition
    Fibonacci[1] = 1; // by ditto
    for (i = 2; i < 15; ++i)
        Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2];
    printf("The first 15 Fibonacci numbers are:\n");
    for (i = 0; i < 15; ++i)
        printf("%i\n", Fibonacci[i]);

    return 0;
}
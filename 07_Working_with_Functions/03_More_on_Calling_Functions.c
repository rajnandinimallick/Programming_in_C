#include <stdio.h>

void printMessage(void)
{
    printf("Programming is Fun\n");
}
int main(void)
{
    int i;
    for (i = 1; i <= 5; ++i)
        printMessage();

    return 0;
}
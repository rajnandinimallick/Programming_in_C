/*
🧩 Reverse an Array
Topics : Arrays
Problem : Input 5 numbers → print them in reverse order
Hint : -Loop from end to start
*/

#include <stdio.h>

int main(void)
{
    int numbers[5] = {1, 2, 3, 4, 5};
    printf("number[5] = {");
    for (int i = 4; i >= 0; i--)
    {
        printf("%d, ", numbers[i]);
    }
    printf("\b\b");
    printf("}");

    return 0;
}
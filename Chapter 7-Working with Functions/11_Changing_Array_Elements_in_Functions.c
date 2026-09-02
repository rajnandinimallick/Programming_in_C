#include <stdio.h>

void multiplyBy2(float array[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        array[i] *= 2;
}

int main(void)
{
    float floatVals[4] = {1.2f, -3.78f, 0.5f, 9.6f};
    int i;
    void multiplyBy2(float array[], int n);
    multiplyBy2(floatVals, 4);
    for (i = 0; i < 4; ++i)
        printf("%.2f    ", floatVals[i]);
    printf("\n");

    return 0;
}
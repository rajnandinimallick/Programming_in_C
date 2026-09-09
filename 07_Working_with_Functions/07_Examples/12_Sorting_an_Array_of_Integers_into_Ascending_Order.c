#include <stdio.h>

void sort(int values[], int numberOfElements)
{
    int i, j, temp;
    for (i = 0; i < numberOfElements - 1; ++i)
        for (j = i + 1; j < numberOfElements; ++j)
            if (values[i] > values[j])
            {
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
}

int main(void)
{
    int i;
    int array[16] = {5, 3, -8, 1, 9, -12, 7, 5, 19, 3, 8, 2, 4, 6, 10, 11};
    void sort(int values[], int numberOfElements);
    printf("The original array is:\n");
    for (i = 0; i < 16; ++i)
        printf("%i    ", array[i]);
    printf("\n");
    sort(array, 16);
    printf("The sorted array is:\n");
    for (i = 0; i < 16; ++i)
        printf("%i    ", array[i]);
    printf("\n");
    return 0;
}
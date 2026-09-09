#include <stdio.h>

int minimum(int values[], int numberOfElements)
{
    int minValue, i;
    minValue = values[0];
    for (i = 1; i < numberOfElements; ++i)
        if (values[i] < minValue)
            minValue = values[i];
    return minValue;
}

int main(void)
{
    int array1[5] = {5, 3, 8, 1, 9};
    int array2[7] = {12, 7, 5, 19, 3, 8, 2};
    int minimum(int values[], int numberOfElements);
    printf("array1's minimum value is %i\n", minimum(array1, 5));
    printf("array2's minimum value is %i\n", minimum(array2, 7));

    return 0;
}
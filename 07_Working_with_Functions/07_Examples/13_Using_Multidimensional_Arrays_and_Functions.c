#include <stdio.h>

void scalarMultiply(int matrix[3][5], int scalar);
void displayMatrix(int matrix[3][5]);

int main(void)
{
    int sampleMatrix[3][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};

    printf("The original matrix is:\n");
    displayMatrix(sampleMatrix);

    scalarMultiply(sampleMatrix, 2);
    printf("\nThe matrix after multiplied by 2:\n");
    displayMatrix(sampleMatrix);

    scalarMultiply(sampleMatrix, -1);
    printf("\nThe matrix after multiplied by -1:\n");
    displayMatrix(sampleMatrix);

    return 0;
}

void scalarMultiply(int matrix[3][5], int scalar)
{
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 5; column++)
        {
            matrix[row][column] *= scalar;
        }
    }
}

void displayMatrix(int matrix[3][5])
{
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 5; column++)
        {
            printf("%5i", matrix[row][column]);
        }
        printf("\n");
    }
}

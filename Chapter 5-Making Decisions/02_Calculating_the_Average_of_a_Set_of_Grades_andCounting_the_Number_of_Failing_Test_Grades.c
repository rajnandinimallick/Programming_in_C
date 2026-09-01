#include <stdio.h>
int main(void)
{
    int numberofGrades, i, grade;
    int gradeTotal = 0;
    int failureCount = 0;
    float average;
    printf("How many grade will you be entering? ");
    scanf("%i", &numberofGrades);
    for (i = 1; i <= numberofGrades; ++i)
    {
        printf("Enter grade #%i: ", i);
        scanf("%i", &grade);
        gradeTotal += grade;
        if (grade < 65)
            ++failureCount;
    }
    average = (float)gradeTotal / numberofGrades;
    printf("\nGrade average = %.2f\n", average);
    printf("Number of failures = %i\n", failureCount);

    return 0;
}
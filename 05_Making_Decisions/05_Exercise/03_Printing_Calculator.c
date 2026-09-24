#include <stdio.h>

int main(void)
{
    char operator;
    float number;
    float accumulator = 0.0f;

    printf("Type in the operation you want to run from below\n");
    printf("-------------------------------------------------\n");
    printf("summation->            +\n");
    printf("substract->            -\n");
    printf("multiplication->       *\n");
    printf("division->             /\n");
    printf("accumulator (Set)->    S\n");
    printf("end of calculation->   E\n\n");

    while (1)
    {
        printf("Which operator: ");
        scanf(" %c", &operator);

        if (operator == 'E' || operator == 'e')
        {
            printf("Final Value in Accumulator = %.6f\n", accumulator);
            printf("End of Calculations.\n");
            break;
        }

        if (operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == 'S' || operator == 's')
        {
            printf("Enter number: ");
            scanf("%f", &number);
        }
        else
        {
            printf("Unknown operator. Please try again.\n");
            continue;
        }

        switch (operator)
        {
        case 'S':
        case 's':
            accumulator = number;
            break;
        case '+':
            accumulator += number;
            break;
        case '-':
            accumulator -= number;
            break;
        case '*':
            accumulator *= number;
            break;
        case '/':
            if (number == 0)
            {
                printf("Error: Division by zero is not allowed.\n");
            }
            else
            {
                accumulator /= number;
            }
            break;
        }

        printf("Contents of Accumulator = %.6f\n\n", accumulator);
    }

    return 0;
}

#include <stdio.h>
int main(void)
{
    float value1, value2;
    char operator;
    printf("Enter your expression (example: 2.5 + 3.1): ");
    scanf("%f %c %f", &value1, &operator, &value2);
    switch (operator)
    {
    case '+':
        printf("%.2f %c %.2f = %.2f\n", value1, operator, value2, value1 + value2);
        break;
    case '-':
        printf("%.2f %c %.2f = %.2f\n", value1, operator, value2, value1 - value2);
        break;
    case '*':
        printf("%.2f %c %.2f = %.2f\n", value1, operator, value2, value1 * value2);
        break;
    case '/':
        if (value2 != 0)
            printf("%.2f %c %.2f = %.2f\n", value1, operator, value2, value1 / value2);
        else
            printf("Error: Division by zero is not allowed.\n");
        break;
    default:
        printf("Unknown operator.\n");
    }
    return 0;
}
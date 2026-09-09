#include <stdio.h>
int main(void)
{
    float value1, value2;
    char operator;
    printf("Enter your expression (example: 2.5 + 3.1): ");
    scanf("%f %c %f", &value1, &operator, &value2);
    if (operator == '+')
        printf("%.2f %c %.2f = %.2f\n", value1, operator, value2, value1 + value2);
    else if (operator == '-')
        printf("%.2f %c %.2f = %.2f\n", value1, operator, value2, value1 - value2);
    else if (operator == '*')
        printf("%.2f %c %.2f = %.2f\n", value1, operator, value2, value1 * value2);
    else if (operator == '/')
        if (value2 != 0)
            printf("%.2f %c %.2f = %.2f\n", value1, operator, value2, value1 / value2);
        else
            printf("Error: Division by zero is not allowed.\n");
    else
        printf("Unknown operator.\n");

    return 0;
}
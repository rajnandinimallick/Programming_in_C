#include <stdio.h>
int main(void)
{
    float value1, value2;
    char operator;
    printf("Type in your expression (e.g., 5.0 + 3.0): \n");
    scanf("%f %c %f", &value1, &operator, &value2);
    if (operator == '+')
        printf("%.2f %c %.2f = %.2f\n", value1, operator, value2, value1 + value2);
    else if (operator == '-')
        printf("%.2f %c %.2f = %.2f\n", value1, operator, value2, value1 - value2);
    else if (operator == '*')
        printf("%.2f %c %.2f = %.2f\n", value1, operator, value2, value1 * value2);
    else if (operator == '/')
        printf("%.2f %c %.2f = %.2f\n", value1, operator, value2, value1 / value2);
    else
        printf("Unknown operator.\n");

    return 0;
}
#include <stdio.h>

int main(void)
{

    float f1 = 123.125, f2;
    int i1, i2 = -150;
    char c = 'a';
    i1 = f1;
    printf("%f assigned to an int produces %i\n", f1, i1);
    f1 = i1;
    printf("%i assigned to an int produces %f\n", i2, f1);
    f1 = i2 / 100;
    printf("%i assigned to an int produces %f\n", i2, f1);
    f2 = i2 / 100.0;
    printf("%i assigned to an int produces %f\n", i2, f2);
    i2 = (float) 12 / 100;
    printf("(float) %i assigned to an int produces %f\n", i2, f2);

    return 0;
}
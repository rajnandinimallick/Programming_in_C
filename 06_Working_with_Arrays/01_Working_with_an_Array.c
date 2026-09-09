#include <stdio.h>
int main(void)
{
    int value[10];
    int index;
    value[0] = 197;
    value[1] = 42;
    value[2] = -350;
    value[3] = value[0] + value[1];
    value[9] = value[5] / 10;
    --value[2];
    for (index = 0; index < 10; ++index)
        printf("value[%i] = %i\n", index, value[index]);
    return 0;
}
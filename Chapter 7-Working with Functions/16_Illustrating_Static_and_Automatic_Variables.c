#include <stdio.h>

void auto_static(void)
{
    int autoVariable = 1;          // Automatic variable
    static int staticVariable = 1; // Static variable

    printf("Automatic variable: %d\n", autoVariable);
    printf("Static variable: %d\n", staticVariable);

    autoVariable++;
    staticVariable++;
}

int main(void)
{
    int i;
    void auto_static(void);
    for (i = 0; i < 5; ++i)
        auto_static();
    return 0;
}
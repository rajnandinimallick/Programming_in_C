#include <stdio.h>

int main(){
    //3x^3 - 5x^2 +6, for x = 2.55
    float x = 2.55;
    printf("Answer is: %.2f\n", (3 * x * x * x) - (5 * x * x) + 6);

    printf("Another answer is: %.3e", ((3.31e-8) * (2.01e-7)) / ((7.16e-6) + 2.01e-8));

    return 0;
}
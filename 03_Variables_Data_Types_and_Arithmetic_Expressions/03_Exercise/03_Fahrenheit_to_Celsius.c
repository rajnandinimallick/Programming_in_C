#include <stdio.h>

int main(){
    int f = 27;
    float c;
    c = (f - 32) / 1.8;
    // c = (f - 32) * (5.0 / 9.0) 
    //this also works, but be careful with the floating point as the expected value is mostly floating value
    printf("27 Fahrenheit to Celsius = %.3f Degree\n", c);

    printf("If we want to take a value from the user, the code is done below:\n\n");
    float fahr, cels;
    printf("Enter the Fahrenheit value: ");
    scanf("%f", &fahr);
    cels = (fahr - 32) * (5.0 / 9.0);

    printf("%.2f Fahrenheit = %.2f Celsius\n", fahr, cels);
    return 0;
}
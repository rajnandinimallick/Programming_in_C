/*
🧩 Count Vowels in a String
Topics : Strings,
Loops
Problem : Input a string → count vowels
Hint : -check : a, e, i, o, u
- use strlen()(optional)
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) 
{
    char line[100];
    int vowels = 0;
    printf("Enter your line: ");
    fgets(line, sizeof(line), stdin);

    for (int i = 0; line[i] != '\0'; i++)
    {
        char islower = tolower(line[i]);
        if (islower == 'a' || islower == 'e' || islower == 'i' || islower == 'o' || islower == 'u')
        {
            vowels++;
        }
    }
    printf("Total vowels in your line is: %d", vowels);
    return 0;
}
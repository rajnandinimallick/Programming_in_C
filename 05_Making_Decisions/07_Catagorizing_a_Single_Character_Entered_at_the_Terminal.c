#include <stdio.h>
int main(void)
{
    char c;
    printf("Please type in a single character and press Enter: ");
    scanf("%c", &c);
    if (c >= '0' && c <= '9')
        printf("You typed in a digit.\n");
    else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        printf("You typed in a letter.\n");
    else
        printf("You typed in a special character.\n");

    return 0;
}
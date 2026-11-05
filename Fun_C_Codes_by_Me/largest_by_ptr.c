/*
🧩 Find Largest Using Pointer
Topics: Pointers, If
Problem:
find largest using pointers
Hint:
- compare dereferenced values
*/
#include <stdio.h>

int main(void)
{
    int how_many;
    int status_of_how_many;
    printf("How many numbers you wanna give: ");
    status_of_how_many = scanf("%d", &how_many);
    if (how_many > 0 && status_of_how_many == 1)
    {
        int numbers[how_many];
        int status_of_number;
        printf("Enter your numbers:\n");

        for (int i = 0; i < how_many; i++)
        {
            status_of_number = scanf("%d", &numbers[i]);
            if (status_of_number != 1)
            {
                printf("Invalid! Not a number\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
                i--;
            }
        }
        int *ptr_to_number = numbers;
        int max_number = *ptr_to_number;
        for (int j = 0; j < how_many; j++)
        {
            if (*ptr_to_number > max_number)
            {
                max_number = *ptr_to_number;
            }
            ptr_to_number++;
        }
        printf("The maximum number from your input is: %d\n", max_number);
    }
    else
    {
        return 1;
    }
    return 0;
}
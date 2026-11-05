/*
🧩 Guess the Number(loop fun 🎯)
Topics : While Loop,If - Else
Problem : Hardcode a number(like 7).User keeps guessing until correct.
Output : -Too high
- Too low
- Correct!
Hint : -while (1) loop-break when correct
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    int games_played = 0;
    int games_won = 0;
    int games_lost = 0;

    printf("=== Welcome to the Number Guessing Game! ===\n\n");
    while (1)
    {
        int range_number = rand() % 101;
        printf("I have choosen a number from 0 to 100. You have 7 chances.\nCan you guess it?!\n");
        int number = -1;
        int status;
        int i = 1;
        int won_this_game = 0;

        while (i < 8)
        {
            printf("Chance %d/7\nYour guess: ", i);
            status = scanf("%d", &number);

            if (status == 1)
            {

                if (number < 0 || number > 100)
                {
                    printf("Cautious! Number is between 0-100\n (This did not cost a chance)\n\n");
                    continue;
                }
                if (number < range_number)
                {
                    printf("Too low, guess again!\n");
                    i++;
                }
                else if (number > range_number)
                {
                    printf("Too high, guess again!\n");
                    i++;
                }
                else
                {
                    printf("Correct!!!");
                    won_this_game = 1;
                    break;
                }
            }
            else
            {
                printf("Invalid input. That was not a number.\n\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
            }
        }
        games_played++;
        if (won_this_game)
        {
            games_won++;
        }
        else
        {
            printf("Alas! The number was %d. Game Over :( \n\n", range_number);
            games_lost++;
        }

        int choice;
        int choice_status;
        while (1)
        {
            printf("Do you want to play again?\nEnter 1 if YES\nEnter 0 if NO\n->");
            choice_status = scanf("%d", &choice);
            if (choice_status == 1)
            {
                if (choice == 1 || choice == 0)
                {
                    break;
                }
                else
                {
                    printf("Invalid option. Please enter exactly 1 or 0.\n\n");
                }
            }
            else
            {
                printf("Invalid input. Please enter a valid number (1 or 0).\n\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
            }
        }

        printf("\n-----------------------------------------\n");
        if (choice == 0)
        {
            break;
        }

        printf("Starting a new round...\n\n");
    }
    printf("\n=== FINAL SCORE SUMMARY ===\n");
    printf("Total Games Played: %d\n", games_played);
    printf("Games Won:          %d\n", games_won);
    printf("Games Lost:         %d\n", games_lost);
    printf("Thanks for playing! Tataaa!\n");

    return 0;
}
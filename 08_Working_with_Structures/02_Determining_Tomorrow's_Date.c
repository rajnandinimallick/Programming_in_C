#include <stdio.h>

int main(void)
{
    struct date
    {
        int month;
        int day;
        int year;
    };
    struct date today, tomorrow;
    const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 21, 30, 31};
    printf("Enter today;s date (mm/dd/yyyy): ");
    scanf("%i%i%i", &today.month, &today.day, today.year);

    return 0;
}
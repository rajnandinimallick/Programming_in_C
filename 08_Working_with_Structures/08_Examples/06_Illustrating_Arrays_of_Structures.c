#include <stdio.h>

struct time
{
    int hour;
    int minute;
    int second;
};

int main(void)
{
    struct time timeUpdate(struct time now);
    struct time testTimes[5] = {{11, 59, 59}, {12, 0, 0}, {23, 59, 59}, {0, 0, 0}, {13, 30, 45}};
    int i;
    for (i = 0; i < 5; ++i)
    {
        printf("Time is %.2i:%.2i:%.2i\n", testTimes[i].hour, testTimes[i].minute, testTimes[i].second);
        testTimes[i] = timeUpdate(testTimes[i]);
        printf("...one second later it's %.2i:%.2i:%.2i\n\n", testTimes[i].hour, testTimes[i].minute, testTimes[i].second);
    }

    return 0;
}

struct time timeUpdate(struct time now)
{
    ++now.second;
    if (now.second == 60) // next minute
    {
        now.second = 0;
        ++now.minute;
        if (now.minute == 60) // next hour
        {
            now.minute = 0;
            ++now.hour;
            if (now.hour == 24) // next day
                now.hour = 0;
        }
    }
    return now;
}
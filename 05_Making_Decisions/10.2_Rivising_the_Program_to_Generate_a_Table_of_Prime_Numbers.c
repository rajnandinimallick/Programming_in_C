#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    int p, d;
    bool is_prime;
    for (p = 2; p <= 50; ++p)
    {
        is_prime = true;
        for (d = 2; d < p; ++d)
            if (p % d == 0)
                is_prime = false;
        if (is_prime != false)
            printf("%i ", p);
    }
    printf("\n");

    return 0;
}
#include <stdio.h>

int main(void)
{
    int p, d;
    _Bool is_prime;

    for (p = 2; p <= 50; ++p)
    {
        is_prime = 1;

        for (d = 2; d < p; ++d)
        {
            if (p % d == 0)
            {
                is_prime = 0;
                break;
            }
        }

        if (is_prime != 0)
            printf("%i\n", p);
    }
    printf("\n");
    return 0;
}

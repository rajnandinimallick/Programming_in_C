#include <stdio.h>

int main()
{
    int i, j, next_multiple;

    // First set
    i = 256;
    j = 7;
    next_multiple = i + j - (i % j);

    printf("Initial value (i): %d\n", i);
    printf("Divisor (j): %d\n", j);
    printf("Next largest multiple: %d\n\n", next_multiple);

    // Second set
    i = 12258;
    j = 23;
    next_multiple = i + j - (i % j);

    printf("Initial value (i): %d\n", i);
    printf("Divisor (j): %d\n", j);
    printf("Next largest multiple: %d\n\n", next_multiple);

    // Third set
    i = 996;
    j = 4;
    next_multiple = i + j - (i % j);

    printf("Initial value (i): %d\n", i);
    printf("Divisor (j): %d\n", j);
    printf("Next largest multiple: %d\n", next_multiple);

    /*
     * Find the next multiple of j that is greater than or equal to i.
     *
     * Step 1: Calculate the remainder when i is divided by j.
     *         256 % 7 = 4
     *
     * Step 2: Use the formula:
     *         next_multiple = i + j - (i % j)
     *
     *         = 256 + 7 - 4
     *         = 263 - 4
     *         = 259
     */
    return 0;
}
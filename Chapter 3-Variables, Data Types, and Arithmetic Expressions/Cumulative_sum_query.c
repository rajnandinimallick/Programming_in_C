#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int arr[100000];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int Q;
    scanf("%d", &Q);

    while (Q--)
    {
        int i, j;
        scanf("%d %d", &i, &j);

        long long sum = 0;

        for (int k = i; k <= j; k++)
        {
            sum += arr[k];
        }

        printf("%lld\n", sum);
    }

    return 0;
}
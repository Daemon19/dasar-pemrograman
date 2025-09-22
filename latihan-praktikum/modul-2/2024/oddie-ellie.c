#include <stdio.h>
#include <string.h>

int main(void)
{
    char S[101];
    unsigned long long N;
    scanf("%s", S);
    scanf("%llu", &N);

    unsigned long long a;
    unsigned long long n;
    if (strcmp(S, "Ellie") == 0)
    {
        a = 2;
        n = (N % 2 == 0) ? N : N - 1;
    }
    else if (strcmp(S, "Oddie") == 0)
    {
        a = 1;
        n = (N % 2 == 1) ? N : N - 1;
    }
    else
    {
        printf("Who is that?\n");
        return 0;
    }

    unsigned long long sum = 0;
    for (unsigned long long i = a; i <= n; i += 2)
    {
        sum += i;
    }
    printf("%llu\n", sum);

    return 0;
}
#include <stdio.h>
#include <string.h>

unsigned long long Vikturial(unsigned long long n, unsigned long long v)
{
    if (n <= v)
        return n;
    return n * Vikturial(n - v, v);
}

int main()
{
    unsigned long long T;
    scanf("%llu", &T);

    for (unsigned long long i = 0; i < T; i++)
    {
        unsigned long long N, V;
        scanf("%llu %llu", &N, &V);
        printf("%llu\n", Vikturial(N, V));
    }

    return 0;
}
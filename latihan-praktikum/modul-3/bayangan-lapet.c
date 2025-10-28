#include <stdio.h>

int main()
{
    unsigned long long N;
    scanf("%llu", &N);

    unsigned long long tab[2] = {0, 1};
    unsigned long long p = 1;
    for (unsigned long long i = 0; i < N - 1; i++)
    {
        p = !p;
        tab[p] += tab[!p];
    }

    unsigned long long x = tab[p];
    x *= (x % 2) ? 123 : 321;

    printf("%llu\n", x);
    printf("%s\n", (x % 5)
                       ? "TERIMAKASIH LUPUT TELAH MENJADI PASANGANKU"
                       : "AKU TERJEBAK DALAM DUNIAKU");

    return 0;
}
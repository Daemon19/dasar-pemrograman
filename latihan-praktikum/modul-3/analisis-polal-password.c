#include <stdio.h>

void Print(int n)
{
    if (n < 1)
    {
        return;
    }
    if (n == 1)
    {
        printf("d\n");
        return;
    }

    Print(n - 1);

    char c = (n % 2) ? 'd' : 'e';
    for (int i = 0; i < n; i++)
        printf("%c", c);
    printf("\n");

    Print(n - 1);
}

int main()
{
    int N;
    scanf("%d", &N);

    Print(N - 1);

    for (int i = 0; i < N; i++)
        printf("z");
    printf("\n");

    Print(N - 1);
    return 0;
}
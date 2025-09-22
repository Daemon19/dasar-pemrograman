#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int T;
    char S[101];

    scanf("%d", &T);
    scanf("%s", S);

    int len = strlen(S);
    int n = len / T + (len % T != 0);

    char arr[100][100] = {0};
    for (int i = 0, j = 0, k = 0; i < len; i++)
    {
        if (j + k >= len)
        {
            j = 0;
            k++;
        }
        arr[k][j + k] = S[i];
        j += T;
    }

    for (int i = 0; i < len; i++)
    {
        char c = arr[i % T][i];
        printf("%c", (c != '_') ? c : ' ');
    }
    printf("\n");

    return 0;
}
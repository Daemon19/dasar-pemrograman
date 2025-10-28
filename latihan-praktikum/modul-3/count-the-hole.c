#include <stdio.h>
#include <memory.h>
#include <limits.h>

#define MAX 100

int map[MAX][MAX];
int visited[MAX][MAX];

int CariLuas(int i, int j, int v[MAX][MAX])
{
    if (i < 0 || i >= MAX ||
        j < 0 || j >= MAX ||
        !map[i][j] || v[i][j])
        return 0;

    v[i][j] = 1;
    visited[i][j] = 1;
    return (CariLuas(i - 1, j - 1, v) +
            CariLuas(i - 1, j, v) +
            CariLuas(i - 1, j + 1, v) +
            CariLuas(i, j - 1, v) +
            CariLuas(i, j, v) +
            CariLuas(i, j + 1, v) +
            CariLuas(i + 1, j - 1, v) +
            CariLuas(i + 1, j, v) +
            CariLuas(i + 1, j + 1, v) +
            1);
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &map[i][j]);
            // map[i][j] = !map[i][j];
            map[i][j] ^= 1;
            visited[i][j] = 0;
        }
    }

    int counts[MAX * MAX + 1] = {};
    int count = 0;
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j])
                continue;

            int v[MAX][MAX];
            memset(v, 0, MAX * MAX);
            int luas = CariLuas(i, j, v);
            if (luas == 0)
                continue;

            counts[luas]++;
            count++;
            max = (luas > max) ? luas : max;
        }
    }

    printf("Banyak genangan: %d\n", count);
    printf("Luas terbesar: %d\n", max);
    printf("List lubang:\n");
    for (int i = MAX * MAX; i >= 0; i--)
    {
        if (!counts[i])
            continue;
        printf("#%d = %d\n", i, counts[i]);
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str[200];
    scanf(" %[^\n]", str);
    int len = strlen(str);
    int s = 0;

    while (s < len)
    {
        while (!isalpha(str[s]) && s < len)
            s++;

        if (s >= len)
            break;

        int e = s;
        while (isalpha(str[e]) && e < len)
            e++;
        e--;

        int i = e;
        while (s < i)
        {
            char c = str[s];
            str[s] = str[i];
            str[i] = c;
            s++;
            i--;
        }
        s = e + 1;
    }

    for (int i = 0; i < len - 1; i++)
    {
        if (str[i] == 'g' && str[i + 1] == 'n')
        {
            str[i] = 'n';
            str[i + 1] = 'g';
        }
    }

    str[0] = str[0] & 0b1011111;
    printf("%s\n", str);
}
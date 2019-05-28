#include <string.h>
#include <stdlib.h>

int calc(char *s, int index)
{
    int o = 0, e = 0, len = 0;
    for (unsigned int i = index; i < strlen(s); i++)
    {
        if ((s[i] - '0') % 2 == 0)
            e += 1;
        else
            o += 1;
        if (o == e)
            len = o + e;
    }
    return (len);
}

char    *longest_subarray(char *arr)
{
    char *result;
    int *l;
    int len = strlen(arr);

    l = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        l[i] = 0;
    }
    int max = 0;
    for (int i = 0; i < len; i++)
    {
        int tmp = calc(arr, i);
        l[i] = tmp;
        if (tmp > max)
            max = tmp;
    }
    int i = 0;
    while (i < len)
    {
        if (l[i] == max)
        {
            break;
        }
        i++;
    }
    result = malloc(sizeof(char) * (max + 1));
    result[max] = '\0';
    for (int j = 0; j < max; j++)
        result[j] = arr[j + i];
    return (result);
}

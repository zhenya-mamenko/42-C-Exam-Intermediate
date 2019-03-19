int	gold_gain(int **mine, int n)
{
    int i, j, tmp;

    i = 1;
    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            tmp = (j > 0) ? mine[j - 1][i - 1] : 0;
            if (tmp < mine[j][i - 1])
                tmp = mine[j][i - 1];
            if (j < n - 1 && (tmp < mine[j + 1][i - 1]))
                tmp = mine[j + 1][i - 1];
            mine[j][i] = mine[j][i] + tmp;
            j++;
        }
        i++;
    }
    tmp = 0;
    i = 0;
    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            if (tmp < mine[i][j])
                tmp = mine[i][j];
            j++;
        }
        i++;
    }
    return (tmp);
}

/*

#include <stdlib.h>
#include <stdio.h>

int **make_array(int *a, int n)
{
    int **res;
    int i, j;

    res = malloc(sizeof(int *) * n);
    i = 0;
    while (i < n)
    {
        res[i] = malloc(sizeof(int) * n);
        j = 0;
        while (j < n)
        {
            res[i][j] = a[i * n + j];
            j++;
        }
        i++;
    }
    return (res);
}

int main(void)
{
    int a[] = { 1, 3, 1, 5, 2, 2, 4, 1, 5, 0, 2, 3, 0, 6, 1, 2 };
    int n = 4;

    printf("%d\n", gold_gain(make_array(a, n), n));
}

*/
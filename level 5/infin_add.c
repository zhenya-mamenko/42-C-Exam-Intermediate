#include <stdlib.h>
#include <unistd.h>

int len(char *s)
{
    int l = 0;
    while (s[l])
        l++;
    return (l);
}

void infin_add(char *x, char *y)
{
    int sx = 1, sy = 1;
    if (x[0] == '-')
    {
        sx = -1;
        x++;
    }
    while (*x && *x == '0')
        x++;
    if (!(*x))
        x--;
    if (y[0] == '-')
    {
        sy = -1;
        y++;
    }
    while (*y && *y == '0')
        y++;
    if (!(*y))
        y--;
    if (x[0] == '0' && len(x) == 1)
    {
        if (sy == -1 && !(y[0] == '0' && len(y) == 1))
            write(1, "-", 1);
        write(1, y, len(y));
        return ;
    }
    if (y[0] == '0' && len(y) == 1)
    {
        if (sx == -1)
            write(1, "-", 1);
        write(1, x, len(x));
        return ;
    }
    int l = (len(x) > len(y) ? len(x) : len(y)) + 1;
    char *r = malloc(sizeof(char) * (l + 1));
    r[l] = '\0';
    for (int i = 0; i < l; i++)
        r[i] = '0';
    if (sx != sy)
    {
        int f = 0;
        if (len(x) == len(y))
        {
            for (int i = 0; i < len(x); i++)
            {
                if (y[i] > x[i])
                {
                    f = 1;
                    break ;
                }
            }
        }
        else
        {
            if (len(y) > len(x))
                f = 1;
        }
        if (f == 1)
        {
            char *t = x;
            x = y;
            y = t;
            int tmp = sx;
            sx = sy;
            sy = tmp;
        }
    }
    for (int i = 0; i < l - 1; i++)
    {
        int vx = (i < len(x)) ? x[len(x) - i - 1] - '0' : 0;
        int vy = (i < len(y)) ? y[len(y) - i - 1] - '0' : 0;
        if (sx == sy)
        {
            int v = vx + vy + (r[l - i - 1] - '0');
            r[l - i - 1] = (v % 10) + '0';
            r[l - i - 2] = (v / 10) + '0';
        }
        else
        {
            int v = vx - vy + (r[l - i - 1] - '0');
            r[l - i - 1] = ((v >= 0 ? v : 10 + v) % 10) + '0';
            r[l - i - 2] = (v >= 0 ? 0 : -1) + '0';
        }
    }
    while (*r && *r == '0')
        r++;
    if (sx == -1 && (*r))
        write(1, "-", 1);
    if (!(*r))
        r--;
    write(1, r, len(r));
}

int main(int ac, char **av)
{
    if (ac == 3)
        infin_add(av[1], av[2]);
    write(1, "\n", 1);
}
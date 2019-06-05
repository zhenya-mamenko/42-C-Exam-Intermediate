#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void z(char *s, int c)
{
    for (int i = 0; i < c; i++)
        s[i] = '\0';
}

void m(char *d, char *s, int c)
{
    for (int i = 0; i < c; i++)
        d[i] = s[i];
}

int a(char *s, int l)
{
    for (int i = 0; i < l - 1; i++)
    {
        if (s[i] != '.' && s[i] != 'X')
            return (-1);
    }
    return (s[l - 1] != '\n' ? -1 : 1);
}

void count(char **map, int y, int x, int j, int k, int n)
{
    map[y][x] = '0' + n;
    if (y > 0 && map[y - 1][x] == 'X')
        count(map, y - 1, x, j, k, n);
    if (x > 0 && map[y][x - 1] == 'X')
        count(map, y, x - 1, j, k, n);
    if (y < j - 1 && map[y + 1][x] == 'X')
        count(map, y + 1, x, j, k, n);
    if (x < k - 1 && map[y][x + 1] == 'X')
        count(map, y, x + 1, j, k, n);
}

void count_island(char *s)
{
    char b[1024];
    int fd, cnt, l, i;

    fd = open(s, O_RDONLY);
    if (fd == -1)
    {
        write(1, "\n", 1);
        return ;
    }
    i = 0;
    z(b, 1024);
    while ((cnt = read(fd, b + i, 1)) == 1 && b[i] != '\n' && i < 1024)
        i++;
    l = i + 1;
    if (cnt != 1 || i == 1024 || b[i] != '\n' || a(b, l) == -1)
    {
        write(1, "\n", 1);
        return ;
    }
    char **map;
    map = malloc(sizeof(char *) * 10000);
    for (int j = 0; j < 10000; j++)
        map[j] = malloc(sizeof(char) * l);
    m(map[0], b, l);
    i = 1;
    z(b, l);
    while ((cnt = read(fd, b, l)) == l)
    {
        if (a(b, l) == -1)
        {
            write(1, "\n", 1);
            return ;
        }
        m(map[i], b, l);
        z(b, l);
        i++;
    }
    if (cnt != 0)
    {
        write(1, "\n", 1);
        return ;
    }
    int n = 0;
    for (int j = 0; j < i; j++)
    {
        for (int k = 0; k < l; k++)
        {
            if (map[j][k] == 'X')
            {
                count(map, j, k, i, l, n);
                n++;
            }
        }
        write(1, map[j], l);
    }

}
int main(int ac, char **av)
{
    if (ac == 2)
    {
        count_island(av[1]);
    }
    else
    {
        write(1, "\n", 1);
    }
}
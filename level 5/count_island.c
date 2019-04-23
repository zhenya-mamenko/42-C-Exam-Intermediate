#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void count(char *s, int row, int col, int r, int l, int k)
{
    s[row * l + col] = '0' + k;
    if (row > 0 && s[(row - 1) * l + col] == 'X')
        count(s, row - 1, col, r, l, k);
    if (row + 1 < r && s[(row + 1) * l + col] == 'X')
        count(s, row + 1, col, r, l, k);
    if (col > 0 && s[row * l + col - 1] == 'X')
        count(s, row, col - 1, r, l, k);
    if (col + 1 < l && s[row * l + col + 1] == 'X')
        count(s, row, col + 1, r, l, k);
}

void count_island(char *s)
{
    char buf[1024], *island;
    int fd, l, i, cnt, r;

    fd = open(s, O_RDONLY);
    if (fd == -1)
    {
        write(1, "\n", 1);
        return ;
    }
    l = read(fd, buf, 1024);
    if (close(fd) == -1 || l <= 0)
    {
        write(1, "\n", 1);
        return ;
    }
    i = 0;
    while (i < l)
    {
        if (buf[i] == '\n')
            break ;
        i++;
    }
    if (i == l)
    {
        write(1, "\n", 1);
        return ;
    }
    l = i + 1;
    if ((island = malloc(100000)) == NULL)
    {
        write(1, "\n", 1);
        return ;
    }
    i = 0;
    while (i < 100000)
        island[i++] = '\0';
    fd = open(s, O_RDONLY);
    if (fd == -1)
    {
        write(1, "\n", 1);
        return ;
    }
    r = 0;
    while ((cnt = read(fd, buf, l)) > 0)
    {
        if (cnt != l || buf[l - 1] != '\n')
        {
            write(1, "\n", 1);
            return ;
        }
        i = 0;
        while (i < l)
        {
            if ((buf[i] != '\n' && buf[i] != 'X' && buf[i] != '.') || (buf[i] == '\n' && i != l - 1))
            {
                write(1, "\n", 1);
                return ;
            }
            island[r * l + i] = buf[i];
            i++;
        }
        r++;
    }
    int k = 0;
    i = 0;
    while (i < r)
    {
        int j = 0;
        while (j < l)
        {
            if (island[i * l + j] == 'X')
                count(island, i, j, r, l, k++);
            j++;
        }
        i++;
    }
    write(1, island, r * l);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] != '\0')
        count_island(av[1]);
    else
        write(1, "\n", 1);
}
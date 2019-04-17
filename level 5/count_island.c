#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void fill(char *s, int i, int n, int k, int len)
{
    s[i] = '0' + k;
    if (i - 1 >= 0 && s[i - 1] == 'X')
        fill(s, i - 1 , n, k, len);
    if (i + 1 < len && s[i + 1] == 'X')
        fill(s, i + 1 , n, k, len);
    if (i - n >= 0 && s[i - n] == 'X')
        fill(s, i - n , n, k, len);
    if (i + n < len && s[i + n] == 'X')
        fill(s, i + n , n, k, len);
}

void count_island(char *f)
{
    int fd, len, tmp;
    char buf[1000];
    char *q;

    fd = open(f, O_RDONLY);
    if (fd == -1)
        return ;
    len = 0;
    while ((tmp = read(fd, buf, 1000)) > 0)
        len += tmp;
    if (close(fd) == -1 || len == 0)
        return ;
    fd = open(f, O_RDONLY);
    if (fd == -1)
        return ;
    q = malloc(len + 1);
    q[len] = '\0';
    if (q == NULL)
        return ;
    read(fd, q, len);
    close(fd);
    int n = -1, i = 0;
    while (q[i])
    {
        if (q[i] != '\n' && q[i] != '.' && q[i] != 'X')
            return ;
        if (q[i++] == '\n')
        {
            if (n == -1)
                n = i;
            else if (i % n != 0)
                return ;
        }
    }
    int k = 0;
    i = 0;
    while (q[i])
    {
        if (q[i] == 'X')
            fill(q, i, n, k++, len);
        i++;
    }
    write(1, q, len);
}

int main(int ac, char **av)
{
    if (ac == 2)
        count_island(av[1]);
    else
        write(1, "\n", 1);
}

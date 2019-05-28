#include <stdlib.h>
#include <unistd.h>

int len(char *s)
{
    int l = 0;
    while (s[l])
        l++;
    return (l);
}

int stristr(char *s, char *f)
{
    if (len(f) > len(s))
        return (-1);
    int cnt = 0, i = 0;
    while (i < len(s))
    {
        if (s[i] == f[cnt])
        {
            cnt++;
            if (cnt == len(f))
                return (1);
        }
        else
        {
            i -= cnt;
            cnt = 0;
        }
        i++;
    }
    return (-1);
}

void clear(char *s, int cnt)
{
     for (int i = 0; i < cnt; i++)
        s[i] = '\0';
}

void cp(char *to, char *from)
{
    for (int i = 0; i <= len(from); i++)
        to[i] = from[i];
}

void str_maxlenoc(int ac, char **av)
{
    if (ac == 1)
    {
        write(1, av[0], len(av[0]));
        return ;
    }

    int min_len = 2147483647, item = 0;
    for (int i = 0; i < ac; i++)
    {
        int l = len(av[i]);
        if (l < min_len)
        {
            min_len = l;
            item = i;
        }
    }
    char *result = malloc(sizeof(char) * (min_len + 1));
    char *test = malloc(sizeof(char) * (min_len + 1));
    clear(result, (min_len + 1));
    clear(test, (min_len + 1));
    int cnt = 0, i = 0;
    while (i < min_len)
    {
        test[cnt] = av[item][i];
        for (int j = 0; j < ac; j++)
        {
            if (stristr(av[j], test) == -1)
            {
                test[cnt] = '\0';
                if (len(test) > len(result))
                    cp(result, test);
                i -= len(test);
                clear(test, cnt);
                cnt = -1;
                break;
            }
        }
        if (len(test) > len(result))
            cp(result, test);
        cnt++;
        i++;
    }
    write(1, result, len(result));
}

int main(int ac, char **av)
{
    if (ac != 1)
        str_maxlenoc(ac - 1, av + 1);
    write(1, "\n", 1);
}

#include <stdlib.h>
#include <unistd.h>

int len(char *s)
{
    int l = 0;
    while (s[l])
        l++;
    return (l);
}

void infin_mult(char *s, char *a, char *b, int l)
{
    int la = len(a);
    int lb = len(b);
    int i = 0;
    while (i < la)
    {
        int j = 0;
        while (j < lb)
        {
            s[l - i - j] -= '0';
            s[l - i - j] += (a[la - i - 1] - '0') * (b[lb - j - 1] - '0');
            if (s[l - i - j] >= 10)
            {
                s[l - i - j -1] += s[l - i - j] / 10;
                s[l - i - j] %= 10;
            }
            s[l - i - j] += '0';
            j++;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    (void)ac;
    char *s, *s1, *s2;
    int sign = 1;

    s1 = av[1];
    s2 = av[2];
    if (s1[0] == '-')
    {
        s1++;
        sign *= -1;
    }
    if (s2[0] == '-')
    {
        s2++;
        sign *= -1;
    }
    int l1 = len(s1);
    int l2 = len(s2);
    if ((l1 == 1 && s1[0] == '0') || (l2 == 1 && s2[0] == '0'))
    {
        write(1, "0\n", 2);
        return (0);
    }
    int l = (l1 > l2 ? l1 : l2) * 2 + 3;
    s = malloc(sizeof(char) * l);
    int i = 0;
    while (i < l)
    {
        s[i] = '0';
        i++;
    }
    s[l - 1] = '\0';
    infin_mult(s, s1, s2, l - 2);
    if (sign == -1)
        write(1, "-", 1);
    while (*s == '0')
        s++;
    while (*s)
    {
        write(1, s, 1);
        s++;
    }
    write(1, "\n", 1);
}
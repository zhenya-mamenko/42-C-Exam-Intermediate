int is_anagram(char *a, char *b)
{
    int t[127] = {0};
    int i;

    i = 0;
    while (a[i])
        t[(unsigned int)a[i++]] += 1;
    i = 0;
    while (b[i])
        t[(unsigned int)b[i++]] -= 1;
    i = 0;
    while (i < 127)
        if (t[i++] != 0)
            return (0);
    return (1);
}

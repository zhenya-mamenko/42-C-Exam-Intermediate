#include <unistd.h>
#include <stdlib.h>

typedef struct s_words
{
    char *word;
    struct s_words *next;
} t_words;

typedef struct s_lines
{
    int cnt;
    t_words *words;
    struct s_lines *next;
} t_lines;

int len(char *s)
{
    int i;
    i = 0;
    while (s[i])
        i++;
    return (i);
}

void ft_putstr(char *s)
{
    write(1, s, len(s));
}

char *extract_word(char **ss)
{
    int f;
    char *s, *b, *r; 

    s = *ss;
    b = s;
    f = 0;
    while (*s)
    {
        if (*s != ' ' && *s != '\t')
        {
            if (f == 0)
                b = s;
            f = 1;
        }
        else
        {
            if (f == 1)
                break ;
        }
        s++;
    }
    r = malloc(sizeof(char) * (s - b + 2));
    f = 0;
    while (b != s)
    {
        r[f] = *b;
        f++;
        b++;
    }
    r[f] = '\0';
    *ss = s;
    return (r);
}

void add_word(t_lines **l, char *s)
{
    t_lines *nl, *k, *ll;
    t_words *w;

    k = *l;
    while (k)
    {
        if (k->cnt == len(s))
            break ;
        ll = k;
        k = k->next;
    }
    if (!k)
    {
        nl = malloc(sizeof(t_lines));
        nl->next = NULL;
        nl->cnt = len(s);
        nl->words = malloc(sizeof(t_words));
        nl->words->word = s;
        nl->words->next = NULL;
        if (!(*l))
            *l = nl;
        else
            ll->next = nl;
    }
    else
    {
        w = k->words;
        while (w->next)
            w = w->next;
        w->next = malloc(sizeof(t_words));
        w = w->next;
        w->next = NULL;
        w->word = s;
    }
}

void sort_lines(t_lines *l)
{
    t_lines *f;
    t_words *w;
    int t;

    f = l;
    while (f->next)
    {
        l = f;
        while (l->next)
        {
            if (f->cnt > l->next->cnt)
            {
                t = f->cnt;
                w = f->words;
                f->cnt = l->next->cnt;
                f->words = l->next->words; 
                l->next->cnt = t;
                l->next->words = w;
            }
            l = l->next;
        }
        f = f->next;
    }
}

int cmp(char *s1, char *s2)
{
    char c1, c2;
    while (*s1)
    {
        c1 = *s1;
        if (c1 >= 'A' && c1 <= 'Z')
            c1 += 'a' - 'A';
        c2 = *s2;
        if (c2 >= 'A' && c2 <= 'Z')
            c2 += 'a' - 'A';
        if (c1 != c2)
            return (c1 > c2 ? 1 : -1);
        s1++;
        s2++;
    }
    return (0);
}

void sort_words(t_words *w)
{
    t_words *f;
    char *t;

    f = w;
    while (f->next)
    {
        w = f;
        while (w->next)
        {
            if (cmp(f->word, w->next->word) > 0)
            {
                t = f->word;
                f->word = w->next->word;
                w->next->word = t;
            }
            w = w->next;
        }
        f = f->next;
    }
}

void ord_alphlong(char *s)
{
    char *w;
    t_lines *l;
    t_words *ww;

    l = NULL;
    while (1)
    {
        w = extract_word(&s);
        if (len(w) == 0)
            break ;
        add_word(&l, w);
    }

    sort_lines(l);
    while (l)
    {
        ww = l->words;
        sort_words(ww);
        while (ww)
        {
            ft_putstr(ww->word);
            ww = ww->next;
            if (ww)
                ft_putstr(" ");
        }
        l = l->next;
        if (l)
            ft_putstr("\n");
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ord_alphlong(av[1]);
    }
    ft_putstr("\n");
}
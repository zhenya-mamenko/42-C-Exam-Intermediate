#include <unistd.h>
#include <stdlib.h>

typedef struct	s_strings
{
	char		*s;
	struct		s_strings *next;
}				t_strings;

typedef struct s_lines
{
	int wlen;
	t_strings *strings;
	struct s_lines *next;
}	t_lines;

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i += 1;
	return (i);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

char	*extract_word(char *s, int b, int e)
{
	char	*r;
	int		i;

	i = (e - b + 1);
	r = (char *)malloc(sizeof(char) * i);
	i = b;
	while (i < e && s[i])
	{
		r[i - b] = s[i];
		i += 1;
	}
	r[i - b] = '\0';
	return (r);
}

void setup_word(char *w, t_lines **tl)
{
	t_strings	*ts, *se;
	t_lines		*le;
	int			l;

	ts = malloc(sizeof(t_strings));
	ts->next = NULL;
	ts->s = w;
	l = ft_strlen(w);
	le = *tl;
	if (le != NULL)
		while (le->next)
		{
			if (le->wlen == l)
				break ;
			le = le->next;
		}
	if (le == NULL || (le->next == NULL && le->wlen != l))
	{
		if (le == NULL)
			le = malloc(sizeof(t_lines));
		else
		{
			le->next = malloc(sizeof(t_lines));
			le = le->next;
		}
		le->next = NULL;
		le->strings = ts;
		le->wlen = l;
	}
	else if (le->wlen == l)
	{
		se = le->strings;
		while (se->next)
			se = se->next;
		se->next = ts;
	}
	if (*tl == NULL)
		*tl = le;
}

int ft_ts_cmp(char *s1, char *s2)
{
	char	c1;
	char	c2;

	while (*s1 && *s2)
	{
		if ((*s1 >= '0' && *s1 <= '9') || (*s2 >= '0' && *s2 <= '9'))
		{
			if (*s1 != *s2)
				return (*s1 - *s2);
		}
		else
		{
			c1 = (*s1 >= 'A' && *s1 <= 'Z') ? *s1 - 'A' : *s1 - 'a';
			c2 = (*s2 >= 'A' && *s2 <= 'Z') ? *s2 - 'A' : *s2 - 'a';
			if (c1 != c2)
				return (c1 - c2);
		}
		s1++;
		s2++;
	}
	return(*s1 - *s2);
}

void sort_strings(t_strings *ts)
{
	char		*s;
	int			changes;
	t_strings 	*se;

	changes = 1;
	while (changes != 0)
	{
		se = ts;
		changes = 0;
		while (ts->next)
		{
			if (ft_ts_cmp(ts->s, ts->next->s) > 0)
			{
				s = ts->s;
				ts->s = ts->next->s;
				ts->next->s = s;
				changes += 1;
			}
			ts = ts->next;
		}
		ts = se;
	}
}

void sort_lines(t_lines *tl)
{
	t_strings	*ts;
	int			i;
	int			changes;
	t_lines 	*le;

	changes = 1;
	while (changes != 0)
	{
		le = tl;
		changes = 0;
		while (tl->next)
		{
			if (tl->wlen > tl->next->wlen)
			{
				ts = tl->strings;
				i = tl->wlen;
				tl->strings = tl->next->strings;
				tl->wlen = tl->next->wlen;
				tl->next->strings = ts;
				tl->next->wlen = i;
				changes += 1;
			}
			tl = tl->next;
		}
		tl = le;
	}
}

void ord_alphlong(char *s)
{
	t_lines		*tl;
	t_strings	*ts;
	int			i;
	char		*w;
	int			f;
	int			b;

	tl = NULL;
	i = 0;
	f = 0;
	b = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
		{
			if (f == 0)
				b = i;
			f = 1;
		}
		else
		{
			if (f == 1)
			{
				w = extract_word(s, b, i);
				setup_word(w, &tl);
			}
			f = 0;
		}
		i += 1;
	}
	if (f == 1)
	{
		w = extract_word(s, b, i);
		setup_word(w, &tl);
	}
	sort_lines(tl);
	while (tl)
	{
		ts = tl->strings;
		sort_strings(ts);
		while (ts)
		{
			ft_putstr(ts->s);
			ts = ts->next;
			if (ts != NULL)
				ft_putstr(" ");
		}
		tl = tl->next;
		ft_putstr("\n");
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ord_alphlong(av[1]);
	}
	else
		ft_putstr("\n");
}

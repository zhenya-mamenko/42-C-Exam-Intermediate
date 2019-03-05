#include <stdio.h>

typedef struct	s_occ
{
	char	c;
	int		count;
} 				t_occ;

void	count_alpha(char *s)
{
	t_occ	a[26];
	int		i;
	int		j;
	int		cnt;
	char	c;

	i = 0;
	while (i < 26)
	{
		a[i].count = 0;
		a[i].c = ' ';
		i += 1;
	}
	i = 0;
	cnt = 0;
	while (s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			j = 0;
			c = (s[i] >= 'a' && s[i] <= 'z') ? s[i] - 'a' : s[i] - 'A';
			while (j < cnt)
			{
				if (a[j].c == c)
					break ;
				j += 1;
			}
			if (j == cnt)
			{
				a[j].c = c;
				cnt += 1;
			}
			a[j].count += 1;

		}
		i += 1;
	}
	i = 0;
	while (i < cnt)
	{
		printf("%d%c%s", a[i].count, a[i].c + 'a', i == cnt - 1 ? "" : ", ");
		i += 1;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		count_alpha(av[1]);
	}
	printf("\n");
}

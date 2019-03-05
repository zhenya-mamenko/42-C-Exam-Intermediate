int		c2num(int n)
{
	int		count;

	count = 0;
	while (n / 10 >= 1)
	{
		if (n % 10 == 2)
			count += 1;
		n /= 10;
	}
	if (n % 10 == 2)
		count += 1;

	return (count);
}

int		count_of_2(int n)
{
	int		i;
	int		result;

	i = 2;
	result = 0;
	while (i <= n)
	{
		result += c2num(i);
		i += 1;
	}

	return (result);
}

struct	s_node {
	int				value;
	struct s_node	**nodes;
};

int		calc_height(struct s_node *el)
{
	int		i;
	int		max;
	int		count;

	count = 0;
	i = 0;
	max = 0;
	while (el->nodes && el->nodes[i])
	{
		count = calc_height(el->nodes[i]) + 1;
		if (count > max)
			max = count;
		i += 1;
	}

	return (max);
}

int		height_tree(struct s_node *root)
{
	int		result;

	result = -1;
	if (root)
	{
		result = calc_height(root);
	}

	return (result);
}

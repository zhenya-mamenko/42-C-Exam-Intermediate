struct s_node
{
	int value;
	struct s_node *next;
};

int	is_looping(struct s_node *node)
{
    while (node)
    {
        if (node->value == -1)
            return (1);
        node->value = -1;
        node = node->next;
    }
    return (0);
}

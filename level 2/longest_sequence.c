struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int calc(struct s_node *n, int l)
{
    int tmp = 0;
    int result = l;

    if (n->left)
    {
        if (n->left->value == n->value + 1)
            tmp = calc(n->left, l + 1);
        else
            tmp = calc(n->left, 1);
        if (tmp > result)
            result = tmp;
    }
    if (n->right)
    {
        if (n->right->value == n->value + 1)
            tmp = calc(n->right, l + 1);
        else
            tmp = calc(n->right, 1);
        if (tmp > result)
            result = tmp;
    }
    return (result);
}

int	longest_sequence(struct s_node *node)
{
    if (!node)
        return (0);
    return (calc(node, 1));
}

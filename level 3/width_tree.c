struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int w_tree(struct s_node *n)
{
    int tmp1, tmp2;
    if (!n)
        return(0);
    tmp1 = w_tree(n->left);
    tmp2 = w_tree(n->right);
    n->value = tmp1 + 1 + tmp2;
    return ((tmp1 > tmp2 ? tmp1 : tmp2) + 1);
}

int max_tree(struct s_node *n)
{
    if (!n)
        return(0);
    int v = n->value, tmp = 0;
    tmp = max_tree(n->left);
    if (tmp > v)
        v = tmp;
    tmp = max_tree(n->right);
    if (tmp > v)
        v = tmp;
    return (v);
}

int	width_tree(struct s_node *n)
{
    if (!n)
        return (0);
    w_tree(n);
    return (max_tree(n));
}
struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int count(struct s_node *n)
{
    int cnt = 0;
    if (!n)
        return (0);
    cnt = 1 + count(n->left) + count(n->right);
    n->value = cnt;
    return (cnt);
}

int can(struct s_node *n, int cnt)
{
    if (!n)
        return (0);
    if (cnt - n->value == n->value)
        return (1);
    if (can(n->left, cnt) == 1)
        return (1);
    if (can(n->right, cnt) == 1)
        return (1);
    return (0);
}

int	can_split(struct s_node *n)
{
    int cnt = count(n);

    if (cnt == 0 || cnt % 2 == 1)
        return (0);
    return(can(n, cnt));
}

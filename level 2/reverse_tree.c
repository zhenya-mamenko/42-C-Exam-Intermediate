struct				s_node
{
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};


void				reverse(struct s_node *el)
{
	struct s_node	*tmp;

	tmp = el->right;
	el->right = el->left;
	el->left = tmp;
	if (el->right)
		reverse(el->right);
	if (el->left)
		reverse(el->left);
}

void				reverse_tree(struct s_node *root)
{
	if (root)
		reverse(root);
}

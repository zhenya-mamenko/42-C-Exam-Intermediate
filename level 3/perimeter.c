#include <stdio.h>

struct s_node {
    int           value;
    struct s_node *right;
    struct s_node *left;
};

void print_left(struct s_node *n)
{
    if (!n || (!n->left && !n->right))
        return ;
    printf(" %d", n->value);
    print_left(n->left);
}

void print_right(struct s_node *n)
{
    if (!n || (!n->left && !n->right))
        return ;
    print_right(n->right);
    printf(" %d", n->value);
}

void print_leafs(struct s_node *n)
{
    if (!n)
        return ;
    if (!n->left && !n->right)
    {
        printf(" %d", n->value);
    }
    else
    {
        print_leafs(n->left);
        print_leafs(n->right);
    }
}

void perimeter(struct s_node *root)
{
    if (!root)
        return ;
    printf("%d", root->value);
    print_left(root->left);
    if (root->left || root->right)
        print_leafs(root);
    print_right(root->right);
    printf("\n");
}
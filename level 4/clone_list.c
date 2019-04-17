#include <stdlib.h>

struct s_node {
    int           data;
    struct s_node *next;
    struct s_node *other;
};

typedef struct s_list {
    struct s_node *new;
    struct s_node *old;
    struct s_list *next;
} t_list;

struct s_node *get_new(t_list *lst, struct s_node *node)
{
    t_list *n;

    if (node == NULL)
        return (NULL);
    n = lst;
    while (n)
    {
        if (node == n->old)
            return (n->new);
        n = n->next;
    }
    return (NULL);
}

struct s_node *clone_list(struct s_node *node)
{
    struct s_node *new, *clone;
    t_list *n, *lst;

    if (!node)
        return (NULL);
    clone = NULL;
    lst = NULL;
    while (node)
    {
        if (clone == NULL)
        {
            new = malloc(sizeof(struct s_node));
            clone = new;
        }
        else
        {
            new->next = malloc(sizeof(struct s_node));
            new = new->next;
        }
        new->data = node->data;
        new->next = NULL;
        new->other = node->other;
        if (lst == NULL)
        {
            n = malloc(sizeof(struct s_node));
            lst = n;
        }
        else
        {
            n->next = malloc(sizeof(t_list));
            n = n->next;
        }        
        n->next = NULL;
        n->new = new;
        n->old = node;
        node = node->next;
    }
    new = clone;
    while (new)
    {
        new->other = get_new(lst, new->other);
        new = new->next;
    }
    return (clone);
}


#include <stdio.h>

struct s_node *cn(int data, struct s_node *other)
{
    struct s_node *n;

    n = malloc(sizeof(struct s_node));
    n->data = data;
    n->next = NULL;
    n->other = other;
    return (n);
}

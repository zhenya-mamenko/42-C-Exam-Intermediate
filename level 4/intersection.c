#include <string.h>

struct s_node {
    void *content;
    struct s_node *next;
};

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
    struct s_node *n;

    if (lst1 == NULL || lst2 == NULL)
        return (NULL);
    while (lst1)
    {
        n = lst2;
        while (n)
        {
            if (lst1 == n)
                return (lst1);
            n = n->next;
        }
        lst1 = lst1->next;
    }
    return (NULL);
}

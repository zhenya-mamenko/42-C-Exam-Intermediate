#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
    int ia = 0, ib = 0, f = 0;
    while (ia < na && ib < nb)
    {
        if (a[ia] == b[ib])
        {
            printf("%s%d", f == 1 ? " ": "", a[ia]);
            f = 1;
        }
        if (a[ia] > b[ib])
            ib++;
        else
            ia++;        
    }
    printf("\n");
}

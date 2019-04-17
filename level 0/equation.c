#include <stdio.h>

void    equation(int n)
{
    int a = 0;
    while (a < 10)
    {
        int b = 0;
        while (b < 10)
        {
            int c = 0;
            while (c < 10)
            {
                if (10 * a + b + a + 10 * c == n)
                    printf("A = %d, B = %d, C = %d\n", a, b, c);
                c++;
            }
            b++;
        }
        a++;
    }
}

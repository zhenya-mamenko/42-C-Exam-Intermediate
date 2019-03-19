int	find_pivot(int *arr, int n)
{
    int     i;
    int     sum;
    int     ssum;

    i = 0;
    sum = 0;
    while (i < n)
    {
        sum += arr[i];
        i++;
    }
    i = n - 1;
    ssum = 0;
    while (i > 0)
    {
        if (sum - arr[i] == ssum)
            return (i);
        ssum += arr[i];
        sum -= arr[i];
        i--;
    }
    return (-1);    
}

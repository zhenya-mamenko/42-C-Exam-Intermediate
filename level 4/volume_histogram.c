int    volume_histogram(int *histogram, int size)
{
    int volume = 0, f = 1;

    while (f == 1)
    {
        int b = - 1, e = -1, i = 0;
        f = 0;
        while (i < size)
        {
            if (histogram[i] != 0)
            {
                if (b == -1)
                    b = i;
                e = i;
                histogram[i]--;
                f = 1;
            }
            else if (b != -1)
                volume++;
            i++;
        }
        if (e != -1)
            volume -= (size - e - 1);
    }
    return (volume);
}

#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int abs;
    int *res;
    int i = 0;

    abs = end - start;
    if (abs < 0)
        abs = abs * -1;
    abs += 1;
    res = malloc(4 * (abs));
    while (i < abs)
    {
        if (start > end)
            res[i] = start - i;
        else
            res[i] = start + i;
        i++;
    }
    return (res);
}
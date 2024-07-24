#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
    int len;
    int *arr;
    int i;

    i = 0;
    len = (end - start);
    if (len < 0)
        len = len * -1;
    len = len + 1;
    arr = malloc(sizeof(int) * len);
    if (end > start)
    {
        while (end >= start && i < len)
        {
            arr[i] = end;
            i++;
            end--;
        }
        return (arr);
    }
    if (end < start)
    {
        while (end <= start && i < len)
        {
            arr[i] = end;
            i++;
            end++;
        }
        return (arr);
    }
}
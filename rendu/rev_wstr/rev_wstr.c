#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char    *s;
    char    arr[2000][200];
    int     count;
    int     len;
    

    count = 0;
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (1);
    }
    s = argv[1];
    while (*s)
    {
        len = 0;
        while (*s != ' ' && *s != '\0')
        {
            arr[count][len] = *s;
            len++;
            s++;
        }
        arr[count][len] = '\0';
        if (*s != '\0')
        {
            s++;
            count++;
        }
    }
    while (count >= 0)
    {
        len = 0;
        while (arr[count][len] != '\0')
        {
            write(1, &arr[count][len], 1);
            len++;
        }
        if (count > 0)
            write(1, " ", 1);
        count--;
    }
    write(1, "\n", 1);
    return (0);
}

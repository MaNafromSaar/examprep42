#include <unistd.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
    char    *s;
    char    *tmp1;
    char    *tmp2;
    int     i;

    i = 0;
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    s = argv[1];
    while (s[i])
        i++;
    s = s + i - 1;
    while (i >= 0)
    {
        while(*s != ' ' && i >= 0)
        {
            s--;
            i--;
        }
        tmp2 = s + 1;
        while (*tmp2 != ' ' && *tmp2 != '\0')
        {
            write(1, tmp2, 1);
            tmp2++;
        }
        if (i > 0)
            write(1, " ", 1);
        s--;
        i--;
    }
    tmp1 = argv[1];
    while (*tmp1 && *tmp1 != ' ')
    {
        write(1, tmp1, 1);
        tmp1++;
    }
    write(1, "\n", 1);
    return (0);
}
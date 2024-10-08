#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char    *s;
    char    c;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    s = argv[1];
    while(*s)
    {
        if (*s >= 'a' && *s <= 'z')
        {
            c = ((*s - 'a') + 13) % 26 + 'a';
            write(1, &c, 1);
        }
        else if (*s >= 'A' && *s <= 'Z')
        {
            c = ((*s - 'A') + 13) % 26 + 'A';
            write(1, &c, 1);
        }
        else
            write(1, s, 1);
        s++;
    }
    write(1, "\n", 1);
    return (0);
}
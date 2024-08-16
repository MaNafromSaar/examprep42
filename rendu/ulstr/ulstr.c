#include <unistd.h>

int main(int argc, char **argv)
{
    char    *s;
    char    c;
    if (argc != 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    s = argv[1];
    while (*s)
    {
        c = *s;
        if (c >= 'A' && c <= 'Z')
        {
            c = c + 32;
            write(1, &c, 1);
        }
        else if (c >= 'a' && c <= 'z')
        {
            c = c - 32;
            write(1, &c, 1);
        }
        else 
            write(1, &c, 1);
        s++;
    }
    write(1, "\n", 1);
    return (0);
}
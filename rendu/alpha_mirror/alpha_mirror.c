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
            c = 25 - (c - 'A') + 'A';
            write(1, &c, 1);
        }
        else if (c >= 'a' && c <= 'z')
        {
            c = 25 - (c - 'a') + 'a';
            write(1, &c, 1);
        }
        else 
            write(1, &c, 1);
        s++;
    }
    write(1, "\n", 1);
    return (0);
}
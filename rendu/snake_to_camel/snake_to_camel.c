#include <unistd.h>

int main(int argc, char **argv)
{
    char    *s;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (1);
    }
    s = argv[1];
    while (*s != '\0')
    {
        if (*s == '_')
            s++;
        if (*(s-1) == '_' && *s >= 'a' && *s <= 'z')
        {
            *s = *s - 32;
            write(1, s, 1);
        }
        else
            write(1, s, 1);
        s++;
    }
    write(1, "\n", 1);
    return (0);
}
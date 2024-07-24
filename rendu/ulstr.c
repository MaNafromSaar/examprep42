#include <unistd.h>

int main(int argc, char **argv)
{
    char *s;

    s = argv[1];
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    while (*s)
    {
        if (*s >= 'a' && *s <= 'z')
            *s -= 32;
        else if (*s >= 'A' && *s <= 'Z')
            *s += 32;
        write(1, s, 1);
        s++;
    }
    write(1, "\n", 1);
}
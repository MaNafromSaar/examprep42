#include <unistd.h>

int main(int argc, char **argv)
{
    char    *s;
    if (argc != 2)
    {
        write(1, "\n", 1);
        return 1;
    }
    s = argv[1];
    while (*s)
    {
        if (*s >= 65 && *s <= 90)
        {
            *s = ((*s - 65 + 13) % 26) + 65;
            write(1, s, 1);
            s++;
        }
        else if (*s >= 97 && *s <= 122)
        {
            *s = ((*s -97 + 13) % 26) + 97;
            write(1, s, 1);
            s++;
        }
        else
        {
            write(1, s, 1);
            s++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
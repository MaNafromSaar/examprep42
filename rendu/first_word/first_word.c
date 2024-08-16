#include <unistd.h>

int main(int argc, char **argv)
{
    char    *s;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    s = argv[1];
    while (*s)
    {
        while (*s == ' ' || *s == '\t')
        {
            s++;
            if (*s == '\0')
            {
                write(1, "\n", 1);
                return (0);
            }
        }
        while (*s != ' ' && *s != '\t' && *s != '\0')
        {
            write(1, s, 1);
            s++;
        }
        *s = '\0';
    }
    write(1, "\n", 1);
    return (0);
}
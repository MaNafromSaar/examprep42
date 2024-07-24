#include <unistd.h>

int main(int argc, char ** argv)
{
    char    *s;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (1);
    }
    s = argv[1];
    while (*s)
    {
        if (*s == ' ' || (*s > 8 && *s < 14))
            s++;
        else
        {
            write(1, s, 1);
            if (*(s + 1) && (*(s + 1) == ' ' || (*(s + 1) > 8 && *(s + 1) < 14)) && *(s + 2) != '\0')
            {
                write(1, " ", 1);
            }
            s++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
#include <unistd.h>

int main(int argc, char **argv)
{
    char    *s;
    int     i;
    char    c;

    i = 1;
    if (argc < 2)
    {
        write(1, "\n", 1);
        return (1);
    }
    while (i < argc)
    {
        s = argv[i];
        while (*s)
        {
            c = *s;
            if ((c >= 'a' && c <= 'z') && (*(s+1) == ' ' || *(s+1) == '\0' || (*(s+1) > 8 && *(s+1) < 14)))
            {
                c = c - 32;
            }
            else if (*(s+1) != ' ' && c >= 'A' && c <= 'Z' && !(*(s+1) == ' ' || *(s+1) == '\0' || (*(s+1) > 8 && *(s+1) < 14)))
            {
                c = c + 32;
            }
            write(1, &c, 1);
            s++;
        }
        write(1, "\n", 1);
        i++;
    }
    return (0);
}
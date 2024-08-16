#include <unistd.h>

int main(int argc, char **argv)
{
    char    *s;
    char    c;
    int     i;

    i = 1;
    if (argc < 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    while (i < argc)
    {
    s = argv[i];
        while (*s)
        {
            c = *s;
            if (c >= 'A' && c <= 'Z' && (*(s + 1) != ' ' && (*(s + 1) < 9 || *(s + 1) > 13) && *(s + 1) != '\0'))
            {
                c = c + 32;
                write(1, &c, 1);
            }
            else if (c >= 'a' && c <= 'z' && (*(s + 1) == ' ' || (*(s + 1) >= 9 && *(s + 1) <= 13) || *(s + 1) == '\0'))
            {
                c = c - 32;
                write(1, &c, 1);
            }
            else 
                write(1, &c, 1);
            s++;
        }
        i++;
        write(1, "\n", 1);
    }
    return (0);
}
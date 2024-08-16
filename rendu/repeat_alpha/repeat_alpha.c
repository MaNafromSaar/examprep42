#include <unistd.h>

int main(int argc, char ** argv)
{
    char    *s;
    int     i;

    i = 0;
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (1);
    }
    s = argv[1];
    while (*s)
    {
        if (!(*s >= 'a' && *s <= 'z' || *s >= 'A' && *s <= 'Z'))
            write(1, s, 1);
        if (*s >= 'a' && *s <= 'z')
        {
            while(i <= *s - 97)
            {
                write(1, s, 1);
                i++;
            }
        }
         if (*s >= 'A' && *s <= 'Z')
        {
            while(i <= *s - 65)
            {
                write(1, s, 1);
                i++;
            }
        }
        i = 0;
        s++;
    }
    write(1, "\n", 1);
    return (0);
}
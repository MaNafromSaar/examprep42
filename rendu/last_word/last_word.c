#include <unistd.h>

int main(int argc, char **argv)
{
    char    *s;
    int     len;
    int     wordlen;

    len = 0;
    wordlen = 0;
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    s = argv[1];
    while (*s)
    {
        s++;
        len++;
    }
    s -= 1;
    while (len > 0)
    {
        while (len > 0 && (*s == ' ' || *s == '\t'))
        {
            len--;
            s--;
        }
        while (len > 0 && *s != ' ' && *s != '\t' && *s != '\0')
        {
            wordlen++;
            s--;
            len--;
        }
        s++;
        while (wordlen > 0)
        {
            write(1, s, 1);
            s++;
            wordlen--;
        }
        write(1, "\n", 1);
        return (0);
    }
    write(1, "\n", 1);
    return (0);
}

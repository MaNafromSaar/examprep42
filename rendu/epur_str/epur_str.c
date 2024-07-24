#include <unistd.h>

int main(int argc, char **argv)
{
    char *s;
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    s = argv[1];
    while (*s == ' ' || *s > 8 && *s < 14)
        s++;
        while (*s) 
        {
        if (!(*s == ' ' || (*s >= 9 && *s <= 13))) 
        {
            write(1, s, 1);
        } 
        else 
        {
            while (*(s + 1) && (*(s + 1) == ' ' || (*(s + 1) >= 9 && *(s + 1) <= 13))) 
            {
                s++;
            }
            if (*(s + 1)) 
            {
                write(1, " ", 1);
            }
        }
        s++;
    }
    write(1, "\n", 1);
    return (0);
}
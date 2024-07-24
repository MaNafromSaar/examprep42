#include <stdio.h>
#include <unistd.h>

int main(int argc,char **argv)
{
    char    *s = argv[1];
    //char    *temp = s;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    while (*s != '\0')
    {
        while (*s == ' ' || (*s > 8 && *s < 14))
            s++;
        while (*s > 32 && *s < 127 && !(*s == ' ' || (*s > 8 && *s < 14)))
        {
            write(1, s, 1);
            s++;
        }
        if (*s == ' ' || (*s > 8 && *s < 14))
        {
            while (*s == ' ' || (*s > 8 && *s < 14))
            {
                s++;
            }
            if (*s != '\0')
                write(1, "   ", 3);
        }
    }
    if (*s == '\0')
        write(1, "\n", 1);
    return (0);
}
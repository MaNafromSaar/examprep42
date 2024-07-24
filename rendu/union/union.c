#include <unistd.h>

int is_in_string(char *str, char c)
{
    while (*str)
    {
        if (*str == c)
            return (1);
        str++;
    }
    return (0);
}

void print_unique_chars(char *s1, char *s2)
{
    char res[256] = {0};
    int i = 0;

    while (*s1)
    {
        if (!is_in_string(res, *s1))
        {
            res[i++] = *s1;
            write(1, s1, 1);
        }
        s1++;
    }

    while (*s2)
    {
        if (!is_in_string(res, *s2))
        {
            res[i++] = *s2;
            write(1, s2, 1);
        }
        s2++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        print_unique_chars(argv[1], argv[2]);
        write(1, "\n", 1);
    }
    else
    {
        write(1, "\n", 1);
    }
    return (0);
}

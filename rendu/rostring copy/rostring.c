#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *s;
    char *tmp;
    int  len;
    int  tmp_len;
    char *word;
    int  space_needed = 0;
    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    s = argv[1];
    len = 0;
    while (*s == ' ' || *s > 8 && *s < 14)
        s++;
    tmp = s;
    while (*s && !(*s == ' ' || (*s > 8 && *s < 14)))
    {
        s++;
        len++;
    }
    s = tmp;
    word = (char *)malloc(sizeof(char) * (len + 1));
    word[len] = '\0';
    tmp = word;
    tmp_len = len;
    while (*s && len > 0)
    {
        *word = *s;
        word++;
        s++;
        len--;
    }
    if (*s)
    {
        while (*s == ' ' || (*s > 8 && *s < 14)) s++;
    }
    while (*s)
    {
        if (*s == ' ' || (*s > 8 && *s < 14))
        {
            while (*s == ' ' || (*s > 8 && *s < 14)) s++;
            if (!*s) break;
            write(1, " ", 1);
        }
        write(1, s, 1);
        s++;
        space_needed = 1;
    }
    if (*s == '\0' && tmp_len > 0)
    {
        if (space_needed)
        {
            write(1, " ", 1);
        }
        word = tmp;
        write(1, word, tmp_len);
    }
    write(1, "\n", 1);
}

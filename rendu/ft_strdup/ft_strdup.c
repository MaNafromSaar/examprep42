//#include <stdlib.h>

/* char    *ft_strdup(char *src)
{
    char    *dup;
    char    *start;
    int     len;

    start = src;
    while (*src)
    {
        *src++;
        len++;
    }
    src = start;
    dup = malloc(sizeof(char) * (len + 1));
    while (*src)
    {
        *dup = *src;
        src++;
        dup++;
    }
    *dup = '\0';
    return (dup);
} */

//version without malloc passes as well. another idea would be a gloabal variable
char    *ft_strdup(char *src)
{
    static char    dup[1000];
    char    *start;
    int     len;

    len = 0;
    while (src[len])
    {
        dup[len] = src[len];
        len++;
    }
    dup[len] = '\0';
    return (dup);
}
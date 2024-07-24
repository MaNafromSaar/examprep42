#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while(*s)
    {
        s++;
        i++;
    }
    return (i + 1);
}

char    *ft_strcpy(char *s1, char *s2)
{
    int len;
    char    *start;

    len = ft_strlen(s2);
    s1 = malloc(sizeof(char) * (len +1));
    start = s1;
    while (*s2 && *s2 != '\0')
    {
        *s1 = *s2;
        *s2++;
        *s1++;
    }
    *s1 = '\0';
    return (start);
}

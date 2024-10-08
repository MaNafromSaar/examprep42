int    ft_strcmp(char *s1, char *s2)
{
    if (!s1 && !s2)
        return (0);
    if (!s1)
        return (-s2[0]);
    if (!s2)
        return (s1[0]);
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

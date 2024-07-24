#include <stdlib.h>
#include <stdio.h>

char** count_words(char *s)
{
    int count;
    int len;
    char    **words;
    char    *temp;
    int parser;

    words = malloc(sizeof(char **) * 5000);
    count = 0;
    while (*s)
    {
        if (*s == ' ' || (*s > 8 && *s < 14))
            s++;
        if (*s == '\0')
            break;
        len = 0;
        if (*s >= 33 && *s <= 126 && !(*s == ' ' || (*s > 8 && *s < 14)))
            count++;
        temp = s;
        while (*s >= 33 && *s <= 126 && !(*s == ' ' || (*s > 8 && *s < 14)))
        {
            len++;
            s++;
        }
        parser = 0;
        words[count - 1] = malloc(sizeof(char) * (len + 1));
        while (parser < len)
        {
            words[count - 1][parser] = temp[parser];
            parser++;
        }
        words[count - 1][parser] = '\0';
    }
    words[count] = NULL;
    return (words);    


}

int main(int argc,char **argv)
{
    int i;
    char    **words;

    i = 0;
    words = count_words(argv[1]);
    while (words[i] != NULL)
    {
        printf("%s   ", words[i]);
        free(words[i]);
        i++;
    }
    printf("\n");
    return (0);
}
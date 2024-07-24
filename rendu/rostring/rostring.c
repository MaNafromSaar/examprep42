#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int skip_(char *str, int i)
{
    while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
        i++;
    return (i);
}

int count_word (char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        i = skip_(str, i);
        if (str[i] && str[i] != ' ' && (str[i] < 9 || str[i] > 13))
        {
            count++;
            while (str[i] && str[i] != ' ' && (str[i] < 9 || str[i] > 13))
                i++;
        }
    }
    return (count);
}

int word_len(char *str, int i)
{
    int len;

    len = 0;
    while (str[i] && str[i] != ' ' && (str[i] < 9 || str[i] > 13))
    {
        len++;
        i++;
    }
    return (len);
}

char    **get_words(char *str, int count)
{
    char    **words;
    int     i;
    int     j;
    int     k;

    words = (char **)malloc(sizeof(char *) * (count + 1));
    i = 0;
    j = 0;
    while (str[i])
    {
        i = skip_(str, i);
        if (str[i] && str[i] != ' ' && (str[i] < 9 || str[i] > 13) && j < count)
        {
            words[j] = (char *)malloc(sizeof(char) * (word_len(str, i) + 1));
            k = 0;
            while (str[i] && str[i] != ' ' && (str[i] < 9 || str[i] > 13))
            {
                words[j][k] = str[i];
                i++;
                k++;
            }
            words[j][k] = '\0';
            j++;
        }
    }
    words[j] = NULL;
    return (words);
}

int main (int argc, char **argv)
{
    int     i;
    int     j;
    char    **words;
    int     wordnum;
    char    *temp;

    wordnum = count_word(argv[1]);
    words = get_words(argv[1], wordnum);

    temp = words[0];
    j = 0;
    while (j < wordnum -1)
    {
        words[j] = words[j + 1];
        j++;
    }
    words[wordnum - 1] = temp;

    i = 0;
    while (i < wordnum)
    {
        printf("%s ", words[i]);
        i++;
    }
    free(words);
    return (0);
}

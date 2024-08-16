#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char** ft_split(const char* str, int* word_count) {
    int i, j, k, len = 0, count = 0;
    char** words = NULL;

    for (i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i]) && (i == 0 || isspace(str[i - 1]))) {
            count++;
        }
    }

    words = (char**)malloc(count * sizeof(char*));
    if (words == NULL) {
        return NULL;
    }

    for (i = 0, k = 0; i < count; i++) {
        while (isspace(str[k])) {
            k++;
        }

        len = 0;
        while (str[k + len] != '\0' && !isspace(str[k + len])) {
            len++;
        }

        words[i] = (char*)malloc((len + 1) * sizeof(char));
        if (words[i] == NULL) {
            for (j = 0; j < i; j++) {
                free(words[j]);
            }
            free(words);
            return NULL;
        }

        for (j = 0; j < len; j++) {
            words[i][j] = str[k + j];
        }
        words[i][len] = '\0';

        k += len;
    }

    *word_count = count;
    return words;
}
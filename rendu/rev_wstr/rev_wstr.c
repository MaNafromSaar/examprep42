#include <unistd.h>
#include <stdio.h>

char arr[1000];

int main(int argc, char **argv) {
    char *s;
    int i = 0;
    char *tmp;
    char *start;
    char *p;

    if (argc != 2) {
        write(1, "\n", 1);
        return (1);
    }
    s = argv[1];
    start = s;
    while (*s) // Move to the end of the string
        s++;
    s--; // Step back to the last character of the string

    while (s >= start) {
        if (*s == ' ') {
            s--; // Skip trailing spaces
            continue;
        }
        tmp = s;
        while (tmp > start && *(tmp - 1) != ' ') // Find the start of the word
            tmp--;
        // Copy the word
        for (p = tmp; p <= s; p++) { //!!! new variable to copy the word and retain the starting point of the next(previous) one!!!
            arr[i++] = *p;
        }
        s = tmp - 1; // Move s to before the start of the word
        if (s > start) {
            arr[i++] = ' '; // Add a space before the next word
        }
    }
    if (i > 0 && arr[i - 1] == ' ') { // Remove trailing space if present
        i--;
    }
    arr[i] = '\0'; // Ensure the string is null-terminated
    write(1, arr, i);
    write(1, "\n", 1);
    return (0);
}

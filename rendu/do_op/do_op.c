#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int a;
    int b;
    char    op;
    int res;

    if (argc != 4)
    {
        write(1, "\n", 1);
        return (1);
    }
    a = atoi(argv[1]);
    b = atoi(argv[3]);
    op = argv[2][0];
    if (op == '+')
    {
        res = a + b;
        printf("%i\n", res);
    }
    else if (op == '-')
    {
        res = a - b;
        printf("%i\n", res);
    }
    else if (op == '*')
    {
        res = a * b;
        printf("%i\n", res);
    }
    else if (op == '/')
    {
        res = a / b;
        printf("%i\n", res);
    }
    else if (op == '%')
    {
        res = a % b;
        printf("%i\n", res);
    }
    return (0);
}
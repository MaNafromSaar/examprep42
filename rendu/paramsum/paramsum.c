#include <unistd.h>
#include <stdlib.h>


void    printnum(int num)
{
    char    digit;
    if (num >= 10)
        printnum(num / 10);
    digit = num % 10 + '0';
    write(1, &digit, 1);
}

int main(int argc, char **argv)
{
    int num;

    num = argc - 1;
    printnum(num);
    write(1, "\n", 1);
    return (0);
}
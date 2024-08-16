#include <unistd.h>


void putnbr(unsigned int n) 
{
    if (n >= 10) 
    {
        putnbr(n / 10);
    }
    char c = n % 10 + '0';
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int     n;
    char    c;

    n = argc - 1;
    putnbr(n);
    write(1, "\n", 1);
    return (0);
}
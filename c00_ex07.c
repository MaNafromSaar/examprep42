#include <unistd.h>

void ft_putchar(int c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    int i;

    i = 0;
    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        
    }
}
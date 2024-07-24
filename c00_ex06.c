#include <unistd.h>

void ft_itoa(int nbr);
void ft_putchar(int c);

void print_comb2(void)
{
    int a;
    int b;

    a= 0;
    while (a <= 98)
    {
        b = a + 1;
        while (b <= 99)
        {
            ft_itoa(a / 10);
            ft_itoa(a % 10);
            write(1, " ", 1);
            ft_itoa(b / 10);
            ft_itoa(b % 10);
            if (a != 98)
                write(1, ", ", 1);
            b++;
            
        }
        a++;
    }
}
int main(void)
{
    print_comb2();
}

void ft_itoa(int nbr)
    nbr += 48;
    ft_putchar(nbr)

void ft_putchar(int c)
    write(1, &c, 1)
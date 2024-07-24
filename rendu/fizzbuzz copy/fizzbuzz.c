#include <unistd.h>

void putnbr(int i)
{
    char    c1;
    char    c2;
    if (i < 10)
    {
        c1 = (i +'0');
        write(1, &c1, 1);
    }
    else
    {
        c1 = i / 10 + '0';
        c2 = i % 10 + '0';
        write(1, &c1, 1);
        write(1, &c2, 1);
    }
    write(1, "\n", 1);
}

int main(void)
{
    int i;

    i = 1;
    while (i < 101)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            write(1, "fizzbuzz\n", 9);
        }
        else if (i % 3 == 0)
        {
            write(1, "fizz\n", 5);
        }
        else if (i % 5 == 0)
        {
            write(1, "buzz\n", 5);
        }
        else
        {
            putnbr(i);
        }
        i++;
    }
    return (0);
}
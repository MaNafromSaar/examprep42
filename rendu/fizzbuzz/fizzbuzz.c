#include <unistd.h>

void print_num(int n) 
{
    char c;
    if (n >= 10) 
    {
        print_num(n / 10);
    }
    c = n % 10 + '0';
    write(1, &c, 1);
}

int main(void)
{
    int i;
    char c;
    int len;

    len = 0;
    i = 1;
    while (i < 101)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            write(1, "fizzbuzz\n", 9);
            i++;
        }
        if (i % 3 == 0)
        {
            write(1, "fizz\n", 5);
            i++;
        }
        if (i % 5 == 0)
        {
            write(1, "buzz\n", 5);
            i++;
        }
        else
        {
            print_num(i);
            write(1, "\n", 1);
            i++;                
        }
    }
}

#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
    int res;

    res = 1;
    if (a == 0 || b == 0)
    {
        return (0);
    }
    if (a < b)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    res = a;
    while (1)
    {
        if (res % a == 0 && res % b == 0)
            return (res);
        res++;
    }
}

int main(void)
{
    int lcm1;
    int lcm2;
    lcm1 = lcm(9, 2);
    lcm2 = lcm(347, 33);
    printf("%i\n", lcm1);
    printf("%i\n", lcm2);
    return (0);
}
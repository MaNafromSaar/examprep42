#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void primeFactors(int n) 
{
    int i;

    i = 3;
    while (n % 2 == 0) 
    {
        printf("%d", 2);
        n = n / 2;
        if (n != 1)
            printf("*");
    }

    while (i * i <= n) 
    {
        while (n % i == 0) 
        {
            printf("%d", i);
            n = n / i;
            if (n != 1)
                printf("*");
        }
        i = i + 2;
    }

    if (n > 2)
        printf("%d", n);
}

int main(int argc, char **argv)
{
    int num;
    int factor;
    int count;
    if (argc != 2)
    {
        printf("\n");
        return (1);
    }
    num = atoi(argv[1]);
    if (num <= 1)
    {
        printf("\n");
        return (1);
    }
    primeFactors(num);
    printf("\n");
    return (0);
}
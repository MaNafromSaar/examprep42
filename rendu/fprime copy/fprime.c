#include <stdlib.h>
#include <stdio.h>

int main(int argc,char  **argv)
{
    int n;
    int i;

    i = 3;
    if (argc != 2)
    {
        printf("\n");
        return (1);
    }
    n = atoi(argv[1]);
    if (n < 2)
    {
        printf("\n");
        return (1);
    }
    while (n % 2 == 0)
    {
        printf("2");
        n = n / 2;
        if (n != 1);
            printf("*");
    }
    while (i * i < n)
    {
        while (n % i == 0)
        {
            printf("%i", i);
            n = n / i;
            if (n != 1);
                printf("*");
        }
        i = i + 2;
    }
    if (n > 2)
        printf("%i", n);
    printf("\n");
    return (0);
}
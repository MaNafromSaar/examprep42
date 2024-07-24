#include <unistd.h>

void ft_print_comb(void)
{
    char i = '0';
    char j, k;

    while (i <= '7')
    {
        j = i + 1;
        while (j <= '8')
        {
            k = j + 1;
            while (k <= '9')
            {
                char combination[] = {i, j, k};
                write(1, combination, 3);
                if (!(i == '7' && j == '8' && k == '9'))
                    write (1, ", ", 2);
                k++;
            }
            j++;
        }
        i++;
    }
}

int main(void)
{
    ft_print_comb();
    return 0;
}
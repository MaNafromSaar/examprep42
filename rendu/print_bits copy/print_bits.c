#include <unistd.h>

void	print_bits(unsigned char octet)
{
    int i;

    i = 128;
    while (i >= 1)
    {
        if (octet - i >= 0)
        {
            write(1, "1", 1);
            octet -= i;
        }
        else
        {
            write(1, "0", 1);
        }
        i /= 2;
    }
}

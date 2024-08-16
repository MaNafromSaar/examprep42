#include <unistd.h>

void print_bits(unsigned char octet)
{
    char res[8];
    int i;

    if (octet / 128 > 0)
    {
        res[0] = 1;
        octet -= 128;
        write(1, "1", 1);
    }
    else
    {
        res[0] = 0;
        write(1, "0", 1);
    }
    if (octet / 64 > 0)
    {
        res[1] = 1;
        octet -= 64;
        write(1, "1", 1);
    }
    else
    {
        res[1] = 0;
        write(1, "0", 1);
    }
    if (octet / 32 > 0)
    {
        res[2] = 1;
        octet -= 32;
        write(1, "1", 1);
    }
    else
    {
        res[2] = 0;
        write(1, "0", 1);
    }
    if (octet / 16 > 0)
    {
        res[3] = 1;
        octet -= 16;
        write(1, "1", 1);
    }
    else
    {
        res[3] = 0;
        write(1, "0", 1);
    }
    if (octet / 8 > 0)
    {
        res[4] = 1;
        octet -= 8;
        write(1, "1", 1);
    }
    else
    {
        res[4] = 0;
        write(1, "0", 1);
    }
    if (octet / 4 > 0)
    {
        res[5] = 1;
        octet -= 4;
        write(1, "1", 1);
    }
    else
    {
        res[5] = 0;
        write(1, "0", 1);
    }
    if (octet / 2 > 0)
    {
        res[6] = 1;
        octet -= 2;
        write(1, "1", 1);
    }
    else
    {
        res[6] = 0;
        write(1, "0", 1);
    }
    if (octet / 1 > 0)
    {
        res[7] = 1;
        octet -= 1;
        write(1, "1", 1);
    }
    else
    {
        res[7] = 0;
        write(1, "0", 1);
    }
}
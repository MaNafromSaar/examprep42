#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
    int result;
    int sign;
    char *base = "0123456789ABCDEF";
    char used_base[17];
    int i;
    int tmp;

    tmp = 0;
    i = 0;
    sign = 1;
    result = 0;
    while (i < str_base)
    {
        used_base[i] = base[i];
        i++;
    }
    used_base[i] = '\0';
    i = 0;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    while (*str)
    {
        i = 0;
        tmp = -1;
        while (used_base[i])
        {
            if (*str == used_base[i] || *str == used_base[i] + 32)
            {
                tmp = i;
                break;
            }
            i++;
        }
        result = result * str_base + tmp;
        str++;
    }
    return (result * sign);
}

void test_ft_atoi_base(const char *str, int str_base, int expected)
{
    int result = ft_atoi_base(str, str_base);
    if (result == expected)
        printf("Test passed: ft_atoi_base(\"%s\", %d) = %d\n", str, str_base, result);
    else
        printf("Test failed: ft_atoi_base(\"%s\", %d) = %d, expected %d\n", str, str_base, result, expected);
}

int main()
{
    // Test cases for bases up to hexadecimal
    test_ft_atoi_base("1010", 2, 10);          // Binary to decimal
    test_ft_atoi_base("A", 16, 10);            // Hexadecimal to decimal
    test_ft_atoi_base("1A", 16, 26);           // Hexadecimal to decimal
    test_ft_atoi_base("-1A", 16, -26);         // Negative hexadecimal to decimal
    test_ft_atoi_base("123", 10, 123);         // Decimal to decimal
    test_ft_atoi_base("-123", 10, -123);       // Negative decimal to decimal
    test_ft_atoi_base("7B", 16, 123);          // Hexadecimal to decimal
    test_ft_atoi_base("7b", 16, 123);          // Lowercase hexadecimal to decimal
    test_ft_atoi_base("101", 8, 65);             // Octal to decimal
    test_ft_atoi_base("0", 10, 0);             // Zero case
    test_ft_atoi_base("-0", 10, 0);            // Negative zero case

    return 0;
}

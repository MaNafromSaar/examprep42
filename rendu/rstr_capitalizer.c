#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int j;
    char c;

    i = 1;
    j = 0;
    if (argc == 1)
    {
        write(1, "\n", 1);
        return (0);
    }
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if(argv[i][j] >= 'A' && argv[i][j] <= 'Z' && !(argv[i][j + 1] == ' ' || argv[i][j +1] == '\0' || (argv[i][j + 1] > 8 && argv[i][j + 1] < 13)))
            {
                c = argv[i][j] + 32;
                write(1, &c, 1);
                j++;
            }
            else if (argv[i][j] >= 'a' && argv[i][j] <= 'z' && (argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0' || (argv[i][j + 1] > 8 && argv[i][j + 1] < 14)))
            {
                c = argv[i][j] - 32;
                write(1, &c, 1);
                j++;
            }
            else
            {
                c = argv[i][j];
                write(1, &c, 1);
                j++;
            }
            
        }
        write(1, "\n", 1);
        i++;
    }
    return (0);
}
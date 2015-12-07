#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int     atoi_base(char *str, int base)
{
    int result;
    int power;
    int uc;
    int i;

    result = 0;
    power = 1;
    uc = 0;
    i = strlen(str) - 1;
    while (i >= 0)
    {
        if (str[i] == 'A')
            uc = 10;
        else if (str[i] == 'B')
            uc = 11;
        else if (str[i] == 'C')
            uc = 12;
        else if (str[i] == 'D')
            uc = 13;
        else if (str[i] == 'E')
            uc = 14;
        else if (str[i] == 'F')
            uc = 15;
        else if (str[i] >= '0' && str[i] <= '9')
            uc = str[i] - '0';
        result = result + uc * power;
        power = power * base;
        i--;
    }
    return (result);
}

int main (int argc, char **argv)
{
    int base;

    if (argc != 3)
    {
        printf("\n");
        return (1);
    }
    base = atoi(argv[2]);
    printf("%d\n", atoi_base(argv[1], base));
    return (0);
}

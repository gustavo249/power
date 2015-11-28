#include <unistd.h>
#include <stdlib.h>

char    *g_ptr;

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_init(void)
{
    int i;

    i = 0;
    while (i <= 2049)
    {
        g_ptr[i] = 0;
        i++;
    }
}

void    ft_brainfuck(char *str)
{
    int i;
    int counter_g;
    int paranteze;

    i = 0;
    counter_g = 0;
    paranteze = 0;
    str = (char*)malloc(sizeof(str) * 2049);
    while (str[i])
    {
        if (str[i] == '+')
            g_ptr[counter_g]++;
        else if (str[i] == '-')
            g_ptr[counter_g]--;
        else if (str[i] == '>')
            counter_g++;
        else if (str[i] == '<')
            counter_g--;
        else if (str[i] == '.')
            ft_putchar(g_ptr[counter_g]);
        else if (str[i] == '[' && g_ptr[counter_g] == 0)
        {
            paranteze = 1;
            while (paranteze != 0)
            {
                if (str[i] == '[')
                    paranteze++;
                if (str[i] == ']')
                    paranteze--;
                i++;
            }
            //i++;
        }
        else if (str[i] == ']' && g_ptr[counter_g] != 0)
        {
            paranteze = 1;
            while (paranteze != 0)
            {
                if (str[i] == '[')
                    paranteze--;
                if (str[i] == ']')
                    paranteze++;
                i--;
            }
        }
        i++;
    }
}

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    ft_init();
    ft_brainfuck(argv[1]);
    write(1, "\n", 1);
    return (0);
}

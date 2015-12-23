#include "get_next_line.h"

int main ()
{
        char *s = NULL;
        int fd;
        int line;

        fd = open("42.txt", O_RDONLY);
        if (fd < 0)
                return (-1);
        while ((line = get_next_line(fd, &s)))
        {   
                ft_putstr(s);
                ft_putchar('\n');
                free(s);
        }           
        return (0);
} 

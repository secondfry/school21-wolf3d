#include "parser.h"

void    error_exit(int c)
{
    if (c == 15)
        ft_putendl("Map file does not exist\n");
    if (c == 25)
        ft_putendl("Read map error\n");
    if (c == 0)
        ft_putendl("Error filemap, map is invalid\n");
    exit(0);
}

int     parser(t_wolf *wolf, int fd)
{
    char    *x;

    x = reader(fd);
    valid(x);
    wolf->map = x;
    free(x);
    return(0);
}

char    *reader(int fd)
{
    char    buf[BUF_SIZE_PLUS_ONE];
    int     s;
    char    *str;
    char    *tmp;

    str = 0;
    while(1)
    {
        s = read(fd, buf, BUF_SIZE);
        buf[s] = 0;
        if (s < 0)
        {
            ft_putendl("Read error");
            exit(1);
        }
        tmp = ft_strnew(ft_strlen(str) + s + 1);
        ft_strcat(tmp, str);
        ft_strcat(tmp, buf);
        ft_memdel((void**)&str);
        str = tmp;
        if (s < BUF_SIZE)
            return (str);
    }
}

void    valid(char *x)
{
    int     i;

    i = 0;
    while (x[i])
    {
        if (x[i] != '0' && x[i] != '1')
        {
            free(x);
            error_exit(0);
        }
        i++;
    }
}
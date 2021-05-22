#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "defines.h"

int     parser(t_wolf *wolf, int fd);
void    error_exit(int c);
char    *reader(int fd);
void    valid(char *x);

#endif

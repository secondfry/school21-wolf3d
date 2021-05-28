#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "defines.h"
# include "get_next_line.h"

void	parser(t_wolf *wolf, int fd);
void	error_exit(int c);
char	*reader(int fd, size_t *width, size_t *height);
void	valid(char *x);

#endif

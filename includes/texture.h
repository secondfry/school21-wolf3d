#ifndef TEXTURE_H
# define TEXTURE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "defines.h"

int		*texture_load(char *filename);
void	init_textures(t_wolf *wolf);

#endif

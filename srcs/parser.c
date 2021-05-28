#include "parser.h"

void    error_exit(int c)
{
	if (c == ERR_OPEN)
		ft_putendl_fd("Can't open map.", 2);
	if (c == ERR_READ)
		ft_putendl_fd("Can't read map.", 2);
	if (c == ERR_MEM)
		ft_putendl("Memory error.");
	if (c == ERR_MAP_INVALID_CHARACTERS)
		ft_putendl_fd("Map has invalid characters.", 2);
	if (c == ERR_MAP_EMPTY)
		ft_putendl_fd("Map is empty.", 2);
	if (c == ERR_MAP_HAS_EMPTY_LINE)
		ft_putendl_fd("Map has empty line in it.", 2);
	if (c == ERR_MAP_HAS_DIFFERENT_WIDTH_LINES)
		ft_putendl_fd("Map has different width lines in it.", 2);
	if (c == ERR_MAP_INVALID_WIDTH)
		ft_putendl_fd("Map has invalid width.", 2);
	if (c == ERR_MAP_INVALID_HEIGHT)
		ft_putendl_fd("Map has invalid height.", 2);
	if (c == ERR_MAP_BLOCKED_PLAYER)
		ft_putendl_fd("Player position is blocked on the map.", 2);
	if (c == ERR_MAP_SMOL)
		ft_putendl_fd("Map is less than 3x3.", 2);
	if (c == ERR_INVALID_DEFINE)
		ft_putendl_fd("Invalid defines.", 2);
	exit(c);
}

void	parser(t_wolf *wolf, int fd)
{
	char	*map;
	size_t	width;
	size_t	height;

	map = reader(fd, &width, &height);
	if (map[width + 1] == '1')
		error_exit(ERR_MAP_BLOCKED_PLAYER);
	if (width < 3 || height < 3)
		error_exit(ERR_MAP_SMOL);
	wolf->map_width = width;
	wolf->map_height = height;
	wolf->map = map;
}

static void	check_size(char *line, t_byte gnl_res)
{
	static size_t	width;
	size_t			len;

	len = ft_strlen(line);
	if (gnl_res == 0)
	{
		if (width == 0)
			error_exit(ERR_MAP_EMPTY);
		else
			return ;
	}
	if (!len)
		error_exit(ERR_MAP_HAS_EMPTY_LINE);
	if (width == 0)
	{
		width = len;
		return ;
	}
	if (width != len)
		error_exit(ERR_MAP_HAS_DIFFERENT_WIDTH_LINES);
}

char	*reader(int fd, size_t *width, size_t *height)
{
	char	*line;
	char	*str;
	char	*tmp;
	t_byte	gnl_res;

	gnl_res = get_next_line(fd, &line);
	if (gnl_res < 1)
		error_exit(ERR_MAP_INVALID_WIDTH);
	*width = ft_atoi(line);
	if (ft_strcmp(line, ft_itoa(*width)))
		error_exit(ERR_MAP_INVALID_WIDTH);
	ft_memdel((void**)&line);
	gnl_res = get_next_line(fd, &line);
	if (gnl_res < 1)
		error_exit(ERR_MAP_INVALID_HEIGHT);
	*height = ft_atoi(line);
	if (ft_strcmp(line, ft_itoa(*height)))
		error_exit(ERR_MAP_INVALID_HEIGHT);
	ft_memdel((void**)&line);

	str = (void *)0;
	while(1)
	{
		gnl_res = get_next_line(fd, &line);
		check_size(line, gnl_res);
		if (gnl_res < 0)
			error_exit(ERR_READ);
		tmp = ft_strnew(ft_strlen(str) + ft_strlen(line) + 1);
		if (!tmp)
			error_exit(ERR_MEM);
		ft_strcat(tmp, str);
		ft_strcat(tmp, line);
		ft_memdel((void**)&str);
		ft_memdel((void**)&line);
		str = tmp;
		valid(str);
		if (gnl_res == 0)
			break;
	}
	return (str);
}

void    valid(char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '0' && map[i] != '1')
		{
			ft_memdel((void **)&map);
			error_exit(ERR_MAP_INVALID_CHARACTERS);
		}
		i++;
	}
}
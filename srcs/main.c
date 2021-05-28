/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:52:15 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/11 18:18:51 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "parser.h"

void	init_player(t_player *player)
{
	player->pos.x = 7 * 32;
	player->pos.y = 7 * 32;
	player->angle = 45.0f;
}

void	init_wolf(t_wolf *wolf)
{
	wolf->flags = FLAG_INVALIDATE_POSITION | FLAG_INVALIDATE_ROTATION
		| FLAG_REDRAW;
	wolf->map_width = 7;
	wolf->map_height = 7;
	wolf->projection_distance = WIDTH / 2 / tanf(FOV / 2 * M_PI_F / 180);
}

int		main(int argc, char *argv[])
{
	t_wolf		wolf;
	t_mlx		mlx;
	t_player	player;
	int			fd;
	int			res;

	if (argc != 2)
	{
		ft_putendl("\nUsage: \n$ ./wolf3d maps/map\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		error_exit(ERR_OPEN);
	res = read(fd, NULL, 0);
	if (res != 0)
		error_exit(ERR_READ);
	parser(&wolf, fd);
	init_player(&player);
	wolf.player = &player;
	init_mlx(&mlx);
	init_mlx_image(&mlx);
	wolf.mlx = &mlx;
	init_wolf(&wolf);
	init_textures(&wolf);
	init_mlx_hooks(&wolf);

	// input(&fdf, argv[argc - 1]);
	
	mlx_loop(mlx.mlx);
	return (0);
}

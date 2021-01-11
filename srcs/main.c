/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:52:15 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/11 13:18:10 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_player(t_player *player)
{
	player->pos.x = 64 + 32;
	player->pos.y = 64 + 32;
	player->angle = 45.0f;
}

void	init_wolf(t_wolf *wolf)
{
	wolf->flags = FLAG_INVALIDATE_POSITION | FLAG_REDRAW;
	wolf->map_width = 12;
	wolf->map_height = 12;
	wolf->map = "111111111111100000000001100000000001100000000001100000000001100000000001100000000001100000000001100000000001100000000001100000000001111111111111";
	// wolf->options = ;
}

int		main(void)
{
	t_wolf		wolf;
	t_mlx		mlx;
	t_player	player;

	init_player(&player);
	wolf.player = &player;
	init_mlx(&mlx);
	init_mlx_image(&mlx);
	wolf.mlx = &mlx;
	init_wolf(&wolf);

	// unsigned short wall_x = (player->pos_y - wall_y) / tanf(player->angle) + player->pos_x;


	
	// input(&fdf, argv[argc - 1]);
	// mlx_hook(fdf.win, EVENT_KEY_PRESS, MASK_KEY_PRESS, loop_key_hook, &fdf);
	mlx_hook(mlx.win, EVENT_CLIENT_MESSAGE, STRUCTURE_NOTIFY_MASK, loop_destroy_hook, &wolf);
	mlx_loop_hook(mlx.mlx, loop_hook, &wolf);
	mlx_loop(mlx.mlx);
	return (0);
}

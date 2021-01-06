/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:52:15 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/06 18:53:43 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_player(t_player *player)
{
	player->pos_x = 32;
	player->pos_y = 32;
}

void	init_wolf(t_wolf *wolf)
{
	wolf->flags = FLAG_INVALIDATE_POSITION | FLAG_REDRAW;
	// wolf->options = ;
}

int		main(void) {
	t_wolf		wolf;
	t_mlx		mlx;
	t_player	player;

	init_player(&player);
	wolf.player = &player;
	init_mlx(&mlx);
	init_mlx_image(&mlx);
	wolf.mlx = &mlx;
	init_wolf(&wolf);
	
	// input(&fdf, argv[argc - 1]);
	// mlx_hook(fdf.win, EVENT_KEY_PRESS, MASK_KEY_PRESS, loop_key_hook, &fdf);
	mlx_hook(mlx.win, EVENT_DESTROY_NOTIFY, MASK_STRUCTURE_NOTIFY, loop_destroy_hook, &wolf);
	mlx_loop_hook(mlx.mlx, loop_hook, &wolf);
	mlx_loop(mlx.mlx);
	return (0);
}

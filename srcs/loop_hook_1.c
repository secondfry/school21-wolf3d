/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:49:39 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/11 10:48:51 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_hook.h"

int		loop_hook(t_wolf *wolf)
{
	loop_calculate_wall_position(wolf);
	loop_before_next_update(wolf);
	return (0);
}

int		loop_destroy_hook(t_wolf *wolf)
{
	mlx_loop_end(wolf->mlx->mlx);
	clear_mlx(wolf->mlx);
	ft_putendl("Goodbye!");
	exit(0);
}

void	loop_before_next_update(t_wolf *wolf)
{
	mlx_do_sync(wolf->mlx->mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:39:04 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/11 10:49:30 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_hook.h"

void	loop_calculate_wall_position(t_wolf *wolf)
{
	if (!(wolf->flags & FLAG_INVALIDATE_POSITION))
		return ;
	wolf->player->wall.prev.x = wolf->player->pos.x - wolf->player->pos.x % 64;
	wolf->player->wall.prev.y = wolf->player->pos.y - wolf->player->pos.y % 64;
	wolf->player->wall.next.x = wolf->player->wall.prev.x + 64;
	wolf->player->wall.next.y = wolf->player->wall.prev.y + 64;
	wolf->flags -= FLAG_INVALIDATE_POSITION;
	wolf->flags |= FLAG_REDRAW;
}

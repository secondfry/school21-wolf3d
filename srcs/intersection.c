/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:03:51 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/11 17:34:21 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_byte	is_wall(t_wolf *wolf, unsigned short x, unsigned short y)
{
	x /= 64;
	y /= 64;
	if (x > wolf->map_width)
		return (2);
	if (y > wolf->map_height)
		return (2);
	return (wolf->map[wolf->map_width * y + x] == '1');
}

t_point	intersection_horizontal(
	t_wolf *wolf,
	float angle,
	unsigned short wall_y
)
{
	short			dy;
	short			dx;
	unsigned short	wall_x;
	t_byte			check;

	if ((angle < 90 + EPSILON && angle > 90 + -1 * EPSILON)
		|| (angle < -90 + EPSILON && angle > -90 + -1 * EPSILON))
		return ((t_point){0, 0});
	
	dy = wolf->player->pos.y - wall_y;
	dx = dy * tanf(angle * M_PI_F / 180);
	wall_x = dx + wolf->player->pos.x;
	check = is_wall(wolf, wall_x, wall_y); // FIXME blyat
	if (check == 1)
		return ((t_point){wall_x, wall_y});
	if (check == 2)
		return ((t_point){0, 0});
	
	while (1)
	{
		wall_y -= 64; // FIXME blyat 
		wall_x += 64 * tanf(angle * M_PI_F / 180);
		check = is_wall(wolf, wall_x, wall_y);
		if (check == 1)
			return ((t_point){wall_x, wall_y});
		if (check == 2)
			return ((t_point){0, 0});
	}
}

t_point	intersection_vertical(
	t_wolf *wolf,
	float angle,
	unsigned short wall_x
)
{
	short			dy;
	short			dx;
	unsigned short	wall_y;
	t_byte			check;

	if ((angle < EPSILON && angle > -1 * EPSILON)
		|| (angle < -180 + EPSILON && angle > 180 + -1 * EPSILON))
		return ((t_point){0, 0});

	dx = wolf->player->pos.x - wall_x;
	dy = dx / tanf(angle * M_PI_F / 180);
	wall_y = dy + wolf->player->pos.y;
	check = is_wall(wolf, wall_x, wall_y);
	if (check == 1)
		return ((t_point){wall_x, wall_y});
	if (check == 2)
		return ((t_point){0, 0});

	while (1)
	{
		wall_x += 64; // FIXME blyat
		wall_y -= 64 * tanf(angle * M_PI_F / 180);
		check = is_wall(wolf, wall_x, wall_y);
		if (check == 1)
			return ((t_point){wall_x, wall_y});
		if (check == 2)
			return ((t_point){0, 0});
	}
}
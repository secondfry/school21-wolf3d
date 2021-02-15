/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:39:04 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/22 19:08:37 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_hook.h"

void	loop_invalidate_position(t_wolf *wolf)
{
	if (!(wolf->flags & FLAG_INVALIDATE_POSITION))
		return ;
	wolf->player->wall.prev.x = (int) wolf->player->pos.x - (int) wolf->player->pos.x % 64;
	wolf->player->wall.prev.y = (int) wolf->player->pos.y - (int) wolf->player->pos.y % 64;
	wolf->player->wall.next.x = wolf->player->wall.prev.x + 64;
	wolf->player->wall.next.y = wolf->player->wall.prev.y + 64;
	wolf->flags -= FLAG_INVALIDATE_POSITION;
	wolf->flags |= FLAG_REDRAW;
}

void	loop_invalidate_rotation(t_wolf *wolf)
{
	if (!(wolf->flags & FLAG_INVALIDATE_ROTATION))
		return ;
	wolf->flags -= FLAG_INVALIDATE_ROTATION;
	wolf->flags |= FLAG_REDRAW;
}

void	draw_wall(t_wolf *wolf, t_point point, float angle, float distance, int col)
{
	short	wall_height;

	point.x = point.x;
	angle = angle + 0;
	float dangle = angle - wolf->player->angle;
	float multiplicator = cosf(dangle * M_PI_F / 180);
	float distance_corrected = distance * multiplicator;
	wall_height = WALL_HEIGHT * wolf->projection_distance / distance_corrected / 4;

	short start = (HEIGHT - wall_height) / 2;
	start = start < 0 ? 0 : start;
	short end = (HEIGHT + wall_height) / 2;
	end = end > HEIGHT ? HEIGHT : end;
	for (int v = start; v < end; v++) {
		wolf->mlx->img_data[v * wolf->mlx->size_line_int + col] = 0xff00000;
	}
	return ;
}

void	loop_redraw(t_wolf *wolf)
{
	t_point	hor;
	t_point	ver;
	float	angle;
	float	dh;
	float	dv;

	if (!(wolf->flags & FLAG_REDRAW))
		return ;
	ft_bzero(wolf->mlx->img_data, wolf->mlx->size_line_char * HEIGHT);
	wolf->flags -= FLAG_REDRAW;
	for (int col = 0; col < WIDTH; col++) {
		angle = wolf->player->angle + ((float)col) * FOV / WIDTH - FOV / 2;
		while (angle < -180)
			angle += 360;
		while (angle > 180)
			angle -= 360;
		if (angle > -90 && angle < 90)
			hor = intersection_horizontal(wolf, angle, wolf->player->wall.prev.y - 1);
		else
			hor = intersection_horizontal(wolf, angle, wolf->player->wall.next.y);
		if (angle > 0 && angle < 180)
			ver = intersection_vertical(wolf, angle, wolf->player->wall.next.x);
		else
			ver = intersection_vertical(wolf, angle, wolf->player->wall.prev.x - 1);
		dh = (hor.x - wolf->player->pos.x) / sinf(angle * M_PI_F / 180);
		dv = (ver.x - wolf->player->pos.x) / sinf(angle * M_PI_F / 180);
		if (hor.x == 0 && hor.y == 0)
			draw_wall(wolf, ver, angle, dv, col);
		if (ver.x == 0 && ver.y == 0)
			draw_wall(wolf, hor, angle, dh, col);
		dh > dv
			? draw_wall(wolf, ver, angle, dv, col)
			: draw_wall(wolf, hor, angle, dh, col);
	}
	mlx_put_image_to_window(wolf->mlx->mlx, wolf->mlx->win, wolf->mlx->img, 0, 0);
}

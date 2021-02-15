/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:59:41 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/22 18:52:06 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_hook.h"

void	loop_render_debug(t_wolf *wolf)
{
	char *str;

	mlx_string_put(wolf->mlx->mlx, wolf->mlx->win, 10, 35, 0xfffff, "Walls:");
	str = ft_itoa(wolf->player->wall.prev.x);
	mlx_string_put(wolf->mlx->mlx, wolf->mlx->win, 70, 20, 0xfffff, str);
	ft_memdel((void**)&str);
	str = ft_itoa(wolf->player->wall.prev.y);
	mlx_string_put(wolf->mlx->mlx, wolf->mlx->win, 60, 30, 0xfffff, str);
	ft_memdel((void**)&str);
	str = ft_itoa(wolf->player->wall.next.x);
	mlx_string_put(wolf->mlx->mlx, wolf->mlx->win, 90, 40, 0xfffff, str);
	ft_memdel((void**)&str);
	str = ft_itoa(wolf->player->wall.next.y);
	mlx_string_put(wolf->mlx->mlx, wolf->mlx->win, 80, 50, 0xfffff, str);
	ft_memdel((void**)&str);
	mlx_string_put(wolf->mlx->mlx, wolf->mlx->win, 10, 60, 0xfffff, "Angle:");
	str = ft_itoa(wolf->player->angle);
	mlx_string_put(wolf->mlx->mlx, wolf->mlx->win, 50, 60, 0xfffff, str);
	ft_memdel((void**)&str);
}

void	move(t_wolf *wolf, char direction)
{
	wolf->player->pos.x += direction * sinf(wolf->player->angle * M_PI_F / 180) * 5;
	wolf->player->pos.y -= direction * cosf(wolf->player->angle * M_PI_F / 180) * 5;
	wolf->flags |= FLAG_INVALIDATE_POSITION;
}

void	strafe(t_wolf *wolf, char direction)
{
	*wolf = *wolf;
	direction = direction + 0;
	wolf->flags |= FLAG_INVALIDATE_POSITION;
}

void	rotate(t_wolf *wolf, char direction)
{
	wolf->player->angle += 3 * direction;
	if (wolf->player->angle > 180)
		wolf->player->angle -= 360;
	if (wolf->player->angle < -180)
		wolf->player->angle += 360;
	wolf->flags |= FLAG_INVALIDATE_ROTATION;
}

int		loop_key_hook(int keycode, t_wolf *wolf)
{
	keycode == KEY_ESC ? loop_destroy_hook(wolf) : 0;
	keycode == KEY_W ? move(wolf, 1) : 0;
	keycode == KEY_S ? move(wolf, -1) : 0;
	keycode == KEY_Q ? strafe(wolf, -1) : 0;
	keycode == KEY_E ? strafe(wolf, 1) : 0;
	keycode == KEY_A ? rotate(wolf, -1) : 0;
	keycode == KEY_D ? rotate(wolf, 1) : 0;
	// keycode == KEY_R ? fdf->options ^= OPTION_ENABLE_ROTATION : 0;
	// keycode == KEY_F ? toggle_perspective(fdf) : 0;
	// keycode == KEY_T ? force_isometric(fdf) : 0;
	// keycode == KEY_G ? reset_rotation(fdf) : 0;
	// keycode == KEY_Z ? fdf->options ^= OPTION_ROTATION_X : 0;
	// keycode == KEY_X ? fdf->options ^= OPTION_ROTATION_Y : 0;
	// keycode == KEY_C ? fdf->options ^= OPTION_ROTATION_Z : 0;
	return (0);
}

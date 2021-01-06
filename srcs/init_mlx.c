/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:08:37 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/06 18:07:04 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	ft_ptr_check(mlx->mlx, "[main] mlx_init errored.", 0);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, TITLE);
	if (!mlx->win)
	{
		mlx_destroy_display(mlx->mlx);
		ft_ptr_check(mlx->win, "[main] mlx_new_window errored.", 1, mlx->mlx);
	}
}

void	init_mlx_image(t_mlx *mlx)
{
	int bits_per_pixel;
	int size_line;
	int endianess;

	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		ft_ptr_check(mlx->img, "[main] mlx_new_image errored.", 1, mlx->mlx);
	}
	mlx->img_data = (int *)mlx_get_data_addr(
		mlx->img, &bits_per_pixel, &size_line, &endianess);
	mlx->size_line_char = (size_t)size_line;
	mlx->size_line_int = (size_t)(size_line / 4);
}

void	clear_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	ft_memdel(&(mlx->mlx));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:09:02 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/06 17:48:35 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MLX_H
# define INIT_MLX_H

# include <stdlib.h>
# include <mlx.h>
# include "defines.h"

void	init_mlx(t_mlx *mlx);
void	init_mlx_image(t_mlx *mlx);
void	clear_mlx(t_mlx *mlx);

#endif

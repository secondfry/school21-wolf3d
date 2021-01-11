/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:50:14 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/11 10:48:40 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_HOOK_H
# define LOOP_HOOK_H

# include "defines.h"
# include "init_mlx.h"

int		loop_hook(t_wolf *wolf);
int		loop_destroy_hook(t_wolf *wolf);
void	loop_before_next_update(t_wolf *wolf);
void	loop_calculate_wall_position(t_wolf *wolf);

#endif

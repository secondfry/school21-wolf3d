/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:05:06 by oadhesiv          #+#    #+#             */
/*   Updated: 2021/01/11 16:07:13 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include <math.h>
# include "defines.h"

t_byte	is_wall(t_wolf *wolf, unsigned short x, unsigned short y);
t_point	intersection_horizontal(
	t_wolf *wolf,
	float angle,
	unsigned short wall_y
);
t_point	intersection_vertical(
	t_wolf *wolf,
	float angle,
	unsigned short wall_x
);

#endif

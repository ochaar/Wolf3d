/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:14:25 by ochaar            #+#    #+#             */
/*   Updated: 2019/02/06 15:37:27 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_intersection	set(t_intersection *i)
{
	i->x = 10000;
	i->y = 10000;
	return (*i);
}

int				wall_detection(t_obstacle *ob, t_data wolf, double alpha)
{
	t_intersection	a;
	t_intersection	b;

	a = sin(alpha * RAD) ? find_intersection_hor(alpha, wolf, 1) : set(&a);
	b = cos(alpha * RAD) ? find_intersection_ver(alpha, wolf, 1) : set(&b);
	a.dist = sqrt(pow((wolf.player.posx - a.x), 2) +
			pow((wolf.player.posy - a.y), 2));
	b.dist = sqrt(pow((wolf.player.posx - b.x), 2) +
			pow((wolf.player.posy - b.y), 2));
	if (a.dist >= 0 && b.dist >= 0)
		ob->dist = a.dist > b.dist ? b.dist : a.dist;
	else if (a.dist >= 0)
		ob->dist = a.dist;
	else if (b.dist >= 0)
		ob->dist = b.dist;
	ob->h = PRES / ob->dist * wolf.dist_player;
	ob->col = a.dist > b.dist ? (int)b.y % (int)PRES : (int)a.x % (int)PRES;
	return (1);
}

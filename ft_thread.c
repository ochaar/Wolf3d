/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:08:15 by ochaar            #+#    #+#             */
/*   Updated: 2019/02/25 11:12:17 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	*thread(t_worker_arg *arg)
{
	const t_data	*wolf = arg->wolf;
	t_obstacle		ob;
	double			alpha;
	int				x;
	int				i;

	i = 0;
	x = arg->start * 50;
	while (x < (arg->start + 1) * 50)
	{
		alpha = (wolf->player.dirx + (wolf->player.fov / 2)) -
			((wolf->player.fov / SCREEN_X) * x);
		ft_wall_detect(&ob, *wolf, alpha);
		draw(x, wolf, ob);
		while (i++ < 7)
		{
			ft_put_pixel(SCREEN_X / 2 + i, SCREEN_Y / 2, 0xFF0000, wolf);
			ft_put_pixel(SCREEN_X / 2, SCREEN_Y / 2 + i, 0xFF0000, wolf);
			ft_put_pixel(SCREEN_X / 2 - i, SCREEN_Y / 2, 0xFF0000, wolf);
			ft_put_pixel(SCREEN_X / 2, SCREEN_Y / 2 - i, 0xFF0000, wolf);
		}
		x++;
	}
	return (NULL);
}

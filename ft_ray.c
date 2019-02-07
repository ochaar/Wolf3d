/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:57:18 by ochaar            #+#    #+#             */
/*   Updated: 2019/02/06 14:15:09 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		calc_co(double xa, double ya, t_intersection *a, t_data wolf)
{
	while (((int)(a->x / PRES) < 10 && (int)(a->x / PRES) > 0) &&
		(int)(a->y / PRES) < 10 && (int)(a->y / PRES) > 0)
	{
		if (wolf.tab[(int)(a->y / PRES)][(int)(a->x / PRES)] == a->obstacle)
		{
			a->token = 1;
			return ;
		}
		a->x += xa;
		a->y += ya;
	}
}

t_intersection	find_intersection_hor(double alpha, t_data wolf, int obstacle)
{
	t_intersection	a;
	double			xa;
	double			ya;

	a.token = 0;
	if (sin(alpha * RAD) > 0)
	{
		a.y = (int)(wolf.player.posy / PRES) * PRES - 1;
		ya = -PRES;
		xa = 1;
	}
	else
	{
		a.y = (int)(wolf.player.posy / PRES) * PRES + PRES;
		ya = PRES;
		xa = -1;
	}
	a.x = wolf.player.posx + (wolf.player.posy - a.y) / tan(alpha * RAD);
	xa *= PRES / tan(alpha * RAD);
	a.obstacle = obstacle;
	calc_co(xa, ya, &a, wolf);
	return (a);
}

t_intersection	find_intersection_ver(double alpha, t_data wolf, int obstacle)
{
	t_intersection	a;
	double			xa;
	double			ya;

	a.token = 0;
	if (cos(alpha * RAD) > 0)
	{
		a.x = (int)(wolf.player.posx / PRES) * PRES + PRES;
		xa = PRES;
		ya = -1;
	}
	else
	{
		a.x = (int)(wolf.player.posx / PRES) * PRES - 1;
		xa = -PRES;
		ya = 1;
	}
	a.y = wolf.player.posy + (wolf.player.posx - a.x) * tan(alpha * RAD);
	ya *= PRES * tan(alpha * RAD);
	a.obstacle = obstacle;
	calc_co(xa, ya, &a, wolf);
	return (a);
}

int				ft_ray(t_data wolf)
{
	pthread_t	ray_thread[8];
	int			i;
	int			thr[8];

	i = 0;
	thr[0] = pthread_create(&ray_thread[0], NULL, thread1, &wolf);
	thr[1] = pthread_create(&ray_thread[1], NULL, thread2, &wolf);
	thr[2] = pthread_create(&ray_thread[2], NULL, thread3, &wolf);
	thr[3] = pthread_create(&ray_thread[3], NULL, thread4, &wolf);
	thr[4] = pthread_create(&ray_thread[4], NULL, thread5, &wolf);
	thr[5] = pthread_create(&ray_thread[5], NULL, thread6, &wolf);
	thr[6] = pthread_create(&ray_thread[6], NULL, thread7, &wolf);
	thr[7] = pthread_create(&ray_thread[7], NULL, thread8, &wolf);
	if (thr[0] || thr[1] || thr[2] || thr[3] || thr[4] || thr[5] ||
		thr[6] || thr[7])
		ft_read_error(3);
	while (++i < 8)
		pthread_join(ray_thread[i], NULL);
	mlx_put_image_to_window(wolf.mlx, wolf.win, wolf.img, 0, 0);
	return (0);
}
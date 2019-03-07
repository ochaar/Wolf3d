/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:57:18 by ochaar            #+#    #+#             */
/*   Updated: 2019/03/07 14:23:14 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	is_obst(double xa, double ya, t_inter *a, t_data wolf)
{
	while (((int)(a->x / PRES) < 30 && (int)(a->x / PRES) > 0) &&
		(int)(a->y / PRES) < 30 && (int)(a->y / PRES) > 0)
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

t_inter		ft_horizontal(double alpha, t_data wolf, int obstacle)
{
	t_inter		hor;
	double		xa;
	double		ya;

	hor.token = 0;
	if (sin(alpha * RAD) > 0)
	{
		hor.y = (int)(wolf.player.posy / PRES) * PRES - 1;
		ya = -PRES;
		xa = 1;
	}
	else
	{
		hor.y = (int)(wolf.player.posy / PRES) * PRES + PRES;
		ya = PRES;
		xa = -1;
	}
	hor.x = wolf.player.posx + (wolf.player.posy - hor.y) / tan(alpha * RAD);
	xa *= PRES / tan(alpha * RAD);
	hor.obstacle = obstacle;
	is_obst(xa, ya, &hor, wolf);
	return (hor);
}

t_inter		ft_vertical(double alpha, t_data wolf, int obstacle)
{
	t_inter		ver;
	double		xa;
	double		ya;

	ver.token = 0;
	if (cos(alpha * RAD) > 0)
	{
		ver.x = (int)(wolf.player.posx / PRES) * PRES + PRES;
		xa = PRES;
		ya = -1;
	}
	else
	{
		ver.x = (int)(wolf.player.posx / PRES) * PRES - 1;
		xa = -PRES;
		ya = 1;
	}
	ver.y = wolf.player.posy + (wolf.player.posx - ver.x) * tan(alpha * RAD);
	ya *= PRES * tan(alpha * RAD);
	ver.obstacle = obstacle;
	is_obst(xa, ya, &ver, wolf);
	return (ver);
}

int			ft_raycast(t_data wolf)
{
	pthread_t		ray_thread[16];
	t_worker_arg	args[16];
	int				i;
	int				thr[16];

	i = 0;
	while (i < 16)
	{
		args[i] = (t_worker_arg)
		{
			.wolf = &wolf,
			.start = i
		};
		thr[i] = pthread_create(&ray_thread[i], NULL, (void*)thread, args + i);
		if (thr[i])
			ft_read_error(3);
		i++;
	}
	while (i--)
		pthread_join(ray_thread[i], NULL);
	mlx_put_image_to_window(wolf.mlx, wolf.win, wolf.img, 0, 0);
	return (0);
}

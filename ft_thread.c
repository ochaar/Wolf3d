/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:08:15 by ochaar            #+#    #+#             */
/*   Updated: 2019/02/05 16:15:03 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	*thread1(void *param)
{
	t_data		*wolf;
	t_obstacle	ob;
	double		alpha;
	int			x;

	x = 0;
	wolf = (t_data *)param;
	while (x < 100)
	{
		alpha = (wolf->player.dirx + (wolf->player.fov / 2)) -
			((wolf->player.fov / SCREEN_X) * x);
		wall_detection(&ob, *wolf, alpha);
		draw(x, wolf, ob);
		x++;
	}
	return (NULL);
}

void	*thread2(void *param)
{
	t_data		*wolf;
	t_obstacle	ob;
	double		alpha;
	int			x;

	x = 100;
	wolf = (t_data *)param;
	while (x < 200)
	{
		alpha = (wolf->player.dirx + (wolf->player.fov / 2)) -
			((wolf->player.fov / SCREEN_X) * x);
		wall_detection(&ob, *wolf, alpha);
		draw(x, wolf, ob);
		x++;
	}
	return (NULL);
}

void	*thread3(void *param)
{
	t_data		*wolf;
	t_obstacle	ob;
	double		alpha;
	int			x;

	x = 200;
	wolf = (t_data *)param;
	while (x < 300)
	{
		alpha = (wolf->player.dirx + (wolf->player.fov / 2)) -
			((wolf->player.fov / SCREEN_X) * x);
		wall_detection(&ob, *wolf, alpha);
		draw(x, wolf, ob);
		x++;
	}
	return (NULL);
}

void	*thread4(void *param)
{
	t_data		*wolf;
	t_obstacle	ob;
	double		alpha;
	int			x;

	x = 300;
	wolf = (t_data *)param;
	while (x < 400)
	{
		alpha = (wolf->player.dirx + (wolf->player.fov / 2)) -
			((wolf->player.fov / SCREEN_X) * x);
		wall_detection(&ob, *wolf, alpha);
		draw(x, wolf, ob);
		x++;
	}
	return (NULL);
}

void	*thread5(void *param)
{
	t_data		*wolf;
	t_obstacle	ob;
	double		alpha;
	int			x;

	x = 400;
	wolf = (t_data *)param;
	while (x < 500)
	{
		alpha = (wolf->player.dirx + (wolf->player.fov / 2)) -
			((wolf->player.fov / SCREEN_X) * x);
		wall_detection(&ob, *wolf, alpha);
		draw(x, wolf, ob);
		x++;
	}
	return (NULL);
}

void	*thread6(void *param)
{
	t_data		*wolf;
	t_obstacle	ob;
	double		alpha;
	int			x;

	x = 500;
	wolf = (t_data *)param;
	while (x < 600)
	{
		alpha = (wolf->player.dirx + (wolf->player.fov / 2)) -
			((wolf->player.fov / SCREEN_X) * x);
		wall_detection(&ob, *wolf, alpha);
		draw(x, wolf, ob);
		x++;
	}
	return (NULL);
}

void	*thread7(void *param)
{
	t_data		*wolf;
	t_obstacle	ob;
	double		alpha;
	int			x;

	x = 600;
	wolf = (t_data *)param;
	while (x < 700)
	{
		alpha = (wolf->player.dirx + (wolf->player.fov / 2)) -
			((wolf->player.fov / SCREEN_X) * x);
		wall_detection(&ob, *wolf, alpha);
		draw(x, wolf, ob);
		x++;
	}
	return (NULL);
}

void	*thread8(void *param)
{
	t_data		*wolf;
	t_obstacle	ob;
	double		alpha;
	int			x;

	x = 700;
	wolf = (t_data *)param;
	while (x < 800)
	{
		alpha = (wolf->player.dirx + (wolf->player.fov / 2)) -
			((wolf->player.fov / SCREEN_X) * x);
		wall_detection(&ob, *wolf, alpha);
		draw(x, wolf, ob);
		x++;
	}
	return (NULL);
}

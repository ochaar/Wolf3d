/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:26:10 by ochaar            #+#    #+#             */
/*   Updated: 2019/03/16 15:20:21 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_walk_f(t_data *wolf, double angle)
{
	if (cos(angle) > 0)
	{
		if (wolf->tab[((int)wolf->player.posy / (int)PRES)]
			[((int)(wolf->player.posx + 50) / (int)PRES)] != 1)
			wolf->player.posx += PRES / 8 * wolf->speed * fabs(cos(angle));
	}
	else if (cos(angle) < 0)
	{
		if (wolf->tab[((int)wolf->player.posy / (int)PRES)]
			[((int)(wolf->player.posx - 50) / (int)PRES)] != 1)
			wolf->player.posx += -1 * PRES / 8 * wolf->speed * fabs(cos(angle));
	}
	if (sin(angle) > 0)
	{
		if (wolf->tab[((int)(wolf->player.posy - 50) / (int)PRES)]
			[((int)wolf->player.posx / (int)PRES)] != 1)
			wolf->player.posy += -1 * PRES / 8 * wolf->speed * fabs(sin(angle));
	}
	else if (sin(angle) < 0)
	{
		if (wolf->tab[((int)(wolf->player.posy + 50) / (int)PRES)]
			[((int)wolf->player.posx / (int)PRES)] != 1)
			wolf->player.posy += PRES / 8 * wolf->speed * fabs(sin(angle));
	}
}

void	ft_walk_b(t_data *wolf, double angle)
{
	if (cos(angle) > 0)
	{
		if (wolf->tab[((int)wolf->player.posy / (int)PRES)]
			[((int)(wolf->player.posx - 50) / (int)PRES)] != 1)
			wolf->player.posx -= PRES / 8 * wolf->speed * fabs(cos(angle));
	}
	else if (cos(angle) < 0)
	{
		if (wolf->tab[((int)wolf->player.posy / (int)PRES)]
			[((int)(wolf->player.posx + 50) / (int)PRES)] != 1)
			wolf->player.posx -= -1 * PRES / 8 * wolf->speed * fabs(cos(angle));
	}
	if (sin(angle) > 0)
	{
		if (wolf->tab[((int)(wolf->player.posy + 50) / (int)PRES)]
			[((int)wolf->player.posx / (int)PRES)] != 1)
			wolf->player.posy -= -1 * PRES / 8 * wolf->speed * fabs(sin(angle));
	}
	else if (sin(angle) < 0)
	{
		if (wolf->tab[((int)(wolf->player.posy - 50) / (int)PRES)]
			[((int)wolf->player.posx / (int)PRES)] != 1)
			wolf->player.posy -= PRES / 8 * wolf->speed * fabs(sin(angle));
	}
}

void	find_next_tp(t_data *wolf)
{
	int i;
	int j;

	i = 0;
	while (i < 30)
	{
		j = 0;
		while (j < 30)
		{
			if (wolf->tab[j][i] == 3 && (int)(wolf->player.posx / PRES) != i
				&& (int)(wolf->player.posy / PRES) != j)
			{
				wolf->player.posx = (i + 0.2) * PRES;
				wolf->player.posy = (j + 0.5) * PRES;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_move(int key, t_data *wolf)
{
	int tp;

	if (wolf->tab[((int)wolf->player.posy / (int)PRES)][((int)wolf->player.posx
		/ (int)PRES)] != 3)
		tp = 1;
	if (key == KEY_RIGHT)
		wolf->player.dirx -= 5;
	if (key == KEY_LEFT)
		wolf->player.dirx += 5;
	if (key == 257)
		wolf->speed += wolf->speed == 1 ? 1 : -1;
	if (key == KEY_DOWN)
		ft_walk_b(wolf, wolf->player.dirx * RAD);
	if (key == KEY_UP)
		ft_walk_f(wolf, wolf->player.dirx * RAD);
	if (wolf->tab[((int)wolf->player.posy / (int)PRES)][((int)wolf->player.posx
		/ (int)PRES)] == 3 && tp == 1)
	{
		find_next_tp(wolf);
		tp = 0;
	}
}

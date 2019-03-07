/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:26:10 by ochaar            #+#    #+#             */
/*   Updated: 2019/03/07 15:20:51 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_walk_f(t_data *wolf, double angle)
{
	if (cos(angle) > 0)
		wolf->player.posx += PRES / 8 * wolf->speed * fabs(cos(angle));
	else if (cos(angle) < 0)
		wolf->player.posx += -1 * PRES / 8 * wolf->speed * fabs(cos(angle));
	if (sin(angle) > 0)
		wolf->player.posy += -1 * PRES / 8 * wolf->speed * fabs(sin(angle));
	else if (sin(angle) < 0)
		wolf->player.posy += PRES / 8 * wolf->speed * fabs(sin(angle));
}

void	ft_walk_b(t_data *wolf, double angle)
{
	if (cos(angle) > 0)
		wolf->player.posx -= PRES / 8 * wolf->speed * fabs(cos(angle));
	else if (cos(angle) < 0)
		wolf->player.posx -= -1 * PRES / 8 * wolf->speed * fabs(cos(angle));
	if (sin(angle) > 0)
		wolf->player.posy -= -1 * PRES / 8 * wolf->speed * fabs(sin(angle));
	else if (sin(angle) < 0)
		wolf->player.posy -= PRES / 8 * wolf->speed * fabs(sin(angle));
}

void	ft_move(int key, t_data *wolf)
{
	double	prevx;
	double	prevy;

	prevx = wolf->player.posx;
	prevy = wolf->player.posy;
	if (key == KEY_RIGHT)
		wolf->player.dirx -= 10;
	if (key == KEY_LEFT)
		wolf->player.dirx += 10;
	if (key == 257)
		wolf->speed += wolf->speed == 1 ? 1 : -1;
	if (key == KEY_DOWN)
		ft_walk_b(wolf, wolf->player.dirx * RAD);
	if (key == KEY_UP)
		ft_walk_f(wolf, wolf->player.dirx * RAD);
	if (wolf->tab[((int)wolf->player.posy / (int)PRES)][((int)wolf->player.posx
		/ (int)PRES)] == 1)
	{
		wolf->player.posx = prevx;
		wolf->player.posy = prevy;
	}
}

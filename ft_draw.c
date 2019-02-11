/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:59:33 by ochaar            #+#    #+#             */
/*   Updated: 2019/02/11 15:08:18 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_put_pixel(int x, int y, int color, const t_data *wolf)
{
	int	i;

	i = x * 4 + SCREEN_X * 4 * y;
	wolf->str[i] = color & 0xff;
	wolf->str[++i] = (color >> 8) & 0xff;
	wolf->str[++i] = (color >> 16) & 0xff;
}

void	draw(int x, const t_data *wolf, t_obstacle ob)
{
	int	y;

	y = SCREEN_Y / 2 - ob.h / 2;
	while (y < SCREEN_Y / 2 + ob.h / 2 && y < SCREEN_Y - 1)
	{
		if (y < SCREEN_Y && y >= 0)
			ft_put_pixel(x, y, 0x00FFFF, wolf);
		y++;
	}
	y--;
	while (++y < SCREEN_Y)
		ft_put_pixel(x, y, 0x708090, wolf);
}

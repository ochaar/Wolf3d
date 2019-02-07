/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:59:33 by ochaar            #+#    #+#             */
/*   Updated: 2019/02/06 11:29:36 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*void		put_pixel(int x, int y, unsigned int color, t_data *wolf)
{
	int i;

	if ((x >= 0 && x < SCREEN_X) && (y >= 0 && y < SCREEN_Y))
	{
		i = y * wolf->sizel + x * 4;
		wolf->str[i] = color & 0xff;
		wolf->str[++i] = color >> 8 & 0xff;
		wolf->str[++i] = color >> 16;
	}
}

void	ft_draw(t_data *wolf, t_env e, int x)
{
	int i;

	i = -1;
	while (++i < e.drawStart)
		put_pixel(x, i, 0x808080, wolf);
	i--;
	//printf("draw=%d i=%d\n", e.drawEnd, i);
	while (++i <= e.drawEnd && i < SCREEN_Y)
		put_pixel(x, i, 0xFF00FF, wolf);
	i--;
	while (++i < SCREEN_Y)
		put_pixel(x, i, 0x000000, wolf);
}*/
void	put_pixel_image(int x, int y, int color, t_data *wolf)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = color & 0xff;
	wolf->str[(x * 4) + ((int)SCREEN_X * 4 * y)] = b;
	wolf->str[(x * 4) + ((int)SCREEN_X * 4 * y) + 1] = g;
	wolf->str[(x * 4) + ((int)SCREEN_X * 4 * y) + 2] = r;
}

void	draw(int x, t_data *wolf, t_obstacle ob)
{
	int				y;

	y = SCREEN_Y / 2 - ob.h / 2;
	while (y < SCREEN_Y / 2 + ob.h / 2 && y < SCREEN_Y - 1)
	{
		if (y < SCREEN_Y && y >= 0)
			put_pixel_image(x, y, 0x00FFFF, wolf);
		y++;
	}
	y--;
	while (++y < SCREEN_Y)
		put_pixel_image(x, y, 0xFF0000, wolf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:59:33 by ochaar            #+#    #+#             */
/*   Updated: 2019/03/08 17:41:23 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_put_pixel(int x, int y, int color, const t_data *wolf)
{
	int	i;

	i = x * 4 + wolf->sizel * y;
	wolf->str[i] = color & 0xff;
	wolf->str[++i] = (color >> 8) & 0xff;
	wolf->str[++i] = (color >> 16) & 0xff;
}

int		get_text(int y, t_data wolf, t_obstacle ob)
{
	int color;

	y = (double)y / (double)ob.h * PRES;
	color = wolf.tex[ob.ori].str[(ob.col * 4) + (wolf.tex[ob.ori].sizel * y)];
	color += wolf.tex[ob.ori].str[(ob.col * 4) + (wolf.tex[ob.ori].sizel * y)
		+ 1] * 256;
	color += (wolf.tex[ob.ori].str[(ob.col * 4) + (wolf.tex[ob.ori].sizel * y)
		+ 2] * 256) * 256;
	return (color);
}

void	draw(int x, const t_data *wolf, t_obstacle ob)
{
	int				y;
	int				yim;
	unsigned int	color;

	y = SCREEN_Y / 2 - (ob.h / 2);
	yim = 0;
	ft_print_sky(x, wolf);
	while (y < SCREEN_Y / 2 + ob.h / 2 && y < SCREEN_Y - 1)
	{
		if (y >= 0 && y < SCREEN_Y)
		{
			color = get_text(yim, *wolf, ob);
			ft_put_pixel(x, y, color, wolf);
		}
		y++;
		yim++;
	}
	y--;
	while (++y < SCREEN_Y)
		ft_put_pixel(x, y, 0x708090, wolf);
}

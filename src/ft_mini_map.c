/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:52:45 by ochaar            #+#    #+#             */
/*   Updated: 2019/03/04 15:15:33 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_print_map(int i, int j, int color, t_data wolf)
{
	ft_put_pixel(SCREEN_X - 100 + (i * 3), 10 + (j * 3), color, &wolf);
	ft_put_pixel(SCREEN_X - 101 + (i * 3), 10 + (j * 3), color, &wolf);
	ft_put_pixel(SCREEN_X - 102 + (i * 3), 10 + (j * 3), color, &wolf);
	ft_put_pixel(SCREEN_X - 100 + (i * 3), 11 + (j * 3), color, &wolf);
	ft_put_pixel(SCREEN_X - 101 + (i * 3), 11 + (j * 3), color, &wolf);
	ft_put_pixel(SCREEN_X - 102 + (i * 3), 11 + (j * 3), color, &wolf);
	ft_put_pixel(SCREEN_X - 100 + (i * 3), 12 + (j * 3), color, &wolf);
	ft_put_pixel(SCREEN_X - 101 + (i * 3), 12 + (j * 3), color, &wolf);
	ft_put_pixel(SCREEN_X - 102 + (i * 3), 12 + (j * 3), color, &wolf);
}

void		ft_mini_map(t_data wolf)
{
	int i;
	int j;

	i = 0;
	while (i < 30)
	{
		j = 0;
		while (j < 30)
		{
			if (wolf.tab[j][i] == 1)
				ft_print_map(i, j, 0x0, wolf);
			else
				ft_print_map(i, j, 0xFFFFFF, wolf);
			if ((int)(wolf.player.posy / PRES) == j && (int)(wolf.player.posx
				/ PRES) == i)
				ft_print_map(i, j, 0xFF0000, wolf);
			j++;
		}
		i++;
	}
}

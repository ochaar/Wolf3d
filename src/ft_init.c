/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:17:59 by ochaar            #+#    #+#             */
/*   Updated: 2019/03/08 16:51:43 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_check_spawn(t_data *wolf)
{
	int i;
	int j;
	int verif;

	i = 0;
	verif = 0;
	while (i < 30)
	{
		j = 0;
		while (j < 30)
		{
			if (wolf->tab[i][j] == 2 && verif == 0)
			{
				wolf->player.start_x = j;
				wolf->player.start_y = i;
				verif = 1;
			}
			else if (wolf->tab[i][j] == 2 && verif == 1)
				ft_map_error(3, 0);
			j++;
		}
		i++;
	}
	if (verif == 0)
		ft_map_error(3, 0);
}

void	ft_init(t_data *wolf)
{
	int i;

	i = 0;
	ft_check_spawn(wolf);
	wolf->player.dirx = 0;
	wolf->player.diry = 0;
	wolf->player.fov = 60;
	wolf->player.posx = PRES * wolf->player.start_x;
	wolf->player.posy = PRES * wolf->player.start_y;
	wolf->menu = 1;
	wolf->enter = 0;
	wolf->speed = 1;
	wolf->proj_dist_player = (SCREEN_X / 2) / tan((wolf->player.fov / 2) * RAD);
	wolf->mlx = mlx_init();
	wolf->win = mlx_new_window(wolf->mlx, SCREEN_X, SCREEN_Y, "WOLF3D");
	wolf->img = mlx_new_image(wolf->mlx, SCREEN_X, SCREEN_Y);
	wolf->str = mlx_get_data_addr(wolf->img, &i, &wolf->sizel, &i);
}

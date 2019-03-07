/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:52:50 by ochaar            #+#    #+#             */
/*   Updated: 2019/03/07 14:43:16 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	change_menu(t_data *wolf)
{
	if (wolf->enter == 0)
	{
		mlx_string_put(wolf->mlx, wolf->win, 350, 400, 0xFF0000, "NEW GAME");
		mlx_string_put(wolf->mlx, wolf->win, 350, 500, 0xEEEEEE, "RESUME");
		mlx_string_put(wolf->mlx, wolf->win, 350, 600, 0xEEEEEE, "QUIT");
	}
	if (wolf->enter == 1)
	{
		mlx_string_put(wolf->mlx, wolf->win, 350, 600, 0xEEEEEE, "QUIT");
		mlx_string_put(wolf->mlx, wolf->win, 350, 400, 0xEEEEEE, "NEW GAME");
		mlx_string_put(wolf->mlx, wolf->win, 350, 500, 0xFF0000, "RESUME");
	}
	if (wolf->enter == 2)
	{
		mlx_string_put(wolf->mlx, wolf->win, 350, 600, 0xFF0000, "QUIT");
		mlx_string_put(wolf->mlx, wolf->win, 350, 400, 0xEEEEEE, "NEW GAME");
		mlx_string_put(wolf->mlx, wolf->win, 350, 500, 0xEEEEEE, "RESUME");
	}
}

void	hook_key_menu(int key, t_data *wolf)
{
	if (key == 125)
		wolf->enter++;
	if (key == 126)
		wolf->enter--;
	if (wolf->enter < 0)
		wolf->enter = 0;
	else if (wolf->enter > 2)
		wolf->enter = 2;
	change_menu(wolf);
	if (key == 36)
	{
		if (wolf->enter == 0)
		{
			wolf->player.dirx = 1;
			wolf->player.diry = 0;
			wolf->player.posx = PRES * wolf->player.start_x;
			wolf->player.posy = PRES * wolf->player.start_y;
			ft_raycast(*wolf);
		}
		else if (wolf->enter == 1)
			ft_raycast(*wolf);
		else
			exit(0);
		wolf->menu = 0;
	}
}

int		menu(t_data *wolf)
{
	mlx_string_put(wolf->mlx, wolf->win, 350, 400, 0xFF0000, "NEW GAME");
	mlx_string_put(wolf->mlx, wolf->win, 350, 500, 0xEEEEEE, "RESUME");
	mlx_string_put(wolf->mlx, wolf->win, 350, 600, 0xEEEEEE, "QUIT");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:19:44 by ochaar            #+#    #+#             */
/*   Updated: 2019/03/15 17:06:13 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	deal_key(int key, void *param)
{
	t_data	*wolf;

	wolf = (t_data*)param;
	if (key == KEY_ESC)
		exit(0);
	if (wolf->menu == 1)
		hook_key_menu(key, wolf);
	else if (wolf->menu == 0 && key == 48)
	{
		mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->tex[5].img, 0, 0);
		menu(wolf);
		hook_key_menu(key, wolf);
		wolf->menu = 1;
	}
	else
	{
		ft_move(key, wolf);
		mlx_destroy_image(wolf->mlx, wolf->img);
		wolf->img = mlx_new_image(wolf->mlx, SCREEN_X, SCREEN_Y);
		wolf->str = mlx_get_data_addr(wolf->img, &key, &wolf->sizel, &key);
		ft_raycast(*wolf);
	}
	return (0);
}

int			ft_close(void)
{
	exit(0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_data	wolf;

	if (argc == 2)
	{
		wolf.tab = ft_verif(argv[1]);
		ft_init(&wolf);
		ft_load_wall(&wolf);
		menu(&wolf);
		mlx_hook(wolf.win, 2, 0, deal_key, &wolf);
		mlx_hook(wolf.win, 17, 0, ft_close, &wolf);
		mlx_loop(wolf.mlx);
	}
	else
		ft_read_error(0);
	return (0);
}

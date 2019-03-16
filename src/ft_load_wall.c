/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:50:46 by ochaar            #+#    #+#             */
/*   Updated: 2019/03/16 15:20:43 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_load_other(t_data *wolf)
{
	int a;
	int i;

	wolf->tex[4].img = mlx_xpm_file_to_image(wolf->mlx, "./xpm/sky.XPM",
		&a, &a);
	wolf->tex[5].img = mlx_xpm_file_to_image(wolf->mlx, "./xpm/menu.XPM",
		&a, &a);
	wolf->tex[6].img = mlx_xpm_file_to_image(wolf->mlx, "./xpm/gun.XPM",
		&a, &a);
	if (!(wolf->tex[4].img && wolf->tex[5].img && wolf->tex[6].img))
		ft_read_error(4);
	wolf->tex[4].str = mlx_get_data_addr(wolf->tex[4].img, &i,
		&wolf->tex[4].sizel, &i);
	wolf->tex[5].str = mlx_get_data_addr(wolf->tex[5].img, &i,
		&wolf->tex[5].sizel, &i);
	wolf->tex[6].str = mlx_get_data_addr(wolf->tex[6].img, &i,
		&wolf->tex[6].sizel, &i);
}

void	ft_load_wall(t_data *wolf)
{
	int a;
	int i;

	wolf->tex[0].img = mlx_xpm_file_to_image(wolf->mlx, "./xpm/roche.XPM",
		&a, &a);
	wolf->tex[1].img = mlx_xpm_file_to_image(wolf->mlx, "./xpm/brick.XPM",
		&a, &a);
	wolf->tex[2].img = mlx_xpm_file_to_image(wolf->mlx, "./xpm/pierre.XPM",
		&a, &a);
	wolf->tex[3].img = mlx_xpm_file_to_image(wolf->mlx, "./xpm/fiss.XPM",
		&a, &a);
	if (!(wolf->tex[0].img && wolf->tex[1].img && wolf->tex[2].img
		&& wolf->tex[3].img))
		ft_read_error(4);
	wolf->tex[0].str = mlx_get_data_addr(wolf->tex[0].img, &i,
		&wolf->tex[0].sizel, &i);
	wolf->tex[1].str = mlx_get_data_addr(wolf->tex[1].img, &i,
		&wolf->tex[1].sizel, &i);
	wolf->tex[2].str = mlx_get_data_addr(wolf->tex[2].img, &i,
		&wolf->tex[2].sizel, &i);
	wolf->tex[3].str = mlx_get_data_addr(wolf->tex[3].img, &i,
		&wolf->tex[3].sizel, &i);
	ft_load_other(wolf);
}

void	ft_print_sky(int x, const t_data *wolf)
{
	int				y;
	unsigned int	color;

	y = 0;
	while (y < SCREEN_Y / 2)
	{
		color = wolf->tex[4].str[(x * 4) + (wolf->tex[4].sizel * y)];
		color += wolf->tex[4].str[(x * 4) + (wolf->tex[4].sizel * y) + 1] * 256;
		color += (wolf->tex[4].str[(x * 4) + (wolf->tex[4].sizel * y) + 2]
			* 256) * 256;
		ft_put_pixel(x, y, color, wolf);
		y++;
	}
}

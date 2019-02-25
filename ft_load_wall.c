/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:50:46 by ochaar            #+#    #+#             */
/*   Updated: 2019/02/25 15:35:43 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_load_wall(t_data *wolf)
{
	int a;
	int b;
	int i;

	wolf->tex[0].img = mlx_xpm_file_to_image(wolf->mlx, "./bois.XPM", &a, &b);
	wolf->tex[0].str = mlx_get_data_addr(wolf->tex[0].img, &i,
		&wolf->tex[0].sizel, &i);
	wolf->tex[1].img = mlx_xpm_file_to_image(wolf->mlx, "./brick.XPM", &a, &b);
	wolf->tex[1].str = mlx_get_data_addr(wolf->tex[1].img, &i,
		&wolf->tex[1].sizel, &i);
	wolf->tex[2].img = mlx_xpm_file_to_image(wolf->mlx, "./pierre.XPM", &a, &b);
	wolf->tex[2].str = mlx_get_data_addr(wolf->tex[2].img, &i,
		&wolf->tex[2].sizel, &i);
	wolf->tex[3].img = mlx_xpm_file_to_image(wolf->mlx, "./fiss.XPM", &a, &b);
	wolf->tex[3].str = mlx_get_data_addr(wolf->tex[3].img, &i,
		&wolf->tex[3].sizel, &i);
}

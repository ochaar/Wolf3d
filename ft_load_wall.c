/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:50:46 by ochaar            #+#    #+#             */
/*   Updated: 2019/02/11 13:54:25 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_load_wall(t_data	*wolf)
{
	int a;
	int b;
	int i;

	wolf->img_w = mlx_xpm_file_to_image(wolf->mlx, "./bois.XPM", &a, &b);
	wolf->str_w = mlx_get_data_addr(wolf->img_w, &i, &wolf->size_w, &i);
}
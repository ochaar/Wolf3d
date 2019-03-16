/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:54:00 by ochaar            #+#    #+#             */
/*   Updated: 2019/03/13 11:37:44 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_map_error(int x, int line)
{
	if (x == 0)
		ft_putstr("Map error: this is not a 30x30 map\n");
	if (x == 1)
	{
		ft_putstr("Error line ");
		ft_putnbr(line);
		ft_putstr("\n");
	}
	if (x == 2)
		ft_putstr("Borders are not full of walls\n");
	if (x == 3)
		ft_putstr("Spawn error\n");
	exit(0);
}

void	ft_read_error(int x)
{
	if (x == 0)
		ft_putstr("usage : ./wolf3d <filename>\n");
	if (x == 1)
		ft_putstr("Malloc error\n");
	if (x == 2)
		ft_putstr("Open error\n");
	if (x == 3)
		ft_putstr("Thread error\n");
	if (x == 4)
		ft_putstr("Textures error\n");
	if (x == 5)
		ft_putstr("Read error\n");
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:19:44 by ochaar            #+#    #+#             */
/*   Updated: 2019/02/25 14:39:38 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "wolf.h"

void		ft_walk_f(t_data *wolf, double angle)
{
	if (cos(angle) > 0)
		wolf->player.posx += PRES * fabs(cos(angle));
	else if (cos(angle) < 0)
		wolf->player.posx += -1 * PRES * fabs(cos(angle));
	if (sin(angle) > 0)
		wolf->player.posy += -1 * PRES * fabs(sin(angle));
	else if (sin(angle) < 0)
		wolf->player.posy += PRES * fabs(sin(angle));
}

void		ft_walk_b(t_data *wolf, double angle)
{
	if (cos(angle) > 0)
		wolf->player.posx -= PRES * fabs(cos(angle));
	else if (cos(angle) < 0)
		wolf->player.posx -= -1 * PRES * fabs(cos(angle));
	if (sin(angle) > 0)
		wolf->player.posy -= -1 * PRES * fabs(sin(angle));
	else if (sin(angle) < 0)
		wolf->player.posy -= PRES * fabs(sin(angle));
}

static int	deal_key(int key, t_data *wolf)
{
	double prevx;
	double prevy;

	prevx = wolf->player.posx;
	prevy = wolf->player.posy;
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_RIGHT)
		wolf->player.dirx -= 10;
	if (key == KEY_LEFT)
		wolf->player.dirx += 10;
	if (key == KEY_DOWN)
		ft_walk_b(wolf, wolf->player.dirx * RAD);
	if (key == KEY_UP)
		ft_walk_f(wolf, wolf->player.dirx * RAD);
	if (wolf->tab[((int)wolf->player.posy / (int)PRES)][((int)wolf->player.posx
		/ (int)PRES)] == 1)
	{
		wolf->player.posx = prevx;
		wolf->player.posy = prevy;
	}
	mlx_destroy_image(wolf->mlx, wolf->img);
	wolf->img = mlx_new_image(wolf->mlx, SCREEN_X, SCREEN_Y);
	wolf->str = mlx_get_data_addr(wolf->img, &key, &wolf->sizel, &key);
	ft_raycast(*wolf);
	return (0);
}

int			main(int argc, char **argv)
{
	t_data	wolf;
	int		i;

	i = PRES;
	if (argc == 2)
	{
		wolf.tab = ft_verif(argv[1]);
		ft_init(&wolf);
		wolf.str = mlx_get_data_addr(wolf.img, &i, &wolf.sizel, &i);
		ft_load_wall(&wolf);
		ft_raycast(wolf);
		mlx_key_hook(wolf.win, deal_key, &wolf);
		mlx_loop(wolf.mlx);
	}
	else
		ft_read_error(0);
	return (0);
}

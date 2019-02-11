/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:19:44 by ochaar            #+#    #+#             */
/*   Updated: 2019/02/11 13:23:38 by ochaar           ###   ########.fr       */
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
	mlx_destroy_image(wolf->mlx, wolf->img);
	wolf->img = mlx_new_image(wolf->mlx, SCREEN_X, SCREEN_Y);
	wolf->str = mlx_get_data_addr(wolf->img, &key, &wolf->sizel, &key);
	ft_raycast(*wolf);
	return (0);
}

/*static int	mouse_hook(int button, int x, int y, t_data *wolf)
{
	if (button == 4 || button == 1)
	{
		wolf->xmouse = x / (double)wolf->zoom - (SCREEN_X
		/ (double)(wolf->zoom * 2) + wolf->position_x) + wolf->xmouse;
		wolf->ymouse = y / (double)wolf->zoom - (SCREEN_Y
		/ (double)(wolf->zoom * 2) + wolf->position_y) + wolf->ymouse;
		wolf->position_y = 0;
		wolf->position_x = 0;
		wolf->zoom = wolf->zoom * 2;
	}
	if (button == PRES || button == 2)
		wolf->zoom = wolf->zoom * 0.PRES;
	render(wolf);
	return (0);
}*/

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
		ft_raycast(wolf);
		mlx_key_hook(wolf.win, deal_key, &wolf);
		//mlx_mouse_hook(wolf.win, mouse_hook, &wolf);
		//mlx_hook(wolf.win, 6, (1L << 6), funct, &wolf);
		if (wolf.win == NULL)
			exit(0);
		mlx_loop(wolf.mlx);
	}
	else
		ft_read_error(0);
	return (0);
}

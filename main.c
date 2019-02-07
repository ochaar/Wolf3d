/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:19:44 by ochaar            #+#    #+#             */
/*   Updated: 2019/02/05 17:43:24 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "wolf.h"

static int	deal_key(int key, t_data *wolf)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_RIGHT)
		wolf->player.dirx -= 3;
	if (key == KEY_LEFT)
		wolf->player.dirx += 3;
	if (key == KEY_DOWN)
		wolf->player.posx -= 3;
	if (key == KEY_UP)
		wolf->player.posx += 3;
	mlx_destroy_image(wolf->mlx, wolf->img);
	wolf->img = mlx_new_image(wolf->mlx, SCREEN_X, SCREEN_Y);
	wolf->str = mlx_get_data_addr(wolf->img, &key, &wolf->sizel, &key);
	ft_ray(*wolf);
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
	if (button == 5 || button == 2)
		wolf->zoom = wolf->zoom * 0.5;
	render(wolf);
	return (0);
}*/

int			main(int argc, char **argv)
{
	t_data	wolf;
	//t_env	e;
	t_obstacle	ob;
	int		i;

	i = 5;
	if (argc == 2)
	{
		wolf.tab = ft_verif(argv[1]);
		ft_init(&wolf, &ob);
		wolf.str = mlx_get_data_addr(wolf.img, &i, &wolf.sizel, &i);
		//raycasting(&wolf, &e, wolf.tab);
		ft_ray(wolf);
		mlx_key_hook(wolf.win, deal_key, &wolf);
		//mlx_mouse_hook(wolf.win, mouse_hook, &wolf);
		//mlx_hook(wolf.win, 6, (1L << 6), funct, &wolf);
		mlx_loop(wolf.mlx);
	}
	else
		ft_read_error(0);
	return (0);
}

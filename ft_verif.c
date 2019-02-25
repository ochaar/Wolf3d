/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:42:32 by ochaar            #+#    #+#             */
/*   Updated: 2019/02/25 14:12:14 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_count(char *line)
{
	int i;
	int len;
	int nb;

	i = 0;
	nb = 0;
	len = ft_strlen(line);
	if (len > 1000)
		return (0);
	while (i < len)
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
		{
			if (ft_isdigit(line[i]) == 1)
			{
				i++;
				nb++;
			}
		}
	}
	return (nb);
}

void	ft_check_walls(t_map *data)
{
	int		i;

	i = 0;
	while (i < data->nb_num)
	{
		if (data->tab[0][i] != 1 || data->tab[i][0] != 1)
			ft_map_error(2);
		else if (data->tab[29][i] != 1 || data->tab[i][29] != 1)
			ft_map_error(2);
		i++;
	}
}

void	read_data(char *file, t_map *data)
{
	char	**dst;
	char	*line;
	int		fd;

	data->i = 0;
	fd = open(file, O_RDONLY);
	if (!(data->tab = (int**)malloc(sizeof(int*) * data->nb_lines)))
		ft_read_error(1);
	while (data->i < data->nb_lines)
	{
		data->j = 0;
		get_next_line(fd, &line);
		dst = ft_strsplit(line, ' ');
		if (!(data->tab[data->i] = (int*)malloc(sizeof(int) * data->nb_num)))
			ft_read_error(1);
		while (dst[data->j])
		{
			data->tab[data->i][data->j] = ft_atoi(dst[data->j]);
			data->j++;
		}
		ft_free_char(dst);
		free(line);
		data->i++;
	}
	close(fd);
}

int		**ft_verif(char *file)
{
	int		fd;
	char	*line;
	t_map	data;

	data.nb_lines = 0;
	data.nb_num = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		ft_read_error(2);
	while (get_next_line(fd, &line))
	{
		data.nb_num = ft_count(line);
		if (data.nb_num != 30)
			ft_map_error(1);
		data.nb_lines++;
		free(line);
	}
	if (data.nb_lines != 30)
		ft_map_error(0);
	close(fd);
	read_data(file, &data);
	ft_check_walls(&data);
	return (data.tab);
}

void	ft_init(t_data *wolf)
{
	wolf->player.dirx = 0;
	wolf->player.diry = 0;
	/*wolf->player.start_x = 2;
	wolf->player.start_y = 2;*/
	wolf->player.fov = 60;
	wolf->player.posx = PRES;
	wolf->player.posy = PRES + 10;
	wolf->proj_dist_player = (SCREEN_X / 2) / tan((wolf->player.fov / 2) * RAD);
	wolf->mlx = mlx_init();
	wolf->win = mlx_new_window(wolf->mlx, SCREEN_X, SCREEN_Y, "WOLF3D");
	wolf->img = mlx_new_image(wolf->mlx, SCREEN_X, SCREEN_Y);
}

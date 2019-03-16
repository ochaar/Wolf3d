/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:42:32 by ochaar            #+#    #+#             */
/*   Updated: 2019/03/16 15:23:30 by ochaar           ###   ########.fr       */
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
	if (len > 1000 || len <= 0)
		return (0);
	while (i < len)
	{
		if (ft_isdigit(line[i]) == 1)
			nb++;
		i++;
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
			ft_map_error(2, 0);
		else if (data->tab[29][i] != 1 || data->tab[i][29] != 1)
			ft_map_error(2, 0);
		i++;
	}
}

void	boucle(t_map *data, char *line)
{
	char	**dst;

	if (!(dst = ft_strsplit(line, ' ')))
		ft_read_error(5);
	if (!(data->tab[data->i] = (int*)malloc(sizeof(int) * data->nb_num)))
		ft_read_error(1);
	while (dst[data->j])
	{
		data->tab[data->i][data->j] = ft_atoi(dst[data->j]);
		data->j++;
	}
	ft_free_char(dst);
}

void	read_data(char *file, t_map *data)
{
	char	*line;
	int		fd;
	int		ret;

	line = NULL;
	data->i = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		ft_read_error(2);
	if (!(data->tab = (int**)malloc(sizeof(int*) * data->nb_lines)))
		ft_read_error(1);
	while (data->i < data->nb_lines)
	{
		data->j = 0;
		ret = get_next_line(fd, &line);
		boucle(data, line);
		free(line);
		data->i++;
	}
	if (ret == -1)
		ft_read_error(5);
	close(fd);
}

int		**ft_verif(char *file)
{
	int		fd;
	char	*line;
	t_map	data;
	int		ret;

	data.nb_lines = 0;
	if ((fd = open(file, O_RDONLY)) <= 0)
		ft_read_error(2);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ret == -1 || (!*line))
			ft_read_error(5);
		if ((data.nb_num = ft_count(line)) != 30)
			ft_map_error(1, data.nb_lines + 1);
		data.nb_lines++;
		free(line);
	}
	if (ret == -1)
		ft_read_error(5);
	if (data.nb_lines != 30)
		ft_map_error(0, 0);
	close(fd);
	read_data(file, &data);
	ft_check_walls(&data);
	return (data.tab);
}

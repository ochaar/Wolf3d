/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:53:19 by fbecerri          #+#    #+#             */
/*   Updated: 2018/11/23 18:12:24 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	unsigned int	i;
	char			*dst;

	if (!(dst = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_reader(char **str, char *buff, int fd)
{
	char	*tmp;
	int		ret;

	ret = 1;
	while (!(ft_strchr(*str, '\n')) && ret != 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (NULL);
		if (ret)
		{
			buff[ret] = '\0';
			tmp = *str;
			if (!(*str = ft_strjoin(*str, buff)))
				return (NULL);
			free(tmp);
		}
	}
	free(buff);
	return (*str);
}

char	*ft_line(char **str)
{
	char		*buff;
	char		*line;
	char		*tmp;

	buff = ft_strchr(*str, '\n');
	tmp = NULL;
	if (buff)
	{
		if (!(line = ft_strndup(*str, buff - *str)))
			return (NULL);
		tmp = *str;
		if (!(*str = ft_strdup(buff + 1)))
			return (NULL);
		free(tmp);
	}
	else if (!(line = ft_strdup(*str)))
		return (NULL);
	if (!((*str) && tmp))
	{
		free(*str);
		*str = NULL;
	}
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str;
	char			*buff;

	if (!str)
		str = NULL;
	if (fd < 0 || !line || BUFF_SIZE <= 0 || !(buff = ft_strnew(BUFF_SIZE + 1))
		|| (!str && !(str = ft_strnew(0))))
		return (-1);
	if (!(ft_reader(&str, buff, fd)))
		return (-1);
	if (*str)
	{
		if (!(*line = ft_line(&str)))
			return (-1);
		return (1);
	}
	return (0);
}

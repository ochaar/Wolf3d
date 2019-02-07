/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:56:39 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/11 16:48:25 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_last_index(char const *s, int i)
{
	int n;

	n = 0;
	while (s[i])
	{
		i++;
		n++;
	}
	i = i - 1;
	if (n > 0)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			i--;
			n--;
		}
	}
	return (n);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	len = ft_last_index(s, i);
	i = 0;
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j++;
	while (i < len)
	{
		str[i] = s[j + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

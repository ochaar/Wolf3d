/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:23:34 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/09 23:48:22 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j] != '\0' && (i + j) < n)
			j++;
		if (j == ft_strlen(to_find))
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

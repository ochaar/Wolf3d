/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:51:03 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/09 15:38:56 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*cpys;
	char		*final;

	i = 0;
	cpys = (char *)s;
	while (i < n)
	{
		if (cpys[i] == (char)c)
		{
			final = &cpys[i];
			return (final);
		}
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:40:24 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/09 20:32:14 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*cdst;

	i = 0;
	cdst = (char *)dst;
	if (cdst > (char *)src)
	{
		while (i < n)
		{
			cdst[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			cdst[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

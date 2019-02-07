/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:57:35 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/09 15:46:11 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*cpys1;
	unsigned char		*cpys2;

	i = 0;
	cpys1 = (unsigned char *)s1;
	cpys2 = (unsigned char *)s2;
	while (i < n)
	{
		if (cpys1[i] != cpys2[i])
			return ((int)(cpys1[i] - cpys2[i]));
		i++;
	}
	return (0);
}

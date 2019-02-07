/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:46:25 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/08 18:46:24 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpys;

	i = 0;
	cpys = (unsigned char *)s;
	while (i < n)
	{
		cpys[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

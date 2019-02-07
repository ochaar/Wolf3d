/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:24:46 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/06 19:47:40 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	char	*first;

	first = dest;
	dest = &dest[ft_strlen(dest)];
	while (*src != '\0' && nb > 0)
	{
		*dest++ = *src++;
		nb--;
	}
	*dest = 0;
	return (first);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:51:07 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/09 21:07:42 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (1);
	else if (s1 == NULL || s2 == NULL)
		return (0);
	while ((i < n) && (s1[i] == s2[i]))
	{
		if (s1[i] == '\0')
			return (1);
		i++;
	}
	if (i == n)
		return (1);
	return (0);
}

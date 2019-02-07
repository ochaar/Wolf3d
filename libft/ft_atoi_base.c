/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:23:07 by ochaar            #+#    #+#             */
/*   Updated: 2019/01/16 15:12:22 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_base(char c, int base)
{
	int		i;
	char	*hexa;

	i = 0;
	hexa = "0123456789ABCDEF";
	while (i < base)
	{
		if (hexa[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_base(const char *str, int base)
{
	int		nb;
	int		sign;

	nb = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str != ' ')
	{
		if (find_base(ft_toupper(*str), base) != -1)
			nb = (nb * base) + find_base(ft_toupper(*str), base);
		str++;
	}
	return (sign * nb);
}

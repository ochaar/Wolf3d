/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:28:34 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/13 11:37:06 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_atoi(const char *str)
{
	int			i;
	int			negativ;
	long long	result;

	i = 0;
	negativ = 1;
	result = 0;
	while ((str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')) && str[i])
		i++;
	if (str[i] == '-')
	{
		negativ = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if (result < 0)
			return ((negativ == 1) ? -1 : 0);
	}
	return ((int)result * negativ);
}

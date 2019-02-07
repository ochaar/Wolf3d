/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:25:21 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/13 11:51:00 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static char	*ft_stock(char *str, int nbr, int len)
{
	int		i;

	str[len] = '\0';
	len = len - 1;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		i = 1;
		str[0] = '-';
	}
	else
		i = 0;
	while (len >= i)
	{
		str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	int		over;
	char	*str;

	over = 0;
	if (n == -2147483648)
	{
		n = -2147483647;
		over = 1;
	}
	len = ft_length(n);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str = ft_stock(str, n, len);
	str[len - 1] += over;
	return (str);
}

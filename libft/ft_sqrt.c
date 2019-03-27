/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:08:02 by ochaar            #+#    #+#             */
/*   Updated: 2019/03/20 14:43:36 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_sqrt(int nb)
{
	long	result;

	result = 1;
	while (result * result < nb)
		result++;
	return ((int)result);
}

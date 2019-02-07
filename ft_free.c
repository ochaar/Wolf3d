/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:31:43 by ochaar            #+#    #+#             */
/*   Updated: 2019/01/31 11:32:34 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_free_char(char **dst)
{
	int		k;

	k = 0;
	while (dst[k])
	{
		free(dst[k]);
		k++;
	}
	free(dst);
}

void	ft_free_int(int **tab)
{
	int		k;

	k = 0;
	while (k < 10)
	{
		free(tab[k]);
		k++;
	}
	free(tab);
}

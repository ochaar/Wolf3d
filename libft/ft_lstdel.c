/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:40:01 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/09 15:25:38 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *suppr;

	while (*alst != NULL)
	{
		suppr = (*alst);
		del((*alst)->content, (*alst)->content_size);
		(*alst) = (*alst)->next;
		free(suppr);
		suppr = NULL;
	}
}

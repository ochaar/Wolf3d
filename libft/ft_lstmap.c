/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 22:54:53 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/13 11:02:19 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*first;
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	newlst = ft_lstnew(f(lst)->content, f(lst)->content_size);
	if (newlst == NULL)
		return (NULL);
	first = newlst;
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (temp == NULL)
			return (NULL);
		newlst->next = temp;
		newlst = temp;
	}
	return (first);
}

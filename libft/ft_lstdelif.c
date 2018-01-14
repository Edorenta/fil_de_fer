/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:54:47 by pde-rent          #+#    #+#             */
/*   Updated: 2017/09/21 02:02:05 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelif(t_list **lst, void *content_ref, int (*cmp)())
{
	t_list	*prev_item;
	t_list	*item;
	t_list	*tmp;

	item = *lst;
	prev_item = NULL;
	tmp = NULL;
	while (item != NULL)
	{
		if ((*cmp)(item->content, content_ref) == 0)
		{
			if (item == *lst)
				*lst = item->next;
			else
				prev_item->next = item->next;
			tmp = item;
			item = item->next;
			free(tmp);
		}
		else
		{
			prev_item = item;
			item = item->next;
		}
	}
}

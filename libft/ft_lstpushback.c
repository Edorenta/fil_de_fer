/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:20:07 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/29 14:20:09 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **lst, void *content, size_t content_size)
{
	t_list	*item;

	if (*lst)
	{
		item = *lst;
		while (item->next)
			item = item->next;
		item->next = ft_lstnew(content, content_size);
	}
	else
		*lst = ft_lstnew(content, content_size);
}

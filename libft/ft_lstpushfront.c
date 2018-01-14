/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:54:18 by pde-rent          #+#    #+#             */
/*   Updated: 2017/09/21 06:03:17 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushfront(t_list **lst_start, void *content, size_t content_size)
{
	t_list	*item;

	if (*lst_start)
	{
		item = ft_lstnew(content, content_size);
		item->next = *lst_start;
		*lst_start = item;
	}
	else
		*lst_start = ft_lstnew(content, content_size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:54:51 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/29 14:16:59 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmerge(t_list **lst1, t_list *lst2)
{
	t_list	*item;

	if (*lst1)
	{
		item = *lst1;
		while (item->next)
			item = item->next;
		item->next = lst2;
	}
	else
		*lst1 = lst2;
}

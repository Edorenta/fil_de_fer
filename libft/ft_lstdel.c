/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:30:06 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/29 14:16:39 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **lst, void (*del)(void *, size_t))
{
	t_list	*item;
	t_list	*next;

	item = *lst;
	while (item)
	{
		next = item->next;
		ft_lstdelone(&item, del);
		item = next;
	}
	*lst = NULL;
}

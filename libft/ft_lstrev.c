/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:54:39 by pde-rent          #+#    #+#             */
/*   Updated: 2017/09/21 02:17:04 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list	*prev_item;
	t_list	*item;
	t_list	*next_item;

	prev_item = NULL;
	item = *lst;
	while (item != NULL)
	{
		next_item = item->next;
		item->next = prev_item;
		prev_item = item;
		item = next_item;
	}
	*lst = prev_item;
}

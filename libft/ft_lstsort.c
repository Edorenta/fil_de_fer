/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsprt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:54:54 by pde-rent          #+#    #+#             */
/*   Updated: 2017/09/21 02:02:23 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **lst, int (*cmp)())
{
	t_list	*item;
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*prev_item;
	t_list	*next_item;

	item = *lst;
	prev_item = *lst;
	while (item->next)
	{
		if ((*cmp)(item->content, item->next->content) > 0)
		{
			tmp_a = item;
			tmp_b = item->next;
			next_item = tmp_b->next;
			prev_item->next = tmp_b;
			tmp_b->next = tmp_a;
			tmp_a->next = next_item;
			item = tmp_b;
		}
		else
			item = item->next;
	}
}

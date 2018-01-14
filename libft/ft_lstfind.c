/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:54:45 by pde-rent          #+#    #+#             */
/*   Updated: 2017/09/21 03:25:11 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, void *ref_content, int (*cmp)())
{
	t_list	*item;

	item = lst;
	while (item != NULL)
	{
		if ((*cmp)(item->content, ref_content) == 0)
			return (item);
		item = item->next;
	}
	return (item);
}

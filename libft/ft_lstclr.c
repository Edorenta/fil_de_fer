/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:54:34 by pde-rent          #+#    #+#             */
/*   Updated: 2017/09/21 02:01:10 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclr(t_list **lst)
{
	t_list	*next;
	t_list	*item;

	item = *lst;
	while (item != NULL)
	{
		next = item->next;
		free(item);
		item = next;
	}
	*lst = NULL;
}

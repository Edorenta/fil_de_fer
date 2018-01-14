/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:30:26 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/29 14:17:01 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_item;

	if ((new_item = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_item->content = NULL;
		new_item->content_size = 0;
	}
	else
	{
		new_item->content = ft_memdup(content, content_size);
		new_item->content_size = content_size;
	}
	new_item->next = NULL;
	return (new_item);
}

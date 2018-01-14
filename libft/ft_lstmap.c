/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:30:18 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/29 14:16:57 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *item))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*new_start;

	tmp = f(lst);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	new_start = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (new_start);
}

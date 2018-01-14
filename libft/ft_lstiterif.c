/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:30:14 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/29 14:16:52 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiterif(t_list *lst, void (*f)(t_list *item),
		void *content_ref, int (*cmp)())
{
	if ((lst->next) != NULL)
		(ft_lstiter(lst->next, f));
	if ((*cmp)(lst->content, content_ref) == 0)
		f(lst);
}

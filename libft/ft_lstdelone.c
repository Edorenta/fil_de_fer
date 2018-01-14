/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:30:10 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/29 14:16:45 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **lst, void (*del)(void*, size_t))
{
	if (!lst || !del)
		return ;
	del((*lst)->content, (*lst)->content_size);
	free(*lst);
	*lst = NULL;
	return ;
}

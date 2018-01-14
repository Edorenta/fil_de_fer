/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:54:36 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/29 14:16:32 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *lst, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!lst)
		return (NULL);
	while (i < n)
	{
		if (lst->next)
			lst = lst->next;
		else
			return (NULL);
		i++;
	}
	return (lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpusharg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:19:46 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/29 14:19:53 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpusharg(int ac, char **av)
{
	t_list	*item;
	t_list	*next_item;
	int		i;

	next_item = NULL;
	item = NULL;
	i = -2;
	while ((i += 2) < ac)
	{
		item = ft_lstnew(av[i], ft_atoi(av[i + 1]));
		item->next = next_item;
		next_item = item;
	}
	return (item);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:32:10 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 15:15:34 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str, int len)
{
	char *first;
	char *last;
	char tmp;

	first = str;
	last = str + len - 1;
	while (first < last)
	{
		tmp = *first;
		*first++ = *last;
		*last-- = tmp;
	}
	return (str);
}

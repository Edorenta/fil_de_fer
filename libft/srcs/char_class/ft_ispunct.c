/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 22:03:29 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 15:33:11 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ispunct(int c)
{
	return ((' ' < c && c < '0')
			|| ('9' < c && c < 'A')
			|| ('Z' < c && c < 'a')
			|| ('z' < c && c <= '~'));
}

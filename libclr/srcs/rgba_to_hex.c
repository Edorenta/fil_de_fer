/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba_to_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 22:06:09 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/02 22:06:40 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		rgb_to_hex(int r, int g, int b)
{
	return (((r & 0xff) << 16)
			| ((g & 0xff) << 8)
			| (b & 0xff));
}

int		rgba_to_hex(int r, int g, int b, int a)
{
	return (((r & 0xff) << 24)
			| ((g & 0xff) << 16)
			| ((b & 0xff) << 8)
			| (a & 0xff));
}

int		argb_to_hex(int a, int r, int g, int b)
{
	return (((a & 0xff) << 24)
			| ((r & 0xff) << 16)
			| ((g & 0xff) << 8)
			| (b & 0xff));
}

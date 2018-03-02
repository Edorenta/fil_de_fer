/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:53:36 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/08 15:03:51 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		put_err(int errno)
{
	if (errno == 1)
		ft_putstr("usage: ./fdf [map_file]\n");
	else if (errno == 2)
		ft_putstr("error: map not found\n");
	else if (errno == 3)
		ft_putstr("error: map format not compliant\n");
	return (errno);
}

int		check_av(int ac, char **av)
{
	int errno;
	
	errno = 0;
	if (ac != 2)
		errno = 1;
	else if (!check_map(raw_str(av[1])))
		errno = 2;
	else if (check_map(raw_str(av[1])) == -1)
		errno = 3;
	return (errno);
}

int		check_map(char *str)
{
	return 1;
}

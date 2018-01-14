/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:20:22 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/14 17:05:35 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char	*raw_str(char *file_name)
{
	int     fd;
	int     i;
	int     handle;
	char    buf[BUFF_SIZE];
	char    *tmp;

	i = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	while ((handle = read(fd, buf, BUFF_SIZE)))
		i++;
	close(fd);
	tmp = (char *)malloc(sizeof(char) * (i * BUFF_SIZE + 1));
	fd = open(file_name, O_RDONLY);
	handle = read(fd, tmp, (BUFF_SIZE * i + 1));
	i = BUFF_SIZE * (i - 1) - 1;
	while (tmp[++i])
		if (tmp[i] == '\n')
			if(!ft_isdigit(tmp[i + 1]) && !ft_isoperator(tmp[i + 1]))
				while(tmp[++i])
					tmp[i] = '\0';	
	return (tmp);
}

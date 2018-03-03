/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:20:22 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 11:39:53 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char    		*raw_str(char *file_name)
{
	int     fd;
	int     i;
	int		file_size;
	char    buf;
	char    *tmp;
	
	file_size = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	while ((read(fd, &buf, 1) > 0))
			++file_size;
	if (!(file_size))
		return (NULL);
	close(fd);
	IS_CHAR((tmp = (char *)malloc(sizeof(char) * ((file_size + 1)))));
	fd = open(file_name, O_RDONLY);
	read(fd, tmp, file_size);
	tmp[file_size] = '\0';
	printf(tmp);
	close(fd);
	return (tmp);
}

static	int		map_str_tab(t_env *env, char *str)
{
	int		i;
	int		j;
	int		index;
	char	*tmp;

	i = -1;
	j = -1;
	index = 0;
	tmp = (char *)malloc(sizeof(char) * 10);
	while (str[++i] && index < (env->grid.nb_x * env->grid.nb_y))
	{
		while (str[i] && (ft_isoperator(str[i]) || ft_isdigit(str[i])))
		{
			tmp[++j] = str[i];
			i++;
		}
		tmp[++j] = '\0';
		MX[index / (env->grid.nb_x)][(index % (env->grid.nb_x))]
		= ft_atoi(tmp);
			printf("x: %d , y: %d\n", index % (env->grid.nb_x), index / (env->grid.nb_x));
		++index;
		j = -1;
	}
	free(str);
	grid_init(env);
	return (1);
}

static	int		dim_tab(t_env *env, char *str)
{
	int i;
	int j;

	i = -1;
	j = ((ft_isdigit(str[0]) || ft_isoperator(str[0])) ? 1 : 0);

	while(str[++i] != '\n')
	{
		if (str[i] == 32)
			if (ft_isdigit(str[i + 1]) || ft_isoperator(str[i + 1]))
				j++;
		if (str[i] == '\n')
			if (ft_isdigit(str[i + 1]) || ft_isoperator(str[i + 1]))
				j++;
	}
	env->grid.nb_x = j;
	i = -1;
	IS_INT((MX = (int **)malloc(sizeof(int *) * (env->grid.nb_y))));
	while (++i < env->grid.nb_y)
		IS_INT((MX[i] = (int *)malloc(sizeof(int) * (env->grid.nb_x))));
	return (map_str_tab(env, str));
}

int		tab_init(t_env *env, char *str)
{
	int		i;
	int		j;
	
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == '\n')
			j++;
	if (str[i - 1] != '\n')
		j++;
	env->grid.nb_y = j;
	return (dim_tab(env, str));
}

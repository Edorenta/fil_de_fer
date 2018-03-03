/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:20:22 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 07:53:42 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//convert the raw file to a string
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
	while ((read(fd, &buf, 1)))
			file_size++;
	if (!(file_size))
		return (NULL);
	close(fd);
	IS_CHAR((tmp = (char *)malloc(sizeof(char) * ((file_size + 1)))));
	fd = open(file_name, O_RDONLY);
	read(fd, tmp, file_size);
	tmp[file_size] = '\0';
	printf("%s\n", tmp);
	return (tmp);
}

//convert the unique string to a char **table
static	int		map_str_tab(t_env *env, char *str)
{
	int		i;
	int		j;
	int		rows;
	int		index;
	char	*tmp;

	i = -1;
	j = -1;
	rows = 0;
	index = 0;

	IS_INT((MX = (int **)malloc(sizeof(int *) * env->grid->nb_y)));
	tmp = (char *)malloc(sizeof(char) * 10);
	while (++i < env->grid->nb_y)
		IS_INT((MX[i] = (int *)malloc(sizeof(int) * env->grid->nb_x)));
	i = -1;
	while (str[++i])
	{
		if (ft_isoperator(str[i]) || ft_isdigit(str[i]))
		{
			while (ft_isoperator(str[i]) || ft_isdigit(str[i]))
			{
				tmp[++j] = str[i];
				i++;
			}
			tmp[++j] = '\0';
			MX[index / (env->grid->nb_x)][(index % (env->grid->nb_x))]
			= ft_atoi(tmp);
			//printf("MX[%d,%d]: %d \n", index / (env->grid->nb_x),
			//		index % (env->grid->nb_x), ft_atoi(tmp));
			++index;
			j = -1;
		}	
	}
	free(str);
	grid_init(env);
	return (1);
}

//convert each lines of the initial file into a tab of char* matching wireframe
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
	env->grid->nb_x = j;
	return (map_str_tab(env, str));
}

//find the theoretical size of the wireframe counting \n and pass the data
int		tab_init(t_env *env, char *str)
{
	int		i;
	int		j;
	
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == '\n')
			j++;
	if (str[i-1] != '\n' && !str[i])
		j++;
	env->grid->nb_y = j;
	return (dim_tab(env, str));
}

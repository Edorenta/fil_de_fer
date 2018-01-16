/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:42:20 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/16 16:01:51 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		main(int ac, char **av)
{
	t_env	*env;
	int		i = -1;

	env = env_init();
	tab_init(env, raw_str(env, av[1]));
	while (++i < env->grid->nb_y)
	{
		ft_arrayprint(MX[i], env->grid->nb_x, 32);
		ft_putchar(10);
	}
	//sketch(env); 
	//dyna_key_hook(env);
	//win_refresh(env);
	//printf("loop\n");
	return (0);
}

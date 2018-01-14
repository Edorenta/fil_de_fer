/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:46:28 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/14 16:21:13 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		key_recognition(int key_code, t_env *env)
{
	if (key_code == 53)
		exit(0);
	env->index = key_code;
	printf("keycode:%d\n", key_code);
	sketch(env);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:34:31 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/14 17:17:42 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include<stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"

# define IS_INT(x) if (!x) return (0);
# define IS_CHAR(x) if (!x) return (NULL);
# define IS_VOID(x) if (!x) return ;

# define SCREEN_WIDTH 2560
# define SCREEN_HEIGHT 1440
# define WHITE 0x00FFFFFF
# define BUFF_SIZE 1000

typedef	struct	s_env
{
	t_grid	grid;
	t_view	view;
	void	*mlx;
	void	*win;
	char	*win_title;
	int		index;
	int     width;
	int     height;
	int     pct_scale;
}				t_env;

typedef struct  s_point
{
	int     x;
	int     y;
	int     z;
	int     clr;
}               t_point;

typedef	struct	s_vect
{
	t_point pt1;
	t_point pt2;
	int		clr1;
	int		clr2;
}				t_vect;

typedef struct	s_grid
{
	int		nb_x;
	int		nb_y;
	int		x_spacing;
	int		y_spacing;
	int		z_spacing;
}			t_grid;

typedef struct	s_view
{
	int		zoom;
	int		x_pos;
	int		y_pos;
}				t_view;

void	draw_vector(t_env *env, t_point *a, t_point *b, int clr1, int clr2);
void    draw_circle(t_env *env, t_point *a, float pct_radius, int clr);
void	win_refresh(void *thread);
void	ppixel(t_env *env, int x, int y, int clr);
char	*raw_str(char *file_name);
int		dyna_key_hook(t_env *env);
int		key_recognition(int key_code, t_env *env);
int		sketch(t_env *env);
t_env	*env_init(void);

#endif

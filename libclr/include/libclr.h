/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 03:50:38 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 15:51:23 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCLR_H
# define LIBCLR_H

# include <stdlib.h>
# include <math.h>

# define DMIN(X,Y)		(X > Y ? Y : X)
# define DMAX(X,Y)		(X > Y ? X : Y)

# define MODE_RGB		1
# define MODE_RGBA		2
# define MODE_ARGB		3

# define WHITE			0x00FFFFFF
# define GREY			0x00A4A4A4
# define LIGHT_GREY		0x00CCCCCC
# define CYAN			0x0000FFFF
# define RED			0x00FF0000
# define GREEN			0x0000FF00
# define SKY_BLUE		0x0000CCFF
# define BLUE			0x000000FF
# define MAGENTA		0x00FF00FF
# define YELLOW			0x00FFFF00
# define SAND			0x00FFCC66
# define ORANGE			0x00FF8000

# define BLACK			0x00000000
# define DARK_GREY		0x00232323
# define DARK_CYAN		0x00001a1e
# define DARK_RED		0x00140000
# define DARK_GREEN		0x00002105
# define DARK_BLUE		0x0000114c
# define DARK_PINK		0x0010001c
# define DARK_SAND		0x00261d00
# define DARK_FUN		0x006D647F
# define BROWN			0x001c1515

# define ALPHA_100		0xFF
# define ALPHA_95		0xF2
# define ALPHA_90		0xE6
# define ALPHA_85		0xD9
# define ALPHA_80		0xCC
# define ALPHA_75		0xBF
# define ALPHA_70		0xB3
# define ALPHA_65		0xA6
# define ALPHA_60		0x99
# define ALPHA_55		0x8C
# define ALPHA_50		0x80
# define ALPHA_45		0x73
# define ALPHA_40		0x66
# define ALPHA_35		0x59
# define ALPHA_30		0x4D
# define ALPHA_25		0x40
# define ALPHA_20		0x33
# define ALPHA_15		0x26
# define ALPHA_10		0x1A
# define ALPHA_5		0x0D
# define ALPHA_0		0x00

long	parse_long(char *str);
double	parse_double(char *str);
int		parse_rgb(char *str);
int		rgb_to_hex(int r, int g, int b);
int		rgba_to_hex(int r, int g, int b, int a);
int		argb_to_hex(int a, int r, int g, int b);
int		shade_color(int clr, int pct);
int		shade_opacity(int clr, int pct, int mode);
int		blend_color(int clr1, int clr2, int pct);
int		set_opacity(int clr, int lvl);
int		hex_r(long clr, int mode);
int		hex_g(long clr, int mode);
int		hex_b(long clr, int mode);
int		hex_a(long clr, int mode);
int		*hex_rgba(long clr, int mode, int *ptr);

#endif

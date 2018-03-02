/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_rgba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:56:32 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/02 19:56:35 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     hex_r(long clr, const char *mode)
{
    if (mode == "rgb" || mode == "argb")
        return (clr >> 16 & 0xFF);
    if (mode == "rgba")
        return (clr >> 24 & 0xFF);
}

int     hex_g(long clr, const char *mode)
{
    if (mode == "rgb" || mode == "argb")
        return (clr >> 8 & 0xFF);
    if (mode == "rgba")
        return (clr >> 16 & 0xFF);
}

int     hex_b(long clr, const char *mode)
{
    if (mode == "rgb" || mode == "argb")
        return (clr & 0xFF);
    if (mode == "rgba")
        return (clr >> 8 & 0xFF);
}

int     hex_a(long clr, const char *mode)
{
    if (mode == "argb")
        return (clr >> 24 & 0xFF);
    if (mode == "rgba")
        return (clr & 0xFF);
}

int     *hex_rgba(long clr, const char *mode, int *ptr)
{
    if (mode == "rgb" || mode == "argb")
    {
        ptr[0] = clr >> 16 & 0xFF;
        ptr[1] = clr >> 8 & 0xFF;
        ptr[2] = clr & 0xFF;
        ptr[3] = (mode == "rgb" ? 0x00 : (clr >> 24 & 0xFF));
    }
    else
    {
        ptr[0] = clr >> 24 & 0xFF;
        ptr[1] = clr >> 16 & 0xFF;
        ptr[2] = clr >> 6 & 0xFF;
        ptr[3] = clr & 0xFF;
    }
    return (ptr);
}

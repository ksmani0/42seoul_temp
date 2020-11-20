/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:35:27 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/11 00:48:27 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_light(double (*rgb)[3], double coef, int color)
{
	unsigned int mask;

	mask = 255 << 16;
	(*rgb)[0] += coef * ((color & mask) >> 16) / 255;
	mask >>= 8;
	(*rgb)[1] += coef * ((color & mask) >> 8) / 255;
	mask >>= 8;
	(*rgb)[2] += coef * (color & mask) / 255;
}

void	compute_light(t_inter *inter, t_scene data, t_figures *lst)
{
	double		light;
	double		l_rgb[3];
	t_vector	dir;

	light = 0.0;
	ft_memset(l_rgb, 0, sizeof(double) * 3);
	add_light(&l_rgb, data.ambient_light, data.al_color);
	while (data.l)
	{
		dir = vector_substract(data.l->o, inter->p);
		if (is_hit(inter->p, dir, lst) && dot_product(inter->normal, dir) > 0)
		{
			light = data.l->br * vector_cos(inter->normal, dir);
			add_light(&l_rgb, light, data.l->color);
		}
		data.l = data.l->next;
	}
	inter->color = color_x_light(inter->color, l_rgb);
}

int		is_hit(t_point3 o, t_vector d, t_figures *lst)
{
	double	in;

	while (lst)
	{
		if (lst->flag == SP)
			in = sphere_intersection(o, d, lst);
		else if (lst->flag == CY)
			in = cylinder_intersection(o, d, lst);
		else if (lst->flag == SQ)
			in = square_intersection(o, d, lst);
		else if (lst->flag == TR)
			in = triangle_intersection(o, d, lst);
		else if (lst->flag == PL)
			in = plane_intersection(o, d, lst);
		if (in > EPSILON && in < 1)
			return (0);
		lst = lst->next;
	}
	return (1);
}

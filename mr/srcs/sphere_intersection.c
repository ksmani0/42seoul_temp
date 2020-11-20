/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:16:45 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/09 16:29:54 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		sphere_root(double x[2], t_point3 o, t_vector d, t_figures *lst)
{
	double		discriminant;
	t_vector	o_to_c;
	double		a;
	double		b;
	double		c;

	o_to_c = vector_substract(o, lst->fig.sp.c);
	a = dot_product(d, d);
	b = 2 * dot_product(d, o_to_c);
	c = dot_product(o_to_c, o_to_c) - lst->fig.sp.r * lst->fig.sp.r;
	discriminant = b * b - (4 * a * c);
	if (discriminant < 0)
	{
		x[0] = INFINITY;
		x[1] = INFINITY;
		return ;
	}
	x[0] = (-b + sqrt(discriminant)) / (2 * a);
	x[1] = (-b - sqrt(discriminant)) / (2 * a);
}

double			sphere_intersection(t_point3 o, t_vector d, t_figures *lst)
{
	double		closest;
	double		x[2];

	closest = INFINITY;
	sphere_root(x, o, d, lst);
	if (x[0] > EPSILON && x[0] < INFINITY)
		closest = x[0];
	if (x[1] > EPSILON && x[1] < INFINITY)
		closest = x[1] < x[0] ? x[1] : x[0];
	return (closest);
}

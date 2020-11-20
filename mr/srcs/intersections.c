/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:37:41 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/11 00:26:34 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		plane_root(t_point3 o, t_vector d, t_point3 pl_p, t_vector pl_nv)
{
	double	x;
	double	nv_dir_dot;

	nv_dir_dot = dot_product(pl_nv, d);
	if (nv_dir_dot == 0)
		return (INFINITY);
	x = (dot_product(pl_nv, vector_substract(pl_p, o)) / nv_dir_dot);
	return (x > 0 ? x : INFINITY);
}

double		plane_intersection(t_point3 o, t_vector d, t_figures *lst)
{
	return (plane_root(o, d, lst->fig.pl.p, lst->normal));
}

int			is_p_out_of_plane(t_point3 p1, t_point3 p2, t_point3 p3, t_point3 p)
{
	t_vector v1;
	t_vector v2;
	t_vector v3;
	t_vector v4;
	t_vector normal;

	v1 = vector_substract(p2, p1);
	v4 = vector_substract(p3, p1);
	v2 = vector_substract(p3, p2);
	v3 = vector_substract(p1, p3);
	normal = cross_product(v1, v4);
	if (dot_product(normal, cross_product(v1, vector_substract(p, p1))) < 0)
		return (1);
	if (dot_product(normal, cross_product(v2, vector_substract(p, p2))) < 0)
		return (1);
	if (dot_product(normal, cross_product(v3, vector_substract(p, p3))) < 0)
		return (1);
	return (0);
}

double		square_intersection(t_point3 o, t_vector d, t_figures *lst)
{
	double		t;
	double		cosine;
	t_vector	ip;
	t_sq		sq;

	t = plane_intersection(o, d, lst);
	ip = vector_add(o, multiply_scalar(d, t));
	sq.u = fabs(lst->normal.y) == 1 ? new_vector(1, 0, 0) : new_vector(0, 1, 0);
	sq.v = cross_product(lst->normal, sq.u);
	sq.c_to_ip = vector_substract(ip, lst->fig.sp.c);
	cosine = fabs(vector_cos(sq.v, sq.c_to_ip));
	if (cosine < sqrt(2) / 2)
		cosine = cos(M_PI_2 - acos(cosine));
	if (length(sq.c_to_ip) <= (((lst->fig.sq.side) / 2) / cosine))
		return (t);
	return (INFINITY);
}

double		triangle_intersection(t_point3 o, t_vector d, t_figures *lst)
{
	double		t;
	t_vector	ip;

	t = plane_intersection(o, d, lst);
	ip = vector_add(o, multiply_scalar(d, t));
	if (is_p_out_of_plane(lst->fig.tr.p1, lst->fig.tr.p2,
						lst->fig.tr.p3, ip))
		return (INFINITY);
	return (t);
}

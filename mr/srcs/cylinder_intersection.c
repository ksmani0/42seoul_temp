/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:52:21 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/11 00:47:08 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int			cylinder_hit(double x[2], t_point3 o, t_vector d,
							t_figures *lst)
{
	t_vector	v;
	t_vector	u;
	double		a;
	double		b;
	double		c;

	v = multiply_scalar(lst->fig.cy.nv,
						dot_product(d, lst->fig.cy.nv));
	v = vector_substract(d, v);
	a = dot_product(v, v);
	u = multiply_scalar(lst->fig.cy.nv, dot_product(lst->fig.cy.nv,
		vector_substract(o, lst->fig.cy.c)));
	u = vector_substract(vector_substract(o, lst->fig.cy.c), u);
	b = 2 * dot_product(v, u);
	c = dot_product(u, u) - pow(lst->fig.cy.r, 2);
	x[0] = (-b + sqrt((b * b) - 4 * a * c)) / (2 * a);
	x[1] = (-b - sqrt((b * b) - 4 * a * c)) / (2 * a);
	if (errno == EDOM || (x[0] < EPSILON && x[1] < EPSILON))
	{
		x[0] = INFINITY;
		x[1] = INFINITY;
		return (0);
	}
	return (1);
}

static t_vector		calc_cy_normal(double x[2], t_point3 o, t_vector d,
									t_figures *lst)
{
	double	dist;
	double	t;

	if ((lst->fig.cy.dist1 >= 0 && lst->fig.cy.dist1 <= lst->fig.cy.h
		&& x[0] > EPSILON) && (lst->fig.cy.dist2 >= 0 &&
		lst->fig.cy.dist2 <= lst->fig.cy.h && x[1] > EPSILON))
	{
		dist = x[0] < x[1] ? lst->fig.cy.dist1 : lst->fig.cy.dist2;
		t = x[0] < x[1] ? x[0] : x[1];
	}
	else if (lst->fig.cy.dist1 >= 0 &&
			lst->fig.cy.dist1 <= lst->fig.cy.h && x[0] > EPSILON)
	{
		dist = lst->fig.cy.dist1;
		t = x[0];
	}
	else
	{
		dist = lst->fig.cy.dist2;
		t = x[1];
	}
	x[0] = t;
	return (normalize(vector_substract(vector_substract(multiply_scalar(d, t),
			multiply_scalar(lst->fig.cy.nv, dist)),
			vector_substract(lst->fig.cy.c, o))));
}

static double		cylinder_root(t_point3 o, t_vector d, t_vector *normal,
							t_figures *lst)
{
	double		x[2];
	t_vector	ip;

	if (cylinder_hit(x, o, d, lst) == 0)
		return (INFINITY);
	ip = multiply_scalar(d, x[0]);
	lst->fig.cy.dist1 = dot_product(lst->fig.cy.nv,
		vector_substract(ip, vector_substract(lst->fig.cy.c, o)));
	ip = multiply_scalar(d, x[1]);
	lst->fig.cy.dist2 = dot_product(lst->fig.cy.nv,
		vector_substract(ip, vector_substract(lst->fig.cy.c, o)));
	if (!((lst->fig.cy.dist1 >= 0 && lst->fig.cy.dist1 <= lst->fig.cy.h &&
		x[0] > EPSILON) || (lst->fig.cy.dist2 >= 0 &&
		lst->fig.cy.dist2 <= lst->fig.cy.h && x[1] > EPSILON)))
		return (INFINITY);
	*normal = calc_cy_normal(x, o, d, lst);
	return (x[0]);
}

static double		caps_intersection(t_point3 o, t_vector d, t_figures *lst)
{
	t_point3	c2;
	t_point3	ip1;
	t_point3	ip2;
	double		t1;
	double		t2;

	c2 = vector_add(lst->fig.cy.c,
		multiply_scalar(lst->fig.cy.nv, lst->fig.cy.h));
	t1 = plane_root(o, d, lst->fig.cy.c, lst->fig.cy.nv);
	t2 = plane_root(o, d, c2, lst->fig.cy.nv);
	if (t1 >= INFINITY && t2 >= INFINITY)
		return (INFINITY);
	ip1 = vector_add(o, multiply_scalar(d, t1));
	ip2 = vector_add(o, multiply_scalar(d, t2));
	if ((t1 < INFINITY && distance(ip1, lst->fig.cy.c) <= lst->fig.cy.r)
		&& (t2 < INFINITY && distance(ip2, c2) <= lst->fig.cy.r))
		return (t1 < t2 ? t1 : t2);
	else if (t1 < INFINITY && distance(ip1, lst->fig.cy.c) <= lst->fig.cy.r)
		return (t1);
	else if (t2 < INFINITY && distance(ip2, c2) <= lst->fig.cy.r)
		return (t2);
	return (INFINITY);
}

double				cylinder_intersection(t_point3 o, t_vector d,
											t_figures *lst)
{
	double		cylinder_inter;
	double		caps_inter;
	t_vector	normal;

	cylinder_inter = cylinder_root(o, d, &normal, lst);
	caps_inter = caps_intersection(o, d, lst);
	if (cylinder_inter < INFINITY || caps_inter < INFINITY)
	{
		if (cylinder_inter < caps_inter)
		{
			lst->normal = normal;
			return (cylinder_inter);
		}
		lst->normal = lst->fig.cy.nv;
		return (caps_inter);
	}
	return (INFINITY);
}

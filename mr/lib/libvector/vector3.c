/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:56:34 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/16 17:32:56 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

double		distance(t_point3 p1, t_point3 p2)
{
	double	d;

	d = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
	return (d);
}

t_vector	x_axis_rotation(t_vector v, double angle)
{
	t_vector	row1;
	t_vector	row2;
	t_vector	row3;
	double		radian;

	radian = angle * M_PI / 180;
	row1 = (t_vector){1, 0, 0};
	row2 = (t_vector){0, cos(radian), -sin(radian)};
	row3 = (t_vector){0, sin(radian), cos(radian)};
	return (new_vector(
			dot_product(v, row1),
			dot_product(v, row2),
			dot_product(v, row3)));
}

t_vector	y_axis_rotation(t_vector v, double angle)
{
	t_vector	row1;
	t_vector	row2;
	t_vector	row3;
	double		radian;

	radian = angle * M_PI / 180;
	row1 = (t_vector){cos(radian), 0, sin(radian)};
	row2 = (t_vector){0, 1, 0};
	row3 = (t_vector){-sin(radian), 0, cos(radian)};
	return (new_vector(
			dot_product(v, row1),
			dot_product(v, row2),
			dot_product(v, row3)));
}

t_vector	z_axis_rotation(t_vector v, double angle)
{
	t_vector	row1;
	t_vector	row2;
	t_vector	row3;
	double		radian;

	radian = angle * M_PI / 180;
	row1 = (t_vector){cos(radian), -sin(radian), 0};
	row2 = (t_vector){sin(radian), cos(radian), 0};
	row3 = (t_vector){0, 0, 1};
	return (new_vector(
			dot_product(v, row1),
			dot_product(v, row2),
			dot_product(v, row3)));
}

void		translate(t_point3 *p, t_vector t)
{
	p->x += t.x;
	p->y += t.y;
	p->z += t.z;
}

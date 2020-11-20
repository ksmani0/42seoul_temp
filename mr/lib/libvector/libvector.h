/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 01:07:55 by suntlee           #+#    #+#             */
/*   Updated: 2020/10/20 16:37:46 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECTOR_H
# define LIBVECTOR_H

# include <math.h>

typedef struct	s_point3
{
	double	x;
	double	y;
	double	z;
}				t_point3;

typedef t_point3	t_vector;

t_vector		new_vector(double x, double y, double z);
t_vector		vector_add(t_vector a, t_vector b);
t_vector		vector_substract(t_vector a, t_vector b);
t_vector		vector_product(t_vector a, t_vector b);
double			dot_product(t_vector a, t_vector b);
t_vector		cross_product(t_vector a, t_vector b);
double			length(t_vector v);
t_vector		normalize(t_vector v);
double			vector_sin(t_vector a, t_vector b);
double			vector_cos(t_vector a, t_vector b);
t_vector		multiply_scalar(t_vector v, double n);
double			distance(t_point3 p1, t_point3 p2);
t_vector		x_axis_rotation(t_vector vec, double angle);
t_vector		y_axis_rotation(t_vector vec, double angle);
t_vector		z_axis_rotation(t_vector vec, double angle);

#endif

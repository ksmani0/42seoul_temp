/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:09:28 by suntlee           #+#    #+#             */
/*   Updated: 2020/10/20 16:41:21 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

double		length(t_vector v)
{
	return (sqrt(dot_product(v, v)));
}

t_vector	normalize(t_vector v)
{
	double		len;

	len = length(v);
	return (new_vector(v.x / len, v.y / len, v.z / len));
}

double		vector_cos(t_vector a, t_vector b)
{
	return (dot_product(a, b) / (length(a) * length(b)));
}

double		vector_sin(t_vector a, t_vector b)
{
	return (sqrt(1 - pow(vector_cos(a, b), 2)));
}

t_vector	multiply_scalar(t_vector v, double n)
{
	return (new_vector(n * v.x, n * v.y, n * v.z));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:36:17 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/10 19:52:08 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	calc_normal(t_point3 p, t_vector d, t_figures *lst)
{
	t_vector normal;

	if (lst->flag == SP)
	{
		normal = normalize(vector_substract(p, lst->fig.sp.c));
		if (vector_cos(d, normal) > 0)
		{
			normal = multiply_scalar(normal, -1);
			lst->fig.sp.inside = 1;
		}
		else
			lst->fig.sp.inside = 0;
	}
	else
		normal = vector_cos(d, lst->normal) > 0 ?
				multiply_scalar(lst->normal, -1) : lst->normal;
	return (normal);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:57:28 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/16 17:33:21 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rotation(t_vector *v, t_vector angle)
{
	*v = x_axis_rotation(*v, angle.x);
	*v = y_axis_rotation(*v, angle.y);
	*v = z_axis_rotation(*v, angle.z);
}

void	rotate_cylinder(t_figures *lst, t_vector angle)
{
	while (lst)
	{
		if (lst->flag == CY)
		{
			rotation(&lst->fig.cy.c, angle);
			rotation(&lst->fig.cy.nv, angle);
		}
		lst = lst->next;
	}
}

void	rotate_square(t_figures *lst, t_vector angle)
{
	while (lst)
	{
		if (lst->flag == SQ)
		{
			rotation(&lst->fig.sq.c, angle);
			rotation(&lst->normal, angle);
		}
		lst = lst->next;
	}
}

void	rotate_plane(t_figures *lst, t_vector angle)
{
	while (lst)
	{
		if (lst->flag == PL)
		{
			rotation(&lst->fig.pl.p, angle);
			rotation(&lst->normal, angle);
		}
		lst = lst->next;
	}
}

void	rotate_camera(t_camera *cam, t_vector angle)
{
	while (cam)
	{
		rotation(&cam->nv, angle);
		rotation(&cam->o, angle);
		cam = cam->next;
	}
}

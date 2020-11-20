/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:31:45 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/13 19:44:03 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	trans_sphere(t_figures *lst, t_vector t)
{
	while (lst)
	{
		if (lst->flag == SP)
			translate(&lst->fig.sp.c, t);
		lst = lst->next;
	}
}

void	trans_triangle(t_figures *lst, t_vector t)
{
	while (lst)
	{
		if (lst->flag == TR)
		{
			translate(&lst->fig.tr.p1, t);
			translate(&lst->fig.tr.p2, t);
			translate(&lst->fig.tr.p3, t);
		}
		lst = lst->next;
	}
}

void	trans_square(t_figures *lst, t_vector t)
{
	while (lst)
	{
		if (lst->flag == SQ)
			translate(&lst->fig.sq.c, t);
		lst = lst->next;
	}
}

void	trans_cylinder(t_figures *lst, t_vector t)
{
	while (lst)
	{
		if (lst->flag == CY)
			translate(&lst->fig.cy.c, t);
		lst = lst->next;
	}
}

void	trans_plane(t_figures *lst, t_vector t)
{
	while (lst)
	{
		if (lst->flag == PL)
			translate(&lst->fig.pl.p, t);
		lst = lst->next;
	}
}

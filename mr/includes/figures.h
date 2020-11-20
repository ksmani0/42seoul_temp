/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:27:59 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/08 12:23:06 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURES_H
# define FIGURES_H
# include "minirt.h"

typedef struct	s_sphere
{
	t_point3	c;
	double		r;
	int			inside;
}				t_sphere;

typedef struct	s_plane
{
	t_point3	p;
}				t_plane;

typedef struct	s_square
{
	t_point3	c;
	double		side;
}				t_square;

typedef struct	s_cylinder
{
	t_point3	c;
	t_vector	nv;
	double		r;
	double		h;
	double		dist1;
	double		dist2;
}				t_cylinder;

typedef struct	s_triangle
{
	t_point3	p1;
	t_point3	p2;
	t_point3	p3;
}				t_triangle;

union			u_figures
{
	t_sphere	sp;
	t_plane		pl;
	t_square	sq;
	t_cylinder	cy;
	t_triangle	tr;
};
#endif

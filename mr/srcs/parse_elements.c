/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:19:39 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/18 18:43:46 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(t_figures **lst, char **str)
{
	t_figures	*elem;

	if (!(elem = malloc(sizeof(t_figures))))
		fatal_error("in malloc");
	elem->next = NULL;
	elem->flag = SP;
	skip_space(str);
	elem->fig.sp.c = parse_point3(str);
	elem->fig.sp.r = ft_stof(str) / 2;
	check_range(elem->fig.sp.r, 0, INFINITY, "sphere");
	elem->color = parse_color(str);
	ft_figure_add_back(lst, elem);
}

void	parse_plane(t_figures **lst, char **str)
{
	t_figures	*elem;

	if (!(elem = malloc(sizeof(t_figures))))
		fatal_error("in malloc");
	elem->next = NULL;
	elem->flag = PL;
	skip_space(str);
	elem->fig.pl.p = parse_point3(str);
	elem->normal = normalize(parse_point3(str));
	elem->color = parse_color(str);
	ft_figure_add_back(lst, elem);
}

void	parse_square(t_figures **lst, char **str)
{
	t_figures	*elem;

	if (!(elem = malloc(sizeof(t_figures))))
		fatal_error("in malloc");
	elem->next = NULL;
	elem->flag = SQ;
	skip_space(str);
	elem->fig.sq.c = parse_point3(str);
	elem->normal = normalize(parse_point3(str));
	elem->fig.sq.side = ft_stoi(str);
	check_range(elem->fig.sq.side, 0, INFINITY, "square");
	elem->color = parse_color(str);
	ft_figure_add_back(lst, elem);
}

void	parse_triangle(t_figures **lst, char **str)
{
	t_figures	*elem;

	if (!(elem = malloc(sizeof(t_figures))))
		fatal_error("in malloc");
	elem->next = NULL;
	elem->flag = TR;
	skip_space(str);
	elem->fig.tr.p1 = parse_point3(str);
	elem->fig.tr.p2 = parse_point3(str);
	elem->fig.tr.p3 = parse_point3(str);
	elem->normal = cross_product(
		vector_substract(elem->fig.tr.p3, elem->fig.tr.p1),
		vector_substract(elem->fig.tr.p2, elem->fig.tr.p1));
	elem->color = parse_color(str);
	ft_figure_add_back(lst, elem);
}

void	parse_cylinder(t_figures **lst, char **str)
{
	t_figures	*elem;

	if (!(elem = malloc(sizeof(t_figures))))
		fatal_error("in malloc");
	elem->next = NULL;
	elem->flag = CY;
	skip_space(str);
	elem->fig.cy.c = parse_point3(str);
	elem->fig.cy.nv = normalize(parse_point3(str));
	elem->fig.cy.r = ft_stof(str) / 2;
	check_range(elem->fig.cy.r, 0, INFINITY, "cylinder");
	elem->fig.cy.h = ft_stof(str);
	check_range(elem->fig.cy.h, 0, INFINITY, "cylinder");
	elem->color = parse_color(str);
	ft_figure_add_back(lst, elem);
}

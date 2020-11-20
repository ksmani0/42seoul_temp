/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:29:23 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/19 16:55:26 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		skip_comma(char **str)
{
	if (**str != ',')
		scene_error("formatted incorrectly");
	(*str)++;
}

int			parse_color(char **str)
{
	int r;
	int g;
	int b;

	r = 0;
	g = 0;
	b = 0;
	r |= ft_stoi(str);
	check_range(r, 0, 255, "colors must be in range [0, 255] ");
	r <<= 16;
	skip_comma(str);
	g |= ft_stoi(str);
	check_range(g, 0, 255, "colors must be in range [0, 255] ");
	g <<= 8;
	skip_comma(str);
	b |= ft_stoi(str);
	check_range(b, 0, 255, "colors must be in range [0, 255] ");
	return (r | g | b);
}

t_point3	parse_point3(char **str)
{
	t_point3 p;

	p.x = ft_stof(str);
	skip_comma(str);
	p.y = ft_stof(str);
	skip_comma(str);
	p.z = ft_stof(str);
	skip_space(str);
	return (p);
}

void		ft_figure_add_back(t_figures **lst, t_figures *new)
{
	t_figures	*cur;

	if (!(*lst))
		*lst = new;
	else
	{
		cur = *lst;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:56:09 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/10 19:21:25 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	color_x_light(int color, double l_rgb[3])
{
	unsigned int	mask;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	mask = 0xFF << 16;
	r = l_rgb[0] * ((color & mask) >> 16);
	mask >>= 8;
	g = l_rgb[1] * ((color & mask) >> 8);
	mask >>= 8;
	b = l_rgb[2] * (color & mask);
	r = r > 255 ? 255 : r;
	g = g > 255 ? 255 : g;
	b = b > 255 ? 255 : b;
	return ((r << 16) | (g << 8) | b);
}

int	color_difference(int color1, int color2)
{
	int r[2];
	int g[2];
	int b[2];
	int mask;
	int diff;

	mask = 0xFF;
	r[0] = (color1 & (mask << 16)) >> 16;
	g[0] = (color1 & (mask << 8)) >> 8;
	b[0] = color1 & mask;
	r[1] = (color2 & (mask << 16)) >> 16;
	g[1] = (color2 & (mask << 8)) >> 8;
	b[1] = color2 & mask;
	diff = pow(r[0] - r[1], 2) + pow(g[0] - g[1], 2) + pow(b[0] - b[1], 2);
	return (diff > 1000);
}

int	color_product(int color, double coef)
{
	unsigned int	mask;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	mask = 0xFF << 16;
	r = coef * ((color & mask) >> 16);
	mask >>= 8;
	g = coef * ((color & mask) >> 8);
	mask >>= 8;
	b = coef * (color & mask);
	r = r > 255 ? 255 : r;
	g = g > 255 ? 255 : g;
	b = b > 255 ? 255 : b;
	return ((r << 16) | (g << 8) | b);
}

int	color_add(int color1, int color2)
{
	int	mask;
	int r;
	int g;
	int b;

	mask = 0xff;
	r = ((color1 & (mask << 16)) + (color2 & (mask << 16))) & (mask << 16);
	g = ((color1 & (mask << 8)) + (color2 & (mask << 8))) & (mask << 8);
	b = ((color1 & (mask)) + (color2 & (mask))) & (mask);
	return (r | g | b);
}

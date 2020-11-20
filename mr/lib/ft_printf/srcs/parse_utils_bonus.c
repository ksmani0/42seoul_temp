/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:04:44 by suntlee           #+#    #+#             */
/*   Updated: 2020/09/14 19:29:30 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t	base_to_num(char c)
{
	if (c == 'o')
		return (8);
	else if (c == 'u')
		return (10);
	else if (c == 'd' || c == 'i')
		return (10);
	else if (c == 'p' || c == 'x' || c == 'X')
		return (16);
	return (0);
}

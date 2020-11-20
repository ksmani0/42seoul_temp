/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:06:44 by suntlee           #+#    #+#             */
/*   Updated: 2020/09/14 22:54:16 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_printf *p)
{
	p->printed = 1;
	p->padding = ft_max(0, p->min_length - p->printed);
	p->len += p->padding + p->printed;
	padding(p, 0);
	print_wchar(p, '%', p->printed, p->printed);
	padding(p, 1);
}

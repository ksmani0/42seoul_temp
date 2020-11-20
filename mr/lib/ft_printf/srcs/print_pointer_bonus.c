/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:06:29 by suntlee           #+#    #+#             */
/*   Updated: 2020/09/15 04:45:57 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(t_printf *p)
{
	void	*ptr;

	ptr = va_arg(p->args, void *);
	p->f &= ~FLAG_SHARP;
	p->min_length -= (p->f & FLAG_ZERO ? 2 : 0);
	p->padding = ft_max(0, p->min_length - 3 - p->printed);
	p->f |= FLAG_SHARP;
	p->f |= FLAG_PTR;
	p->printed = 0;
	itoa_base_printf((uintmax_t)ptr, 16, p, !ptr ? 1 : 0);
}

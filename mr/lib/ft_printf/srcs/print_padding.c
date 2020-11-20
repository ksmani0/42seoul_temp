/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:01:39 by suntlee           #+#    #+#             */
/*   Updated: 2020/09/13 15:07:33 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		padding(t_printf *p, int n)
{
	if (p->padding)
	{
		p->c = 32 | (p->f & FLAG_ZERO);
		if ((!n && !(p->f & FLAG_MINUS)) || (n && (p->f & FLAG_MINUS)))
			while (p->padding--)
				write(p->fd, &p->c, 1);
	}
}

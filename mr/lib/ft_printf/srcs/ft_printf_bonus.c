/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 15:46:51 by suntlee           #+#    #+#             */
/*   Updated: 2020/09/14 22:11:33 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_format(t_printf *p)
{
	while (*p->format && p->len > -1)
	{
		if (*p->format == '%')
		{
			++p->format;
			if (!*p->format)
				break ;
			else
				parse_options(p);
		}
		else
		{
			write(p->fd, p->format, 1);
			p->len++;
		}
		++p->format;
	}
}

int			ft_printf(const char *format, ...)
{
	t_printf	p;

	ft_bzero(&p, sizeof(p));
	p.fd = 1;
	p.format = (char *)format;
	va_start(p.args, format);
	print_format(&p);
	va_end(p.args);
	return (p.len);
}

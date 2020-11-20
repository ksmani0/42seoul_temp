/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 16:04:55 by suntlee           #+#    #+#             */
/*   Updated: 2020/09/15 14:15:25 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	itoa_base(uintmax_t tmp, char *s, t_printf *p)
{
	int	len;

	len = p->printed;
	while (len--)
	{
		s[len] = tmp % p->base + ((tmp % p->base < 10) ? '0' :
		'a' - 10 - ((p->f & FLAG_UPCASE) >> 1));
		tmp /= p->base;
	}
	p->len += p->padding + p->printed;
}

void		itoa_printf(intmax_t n, t_printf *p)
{
	char		s[100];
	intmax_t	tmp;

	p->printed = !n ? 1 : 0;
	tmp = n < 0 ? -n : n;
	while (tmp && ++p->printed)
		tmp /= 10;
	if ((n < 0 || p->f & FLAG_PLUS || p->f & FLAG_SPACE) &&
			!(p->f & FLAG_PRECISION) && p->f & FLAG_ZERO)
		--p->precision;
	p->printed = (p->f & FLAG_PRECISION && !p->precision && !n)
					? 0 : ft_max(p->printed, p->precision);
	if (n < 0 || p->f & FLAG_PLUS || p->f & FLAG_SPACE)
		++p->printed;
	p->padding = ft_max(0, p->min_length - p->printed);
	tmp = n < 0 ? -n : n;
	itoa_base(tmp, s, p);
	padding(p, 0);
	(p->f & FLAG_SPACE) ? s[0] = ' ' : 0;
	(n < 0) ? s[0] = '-' : 0;
	((p->f & FLAG_PLUS) && n >= 0) ? s[0] = '+' : 0;
	write(p->fd, s, p->printed);
	padding(p, 1);
}

void		itoa_base_printf(uintmax_t n, int b, t_printf *p, int len)
{
	uintmax_t	tmp;
	char		s[100];

	tmp = n;
	while (tmp && ++len)
		tmp /= b;
	p->printed = (p->f & FLAG_PRECISION && !p->precision && !n)
				? 0 : ft_max(len, p->precision);
	if (((p->f & FLAG_SHARP) && b == 16 && n) || p->f & FLAG_PTR)
	{
		if (!(p->f & FLAG_ZERO))
			p->printed += 2;
		else if ((p->f & FLAG_ZERO) && len + 2 > p->precision)
			p->printed = len + 2;
	}
	p->padding = ft_max(0, p->min_length - p->printed);
	itoa_base(n, s, p);
	padding(p, 0);
	if ((n || (p->f & FLAG_PTR)) && (p->f & FLAG_SHARP) && (b == 8 || b == 16))
	{
		s[0] = '0';
		s[1] = (p->f & FLAG_UPCASE) ? 'X' : 'x';
	}
	write(p->fd, s, p->printed);
	padding(p, 1);
}

void		print_nb(t_printf *p)
{
	intmax_t n;

	if (p->f & FLAG_L || p->f & FLAG_LL)
		n = (p->f & FLAG_L) ? (intmax_t)va_arg(p->args, long long) :
			(intmax_t)va_arg(p->args, long);
	else if (p->f & FLAG_S || p->f & FLAG_SS)
		n = (p->f & FLAG_SS) ? (intmax_t)((char)va_arg(p->args, int)) :
			(intmax_t)((short)va_arg(p->args, int));
	else
		n = (intmax_t)va_arg(p->args, int);
	if (p->f & FLAG_ZERO && !(p->f & FLAG_PRECISION))
		p->precision = p->min_length;
	itoa_printf(n, p);
}

void		print_nb_base(t_printf *p)
{
	uintmax_t n;

	if (p->f & FLAG_L || p->f & FLAG_LL)
		n = (p->f & FLAG_LL) ? (uintmax_t)va_arg(p->args, unsigned long long) :
			(uintmax_t)va_arg(p->args, unsigned long);
	else if (p->f & FLAG_S || p->f & FLAG_SS)
		n = (p->f & FLAG_SS) ? (uintmax_t)((unsigned char)va_arg(p->args, int))
			: (uintmax_t)((unsigned short)va_arg(p->args, int));
	else
		n = (uintmax_t)va_arg(p->args, unsigned int);
	if (p->f & FLAG_ZERO && !(p->f & FLAG_PRECISION))
		p->precision = p->min_length;
	itoa_base_printf(n, p->base, p, !n ? 1 : 0);
}

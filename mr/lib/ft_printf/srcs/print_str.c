/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 23:58:22 by suntlee           #+#    #+#             */
/*   Updated: 2020/09/15 15:35:04 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_wchar(t_printf *p, unsigned int n,
						unsigned int len, unsigned int bytes)
{
	char	tmp[4];

	if (bytes <= len && bytes <= (unsigned int)MB_CUR_MAX)
	{
		if (bytes == 1)
			tmp[0] = n;
		else
		{
			if (bytes == 2)
				tmp[0] = ((n & (0x1f << 6)) >> 6) | 0xC0;
			else
			{
				if (bytes == 3)
					tmp[0] = ((n >> 12) & 0xf) | 0xE0;
				else
				{
					tmp[0] = ((n >> 18) & 7) | 0xF0;
					tmp[1] = ((n >> 12) & 0x3f) | 0x80;
				}
				tmp[bytes - 2] = ((n >> 6) & 0x3f) | 0x80;
			}
			tmp[bytes - 1] = (n & 0x3f) | 0x80;
		}
		write(p->fd, tmp, bytes);
	}
}

static int	wstr_padding(int printed, wchar_t *s)
{
	int char_len;

	if (s == 0)
		return (0);
	while (printed > 0)
	{
		char_len = ft_wcharlen(*s++);
		if (printed < char_len)
			return (printed);
		printed -= char_len;
	}
	return (0);
}

static void	print_wstr(t_printf *p)
{
	wchar_t		*s;
	int			char_len;

	s = va_arg(p->args, wchar_t *);
	p->printed = s == 0 ? 6 : (int)ft_wstrlen(s);
	if (p->f & FLAG_PRECISION)
		p->printed = ft_min(p->printed, p->precision);
	p->printed -= wstr_padding(p->printed, s);
	p->padding = ft_max(0, p->min_length - p->printed);
	p->len += p->padding + p->printed;
	padding(p, 0);
	char_len = 0;
	while (s && (*s != L'\0') && (p->printed -= char_len) > 0)
	{
		if ((char_len = ft_wcharlen((wint_t)*s)) == 0)
		{
			p->len = -1;
			return ;
		}
		print_wchar(p, (unsigned int)*s, p->printed, char_len);
		s++;
	}
	if (s == 0)
		write(p->fd, "(null)", p->printed);
	padding(p, 1);
}

void		print_char(t_printf *p)
{
	wint_t c;

	c = va_arg(p->args, wint_t);
	if (p->f & FLAG_L || p->f & FLAG_LL)
		p->printed = ft_wcharlen(c);
	else
		p->printed = 1;
	p->padding = ft_max(0, p->min_length - p->printed);
	p->len += p->padding + p->printed;
	padding(p, 0);
	print_wchar(p, c, p->printed, p->printed);
	padding(p, 1);
}

void		print_str(t_printf *p)
{
	char	*s;

	if (p->f & FLAG_L || p->f & FLAG_LL)
	{
		print_wstr(p);
		return ;
	}
	s = va_arg(p->args, char *);
	p->printed = s == 0 ? 6 : (int)(ft_strlen((char *)s));
	if (p->f & FLAG_PRECISION)
		p->printed = ft_min(p->printed, p->precision);
	p->padding = ft_max(0, p->min_length - p->printed);
	p->len += p->padding + p->printed;
	padding(p, 0);
	if (s == 0)
		write(p->fd, "(null)", p->printed);
	else
		write(p->fd, s, p->printed);
	padding(p, 1);
}

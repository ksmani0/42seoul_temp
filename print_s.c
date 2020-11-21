/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:24:22 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 20:24:27 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_s(t_format *list, t_uchar *s, int len)
{
	int i;
	int size;

	i = 0;
	size = 0;
	if (list->flag[1] == 0 && list->width > len)
	{
		while (i++ < list->width - len)
			write(1, " ", 1);
		size += i;
	}
	size += write(1, s, len);
	i = 0;
	if (list->flag[1] == 1 && list->width > len)
	{
		while (i++ < list->width - len)
			write(1, " ", 1);
		size += i;
	}
	free(s);
	list->nums += size;
}

void	make_nul_s(t_uchar *nul_s)
{
	nul_s[0] = '(';
	nul_s[1] = 'n';
	nul_s[2] = 'u';
	nul_s[3] = 'l';
	nul_s[4] = 'l';
	nul_s[5] = ')';
	nul_s[6] = 0;
}

int		print_null(t_format *list)
{
	t_uchar *nul_s;
	int		len;

	if ((nul_s = (t_uchar*)malloc(sizeof(t_uchar) * 7)) == 0)
		return (-1);
	make_nul_s(nul_s);
	len = 6;
	if (list->flag[6] == 1 && list->prec < len)
		len = list->prec < len ? list->prec : len;
	output_s(list, nul_s, len);
	return (1);
}

int		print_s(t_format *list)
{
	t_uchar	*s;
	int		len;

	if (list->flag[0] == 1 || list->flag[2] == 1
		|| list->flag[3] == 1 || list->flag[5] == 1)
		return (-1);
	if (list->len == 'l')
		return (print_ls(list));
	if ((s = (t_uchar*)va_arg(list->ap, char*)) == 0)
		return (print_null(list));
	len = ft_strlen(s);
	if (list->flag[6] == 1 && list->prec < len)
		len = list->prec;
	output_s(list, s, len);
	return (1);
}

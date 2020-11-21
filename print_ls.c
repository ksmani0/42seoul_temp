/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:04:00 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 18:45:28 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_lsw_size(t_format *list, wchar_t ls, t_uchar *new)
{
	int len;

	len = ls < 128 ? 1 : 0;
	len = len == 0 && ls < 2048 ? 2 : len;
	len = len == 0 && ls < 65536 ? 3 : len;
	len = len == 0 && ls < 2097152 ? 4 : len;
	if ((new = (t_uchar*)malloc(sizeof(t_uchar) * len)) == 0)
		return (-1);
	if (len == 1)
		new[0] = (t_uchar)ls;
	else if (len == 2)
		new[0] = (ls >> 6) + 192;
	else if (len == 3)
		new[0] = (ls >> 12) + 224;
	else if (len == 4)
	{
		new[0] = (ls >> 18) + 240;
		new[1] = ((ls >> 12) & 63) + 128;
	}
	if (len > 2)
		new[len - 2] = ((ls >> 6) & 63) + 128;
	if (len > 1)
		new[len - 1] = (ls & 63) + 192;
	list->size++;
	return (len);
}

int		input_ls_to_us(t_format *list, wchar_t ls, t_uchar *out)
{
	int		bytes;
	int		len;
	t_uchar new[5];
	t_uchar *temp;
	int		i;
	int		j;

	ft_bzero((void*)new, 5);
	if ((bytes = count_lsw_size(list, ls, new)) < 0)
		return (-1);
	len = (int)ft_ustrlen(out) + bytes;
	if ((temp = (t_uchar*)malloc(sizeof(t_uchar) * (len + 1))) == 0)
		return (-1);
	i = -1;
	while (out[++i] != 0)
		temp[i] = out[i];
	j = 0;
	while (j < bytes)
		temp[i++] = new[j++];
	free(out);
	out = temp;
	return (bytes);
}

int		count_out_num(t_format *list, wchar_t *ls, t_uchar *out, int *bytes)
{
	int temp;
	int size;
	int i;

	i = 0;
	size = (int)ft_wcharlen((const wchar_t *)ls);
	if (list->flag[6] == 1 && list->prec < size)
	{
		while (i < list->prec)
		{
			if (temp = input_ls_to_us(list, ls[i++], out) < 0)
				return (-1);
			*bytes += temp;
		}
	}
	else
	{
		while (ls[i] != 0)
		{
			if (temp = input_ls_to_us(list, ls[i++], out) < 0)
				return (-1);
			*bytes += temp;
		}
	}
	return (1);
}

void	output_ls(t_format *list, t_uchar *out, int bytes)
{
	int i;
	int size;

	size = list->size;
	i = 0;
	if (list->flag[1] == 0 && list->width > size)
	{
		while (i++ < list->width - size)
			write(1, " ", 1);
	}
	write(1, out, bytes);
	i = 0;
	if (list->flag[1] == 1 && list->width > size)
	{
		while (i++ < list->width - size)
			write(1, " ", 1);
	}
	free(out);
	list->nums += size;
}

int		print_ls(t_format *list)
{
	wchar_t	*ls;
	t_uchar	*out;
	int		bytes;

	out = 0;
	bytes = 0;
	if ((ls = va_arg(list->ap, wchar_t*)) == 0)
		return (print_null(list));
	if ((count_out_num(list, ls, out, &bytes)) < 0)
	{
		free(out);
		return (-1);
	}
	output_ls(list, out, bytes);
	return (1);
}

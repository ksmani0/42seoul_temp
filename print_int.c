/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/27 11:47:13 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count_num_len(long num, t_format *list)
{
	size_t	len;
	int		i;

	if (num == 0)
		return (1);
	len = 0;
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void	input_list_num(t_format *list, long num, size_t len)
{
	if (num == 0)
	{
		list->if_num[0] = '0';
		return ;
	}
	if (num < 0)
	{
		list->if_num[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		list->if_num[--len] = num % 10 + '0';
		num /= 10;
	}
}

void	output_num(char *out, t_format *list, size_t len)
{
	int i;

	i = 0;
	if (list->flag[0] == 1 && list->if_num[0] == '-')//-플래그
		out[i++] = '-';
	while (i + len < list->out_len && list->width > list->prec &&	
		list->flag[0] == 0)
		out[i++] = ' ';
	while (i + len < list->width && list->flag[0] == 1 && list->width > list->prec)//너비 크고 0
		out[i++] = '0';
	while (i + len < list->prec && list->width <= list->prec)//정밀도 더 큼
		out[i++] = '0';
	len = 0;
	while (i < list->out_len && list->if_num[len] != 0)
		out[i++] = list->if_num[len++];
	while (i < list->out_len)
		out[i++] = ' ';
	write(1, out, i);
	free(out);
	list->out_num += i;
}

int	print_s_int(t_format *list)
{
	int	num;
	size_t	len;
	char	*out;

	num = va_arg(list->ap, int);
	len = count_num_len((long)num, list);
	input_list_num(list, (long)num, len);
	list->out_len = list->width > list->prec ? list->width : list->prec;
	list->out_len = len > list->out_len ? len : list->out_len;
	if ((out = (char*)malloc(sizeof(char) * (list->out_len + 1))) == 0)
		return (-1);
	out[list->out_len] = 0;
	output_int(out, list, len);
	return (1);
}
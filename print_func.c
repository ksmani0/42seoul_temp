/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/19 13:04:19 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count_num_len(long num, long temp, t_format *list)
{
	size_t len;
	int i;

	if (num == 0)
		return (1);
	len = 0;
	if (num < 0)
	{
		temp *= -1;
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	i = (int)len;
	while (--i >= 0)
	{
		list->if_num[i] = temp % 10 + '0';
		temp /= 10;
	}
	list->if_num[0] = i == 0 ? '-' : list->if_num[0];
	return (len);
}

void	make_int(char *out, t_format *list, size_t len)
{
	int i;

	i = 0;
	if (list->flag[0] == 1 && list->if_num[0] == '-')
		out[i++] = '-';
	while (i + len < list->out_len && list->width > list->prec &&	
		list->flag[0] == 0)
		out[i++] = ' ';
	while (i + len < list->width && list->flag[0] == 1 && list->width > list->prec)//너비 크고 0
		out[i++] = '0';
	while (i + len < list->prec && list->width <= list->prec)//정밀도 더 큼
		out[i++] = '0';
	len = 0;
	while (i < list->out_len)
		out[i++] = list->if_num[len++];
	write(1, out, i);
	free(out);
}

void	print_s_int(va_list ap, t_format *list)
{
	int	num;
	size_t	len;
	char	*out;

	num = va_arg(ap, int);
	len = count_num_len((long)num, (long)num, list);/*수 저장해놓음*/
	list->if_num[0] = num == 0 ? '0' : list->if_num[0];
	list->out_len = list->width > list->prec ? list->width : list->prec;
	list->out_len = len > list->out_len ? len : list->out_len;
	if ((out = (char*)malloc(sizeof(char) * (list->out_len + 1))) == 0)
		return ;
	out[list->out_len] = 0;
	if (list->flag[0] == 1 && list->flag[1] == 1)/*-, 0*/
		list->flag[0] = 0;
	make_int(out, list, len);
}

void	print_s_uint(va_list ap, t_format *list)
{
	unsigned int	num;
	size_t		len;
	char		*out;

	num = va_arg(ap, unsigned int);
	len = count_num_len((long)num, (long)num, list);/*수 저장해놓음*/
	list->if_num[0] = num == 0 ? '0' : list->if_num[0];
	list->out_len = list->width > list->prec ? list->width : list->prec;
	list->out_len = len > list->out_len ? len : list->out_len;
	if ((out = (char*)malloc(sizeof(char) * (list->out_len + 1))) == 0)
		return ;
	out[list->out_len] = 0;
	if (list->flag[0] == 1 && list->flag[1] == 1)/*-, 0*/
		list->flag[0] = 0;
	make_int(out, list, len);
}

void	print_s_char(va_list ap, t_format *list)
{
	char	c;
	size_t	len;
	char	*out;

	c = va_arg(ap, int);////
	len = count_num_len((long)num, (long)num, list);/*수 저장해놓음*/
	list->if_num[0] = num == 0 ? '0' : list->if_num[0];
	list->out_len = list->width > list->prec ? list->width : list->prec;
	list->out_len = len > list->out_len ? len : list->out_len;
	if ((out = (char*)malloc(sizeof(char) * (list->out_len + 1))) == 0)
		return ;
	out[list->out_len] = 0;
	if (list->flag[0] == 1 && list->flag[1] == 1)/*-, 0*/
		list->flag[0] = 0;
	make_int(out, list, len);
}
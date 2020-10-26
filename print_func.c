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
	list->if_num[i] = 0;
	while (--i >= 0)
	{
		list->if_num[i] = temp % 10;
		temp /= 10;
	}
	return (len);
}

void	make_int(char *out, t_format *list, int value, int size)
{

	if ()
}

void	print_s_int(va_list ap, t_format *list)
{
	long	num;
	size_t	len;
	char	*out;

	num = va_arg(ap, int);
	len = count_num_len(num, num, list);
	list->output_len = list->width > list->precision ?
		list->width : list->precision;
	list->output_len = len > list->output_len ? len : list->output_len;
	if ((out = (char*)malloc(sizeof(char) * (longest + 1))) == 0)
		return ;
	if (list->flags[0] == 1 && list->flags[1] == 1)/*-, 0*/
		list->flags[0] = 0;
	make_int(out, list, value);
}

void	output_specific(va_list ap, t_format *list)
{
	if (list->specific == 'd' || list->specific == 'i')
		print_s_int(list);
	else if (list->specific == 'u')
		print_s_uint(list);
	else if (list->specific == 'c' || list->specific == 's')
		print_s_char(list);
	else if (list->specific == '%')
		print_s_percent(list);
	else if (list->specific == 'x' || list->specific == 'X')
		print_s_octal(list);
	else if (list->specific == 'e' || list->specific == 'f' || list->specific == 'g')
		print_s_float(list);
	else if (list->specific == 'p')
		print_s_point(list);
	else if (list->specific == 'n')
		print_s_number(list);
}
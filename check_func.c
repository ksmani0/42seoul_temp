/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/19 13:04:19 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width_prec(va_list ap, t_format *list)
{
	short	w_or_p;

	w_or_p = 0;
	if (*list->str == '*')/* *.*, *., .*, *d */
	{
		if (ist->flag[2] == 0)
			list->width = (short)va_arg(ap, int);
		else if (ist->flag[2] == 1)
			list->prec = (short)va_arg(ap, int);
		list->str++;
		return ;
	}
	while (*list->str >= '0' && *list->str <= '9')
		w_or_p = w_or_p * 10 + (*list->str++ - '0');
	if (list->flag[2] == 0 && w_or_p > 0)/*.*/
		list->width = w_or_p;
	else if (list->flag[2] == 1 && w_or_p > 0)
		list->prec = w_or_p;
	if (list->flag[0] == 1)/*-*/
		list->flag[1] = 0;
	if (list->flag[5] == 1)/*+*/
		list->flag[4] = 0;
}

void	check_length(t_format *list)
{
	if (*list->str == 'h' && *(list->str + 1) == 'h')
		list->len = 'H';
	else if (*list->str == 'h' && *(list->str + 1) != 'h')
		list->len = 'h';
	else if (*list->str == 'l' && *(list->str + 1) == 'l')
		list->len = 'l';
	else if (*list->str == 'l' && *(list->str + 1) != 'l')
		list->len = 'L';
	else
		return ;
	list->str = list->len == 'h' || list->len == 'l' ?
		list->str + 1 : list->str + 2;
}

int	check_specific(t_format *list)
{
	char c;

	c = *list->str;
	if ((c >= 'd' && c <= 'g') || c == '%')
		list->spec = c;
	else if (c == 'i' || c == 'n' || c == 'p' ||
		c == 's' || c == 'u' || c == 'x' || c == 'X')
		list->specifier = c;
	else
		return (-1);
	return (1);
}

void	initial_part(t_format **list)
{
	int i;

	i = 0;
	while (i < 6)
		(*list)->flag[i++] = 0;
	(*list)->spec = 0;
	i = 0;
	while (i < 12 && (*list)->if_num[i] != 0)
		(*list)->if_num[i++] = 0;
	(*list)->len = 0;
	(*list)->width = 0;
	(*list)->prec = 0;
	(*list)->out_len = 0;
}

void	output_specific(va_list ap, t_format *list)
{
	if (list->spec == 'd' || list->spec == 'i')
		print_s_int(ap, list);
	else if (list->spec == 'u')
		print_s_uint(ap, list);
	else if (list->spec == 'c' || list->spec == 's')
		print_s_char(ap, list);
	else if (list->spec == '%')
		print_s_percent(ap, list);
	else if (list->spec == 'x' || list->spec == 'X')
		print_s_octal(ap, list);
	else if (list->spec == 'e' || list->spec == 'f' || list->spec == 'g')
		print_s_float(ap, list);
	else if (list->spec == 'p')
		print_s_point(ap, list);
	else if (list->spec == 'n')
		print_s_number(ap, list);
}